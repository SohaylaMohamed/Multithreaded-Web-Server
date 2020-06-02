//
// Created by sohayla on 20/11/19.
//

#include <cstring>
#include <zconf.h>
#include <iostream>
#include <sys/socket.h>
#include <poll.h>
#include <sstream>
#include "Actions.h"
#define MAX_LINE 15000

Actions::Actions(std::string main_dir) {
    f = new FileSystem(main_dir);
    p = new Parser(main_dir, f);
}

std::vector<std::vector<Request *>> Actions::readInput(std::ifstream &file) {
    std::string host = "";
    std::vector<std::vector<Request *>> ret;
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            Request* req = p->createRequest(line);
            std::string tmp_host = req->getHostName()+ "," + std::to_string(req->getPort());
            if(host != tmp_host) {
                std::vector<Request *> vec;
                ret.push_back(vec);
                host = tmp_host;
            }
            ret[ret.size() - 1].push_back(req);
        }
        file.close();
        return ret;
    }
    return ret;
}


int Actions::sendGet(Request *request, int s_fd) {
    std::string req_header = createGetHeader(request);
    std::cout << s_fd<<std::endl;
    int n = send(s_fd, req_header.c_str(), strlen(req_header.c_str()), 0);
    if (n <= 0) {
        std::cout << "error getting data from server" << std::endl;
        return -1;
    }
    struct timeval time_int;
    time_int.tv_sec = 5;
    time_int.tv_usec = 0;
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(s_fd, &rfds);
    if(select(1, &rfds, NULL, NULL, &time_int) == -1){
        printf("No respone from server within the last 100 seconds, So the client will close the  connection\n");
        return -1;
    }
    std::string resp = recieveResponse(s_fd);
    if(resp == "error") {
        printf("Invalid Response\n");
        return -1;
    }
    std::vector<std::string> temp_resp = p->handleGetResponse(resp);
    if (temp_resp.empty()) {
        printf("invalid response\n");
        return -1;
    }
    int len;
    std::string resp_s;
    if (temp_resp[0] == "200") // file found
    {
        const char *data = 0;
        //header size at 2
        //content len at 1
        len = stoi(temp_resp[1]) + stoi(temp_resp[2]);
        char* buffer =  new char [len]();
        memset(buffer, '\0', len);

        int i = recieveSizedResponse(s_fd, buffer, len);
        char* bod = buffer+stoi(temp_resp[2])+2;
       // bod[strlen(bod)-1] = '\0';
       // bod[strlen(bod)-2] = '\0';
        //resp_s = std::string(buffer);
        //std::string body = p->getResponseBody(resp_s);
        //data = body.c_str();
       f->write(request->geturi(), (char *) bod, stoi(temp_resp[1]));

        std::cout << data << std::endl;

    } else if(temp_resp[0] == "404"){
        len = stoi(temp_resp[2]);
        char* buffer =  new char [len]();
        memset(buffer, '\0', len);

        int i = recieveSizedResponse(s_fd, buffer, len);
        resp_s = std::string(buffer);


        std::cout << resp_s << std::endl;
    }

    return 0;
}

int Actions::sendPost(Request *request, int s_fd) {
    std::string r = createPostRequest(request);

    int n = send(s_fd, r.c_str(), strlen(r.c_str()), 0);

    if(n < 0){
        return -1;
    }


    struct timeval time_int;
    time_int.tv_sec = 5;
    time_int.tv_usec = 0;
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(s_fd, &rfds);
    if(select(1, &rfds, NULL, NULL, &time_int) == -1){
        printf("No respone from server within the last 100 seconds, So the client will close the  connection\n");
        return -1;
    }

    // receive reponse
    std::string resp = recieveResponse(s_fd);

    if(resp == "error"){
        return -1;
    }

    std::string status = p->handlePostResponse(resp);
    int sz = f->file_size(request->geturi());
    std::vector<char> buffer(sz, 0);
    f->read(request->geturi(), &buffer[0], sz);
    if(buffer.empty()){
        return -1;
    }

    if(status == "200") // ready to receive file
    {
        char* ptr = buffer.data();
        int len = sz;
        while (len  > 0){
            int status = write(s_fd, ptr, len);
             if(status == -1){
                return status;
             }
            if(status == 0){
                break;
            }
            ptr+=status;
            len-=status;
        }
        return 0;
    }
    return -1;
}

std::string Actions::createGetHeader(Request *request) {
    std::string header;
    header =  "GET " + request->geturi() + " HTTP/1.1\r\nHost: " + request->getHostName() + "\r\n"+"\r\n";
    return header;
}

std::string Actions::recieveResponse(int fd) {
    char *buffer = new char [MAX_LINE]();
    memset(buffer, '\0', MAX_LINE);
    int len_recv = recv(fd, buffer, MAX_LINE, 0);
    printf(std::string(buffer).c_str());

    if (len_recv == 0) {
        printf("Client disconnected\n");
    } else if (len_recv == -1) {
        perror("reading from socket failed\n");
    } else {
        std::string req(buffer);
        return  req;
    }
    return "error";
}

int Actions::recieveSizedResponse(int fd, char * buff, int sz) {
    int len = sz;
    while(sz > 0) {
        std::vector<char> buffer(sz, 0);
        int valread = recv(fd, &buffer[0] , sz, 0)  ;
        if(valread < 0){
            return -1;
        }
        if(valread == 0){
            break;
        }
        sz -= valread;
        std::string r = std::string(buffer.begin(), buffer.begin() + ((valread < len) ? valread : len));
        std::strcat(buff, r.c_str());
    }
    return len - sz ;
}

std::string Actions::createPostRequest(Request* request) {
    std::string header;
    int len = f->file_size(request->geturi());
    std::stringstream ss;
    ss << len;
    std::string header_len =ss.str();
    header =  "POST " + request->geturi() + " HTTP/1.1\r\nHost: " + request->getHostName() + "\r\nContent-Type: "
            +f->contentType(request->geturi()) +"\r\nContent-Length: " + header_len + "\r\n\r\n";
    return header;
}

int Actions::sendRequestsUnpipelined(std::vector<Request *> reqs, int fd) {
    for (Request* r :reqs) {
        if(r->getMethod() == "GET") {
            sendGet(r, fd);
        } else {
            sendPost(r, fd);
        }
    }
    return 0;
}


int Actions::sendRequestsPipelined(std::vector<Request *> reqs, int fd) {
    std::vector<Request*> tmp_vec;
    int status;
    for(Request* r : reqs) {
        // parse user command
        if(r->getMethod() == "GET"){
            tmp_vec.push_back(r);
        }else{

            if(!tmp_vec.empty()) {
                status = sendGETpipelined(tmp_vec, fd);
            }

            status = sendPost(r, fd);

        }
    }
    if(!tmp_vec.empty()){
        status = sendGETpipelined(tmp_vec, fd);
    }

    return 0;
}

int Actions::sendGETpipelined(std::vector<Request *> reqs, int s_fd) {
    for(Request* r : reqs) {
        std::string h = createGetHeader(r);
        int n = send(s_fd, h.c_str(), strlen(h.c_str()), 0);
        if (n <= 0) {
            std::cout << "error getting data from server" << std::endl;
            return -1;
        }
    }

    //start recieveing responses
    struct timeval time_int;
    time_int.tv_sec = 5;
    time_int.tv_usec = 0;
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(s_fd, &rfds);

    int file_counter = 0 ;
    while(file_counter < reqs.size()) {
        if(select(1, &rfds, NULL, NULL, &time_int) == -1){
            printf("No respone from server within the last 100 seconds, So the client will close the  connection\n");
            return -1;
        }
        std::string resp = recieveResponse(s_fd);
        if(resp == "error") {
            printf("Invalid Response\n");
            return -1;
        }
        std::vector<std::string> temp_resp = p->handleGetResponse(resp);
        if (temp_resp.empty()) {
            printf("invalid response\n");
            return -1;
        }
        int len;
        std::string resp_s;
        if (temp_resp[0] == "200") // file found
        {
            const char *data = 0;
            //header size at 2
            //content len at 1
            len = stoi(temp_resp[1]) + stoi(temp_resp[2]);
            char* buffer =  new char [len]();
            memset(buffer, '\0', len);

            int i = recieveSizedResponse(s_fd, buffer, len);
            char* bod = buffer+stoi(temp_resp[2])+2;
            // bod[strlen(bod)-1] = '\0';
            // bod[strlen(bod)-2] = '\0';
            //resp_s = std::string(buffer);
            //std::string body = p->getResponseBody(resp_s);
            //data = body.c_str();
            f->write(reqs[file_counter]->geturi(), (char *) bod, stoi(temp_resp[1]));

            std::cout << data << std::endl;

        } else if(temp_resp[0] == "404"){
            len = stoi(temp_resp[2]);
            char* buffer =  new char [len]();
            memset(buffer, '\0', len);

            int i = recieveSizedResponse(s_fd, buffer, len);
            resp_s = std::string(buffer);


            std::cout << resp_s << std::endl;
        }
    }

    return 0;
}






