//
// Created by sohayla on 19/11/19.
//

#include <pthread.h>
#include <cstring>
#include <iostream>
#include "Worker.h"
#include "Request.h"

Worker::Worker(int c_fd, int max_line, std::string main_dir) {
    this->c_fd = c_fd;
    finished = false;
    a = new Actions(max_line, main_dir);
    f = new FileSystem(main_dir);
    p = new Parser(main_dir, f);
}

pthread_t Worker::getThreadId() {
    return threadId;

}
void Worker::start() {
    pthread_create(&threadId, NULL, startHelper, (void* )this);
}

void* Worker::startHelper(void *client) {
     ((Worker*)client)->run1();
}

void Worker::run() {
    while(1){
        struct timeval time_int;
        time_int.tv_sec = 4;
        time_int.tv_usec = 0;
        fd_set rfds;
        FD_ZERO(&rfds);
        FD_SET(c_fd, &rfds);
        if(select(1, &rfds, NULL, NULL, &time_int) == -1){
            printf("No more requests from client with fd = %d within the last 5 seconds, So the server will close the client connection\n",c_fd);
            break;
        }
        std::string req = a->recieve_req(c_fd);

        if(req == "error"){
            printf("Invalid Request");
            break;
        } else {
            std::vector<std::vector<std::string>> request = p->handleRequest(req);
            std::vector<std::string> first_line = request[0];
            std::vector<std::string> headers = request[1];
            std::string resp;
            if(std::strcmp(first_line[0].c_str(), "GET") == 0){
                if(first_line.size() < 3) {
                    printf("Invalid GET command expected 3 found %d \n", first_line.size());
                    continue;
                }
                std::string uri = first_line[1];
                std::string http_version = first_line[2];
                resp =  p->handleGET(uri, http_version);
                a->send_response(c_fd, (char*) resp.c_str(), resp.length());
            } else if(std::strcmp(first_line[0].c_str(), "POST") == 0) {
                if(first_line.size() < 3) {
                    printf("Invalid POST command expected 3 found %d \n", first_line.size());
                    continue;
                }
                std::string uri = first_line[1];
                std::string http_version = first_line[2];
                resp = p->handlePOST(uri, http_version, headers);
                a->send_response(c_fd, (char*) resp.c_str(), resp.length());
                if(resp == "HTTP/1.0 200 OK\r\n") {
                    int contentLength = p->getContentLen(headers);
                    int headerLen = req.size();
                    char* dataBuffer = new char[contentLength+headerLen];
                    memset(dataBuffer, 0, contentLength+headerLen);
                    a->recieve_sized_req(c_fd, dataBuffer, contentLength+headerLen);

                    f->write(uri, dataBuffer+ headerLen, contentLength);
                    delete dataBuffer;
                }
            }
        }
    }
    finished = true;

}
bool Worker::is_connected() {
    return finished;
}

void Worker::closeHelper(void *client) {
    delete ((Worker*)client);
}

void Worker::run1() {
    pthread_cleanup_push(closeHelper, (void *)this);
    run();
    pthread_cleanup_pop(1);
}

void Worker::run_pipeline() {
    std::string reqs;
    while(1){
        while (true) {

            struct timeval time_int;
            time_int.tv_sec = 4;
            time_int.tv_usec = 0;
            fd_set rfds;
            FD_ZERO(&rfds);
            FD_SET(c_fd, &rfds);
            if(select(1, &rfds, NULL, NULL, &time_int) == -1){
                printf("No more requests from client with fd = %d within the last 5 seconds, So the server will close the client connection\n",c_fd);
                break;
            }

            std::string req = a->recieve_req(c_fd);

            if (req == "error") {
                std::cout << "Invalid request" << std::endl;
                break;
            }
            reqs += req;
        }

        std::vector<Request*> requests = p->getRequests(reqs);
        for (Request *request : requests) {
            if (request->getMethod() == "GET") {
                std::string resp;
                resp =  p->handleGET(request->geturi(), request->getversion());
                a->send_response(c_fd, (char*) resp.c_str(), resp.length());
            } else if (request->getMethod() == "POST") {
                std::string resp;
                resp = p->handlePOST(request->geturi(), request->getversion(), request->getHeaders());
                a->send_response(c_fd, (char*) resp.c_str(), resp.length());
                if(resp == "HTTP/1.0 200 OK\r\n") {
                    int contentLength = p->getContentLen(request->getHeaders());
                    int headerLen = request->getreq().size();
                    char* dataBuffer = new char[contentLength+headerLen];
                    memset(dataBuffer, 0, contentLength+headerLen);
                    a->recieve_sized_req(c_fd, dataBuffer, contentLength+headerLen);

                    f->write(request->geturi(), dataBuffer+ headerLen, contentLength);
                    delete dataBuffer;
                }
            }
            delete request;
        }
        reqs.clear();



    }
    finished = true;
}

