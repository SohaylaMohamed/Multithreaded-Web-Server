//
// Created by sohayla on 17/11/19.
//

#include <cstring>
#include <sstream>
#include <iostream>
#include "Parser.h"
#include "Request.h"

Parser::Parser(std::string main_dir, FileSystem* f_sys) {
    this->f_sys = f_sys;
}
std::vector<std::vector<std::string>> Parser::handleRequest(std::string request) {
    std::vector<std::string> tokens;
    tokens = tokenize(request, "\r\n");
    std::vector<std::string> headers;
    for (std::vector<std::string>::iterator it = tokens.begin() + 1; it != tokens.end();
         it++) {
        headers.push_back(*it);
    }

    std::vector<std::string> first_line = tokenize(tokens[0], " ");
    std::vector<std::vector<std::string>> ret;
    ret.push_back(first_line);
    ret.push_back(headers);

    return ret;
}


std::vector<std::string> Parser::tokenize(std::string s, std::string delimiter) {
    std::vector<std::string> tokens;
    size_t pos = 0;
    std::string token;

    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        tokens.push_back(token);
        s.erase(0, pos + delimiter.length());
    }

    tokens.push_back(s);
    return tokens;
}

std::string Parser::handleGET(std::string file_uri, std::string version) {
    std::stringstream httpResponseBuf;

    bool fileExists = f_sys->file_exists(file_uri);
    httpResponseBuf << version << " " << (fileExists ? "200 OK" : "404 Not Found") << "\r\n";
    int fileSize = f_sys->file_size(file_uri);
    time_t now;
    time(&now);
    char* cDate = ctime(&now);
    cDate[strlen(cDate) - 1] = '\0';
    httpResponseBuf << "Date: " << std::string(cDate) << "\r\n";
    httpResponseBuf << "Server: " << SERVER_NAME << "\r\n";
    time_t last_mod = f_sys->last_modified(file_uri);
    char* last_date = ctime(&last_mod);
    last_date[strlen(last_date) - 1] = '\0';
    httpResponseBuf << "Last-Modified: " << std::string(cDate) << "\r\n";
    httpResponseBuf << "Content-Length: " << fileSize << "\r\n";
    httpResponseBuf << "Content-Type: " << fileFormat(file_uri) << "\r\n";
    httpResponseBuf << "\r\n";

    if (fileExists) {
        char* dataBytes = new char[fileSize]();
        memset(dataBytes, '\0', fileSize);
        f_sys->read(file_uri, dataBytes, fileSize);
        std::cout << dataBytes << std::endl;
        httpResponseBuf.write(dataBytes, fileSize);
        delete dataBytes;
    }

    return httpResponseBuf.str();
}


std::string Parser::handlePOST(std::string file_uri, std::string version, std::vector<std::string> headers) {
    int contentLength = getContentLen(headers);

    if (contentLength <= 0) {
        std::string badResonse = "HTTP/1.0 400 Bad Request\r\n";
        return badResonse;
    }

    char* dataBuffer = new char[contentLength];
    memset(dataBuffer, 0, contentLength);

    return "HTTP/1.0 200 OK\r\n";

}
int Parser::getContentLen(std::vector<std::string> headers){
    int contentLength = 0;
    for (std::vector<std::string>::iterator it = headers.begin(); it != headers.end(); it++) {
        std::vector<std::string> splitted = tokenize(*it, ": ");
        std::cout << *it << std::endl;
        if (splitted[0] == "Content-Length") {
            contentLength = atoi(splitted[1].c_str());
        }
        splitted.clear();
    }
    return contentLength;
}
std::string Parser::fileFormat(std::string uri) {
    std::string ff;
    if (strcasecmp(uri.substr(uri.find_last_of(".") + 1).c_str(), "html")
        == 0) {
        ff = "text/html";
    } else if (strcasecmp(uri.substr(uri.find_last_of(".") + 1).c_str(), "txt")
               == 0) {
        ff = "text/txt";
    } else if (strcasecmp(uri.substr(uri.find_last_of(".") + 1).c_str(), "css")
               == 0) {
        ff = "text/css";
    } else if (strcasecmp(uri.substr(uri.find_last_of(".") + 1).c_str(), "js")
               == 0) {
        ff = "text/javascript";
    }else if (strcasecmp(uri.substr(uri.find_last_of(".") + 1).c_str(), "png")
              == 0) {
        ff = "image/png";
    } else if (strcasecmp(uri.substr(uri.find_last_of(".") + 1).c_str(), "jpg")
               == 0) {
        ff = "image/jpg";
    } else if (strcasecmp(uri.substr(uri.find_last_of(".") + 1).c_str(), "jpeg")
               == 0) {
        ff = "image/jpg";
    } else if (strcasecmp(uri.substr(uri.find_last_of(".") + 1).c_str(), "gif")
               == 0) {
        ff = "image/gif";
    } else {
        ff = "none/none";
    }
    return ff;
}

std::vector<Request *> Parser::getRequests(std::string data) {

    std::vector<std::string> tokens = tokenize(data , "\r\n");
    std::vector<Request*> reqs;

    int i = 0;
    while(i < tokens.size() - 1){
        std::string s;
        while (tokens[i] != ""){
            s += (tokens[i] + "\r\n");
            i++;
        }
        Request *currRequest = getRequest(s);
        reqs.push_back(currRequest);
        i++;
    }
    // remove bad requests
    for(auto it = reqs.begin() ; it!= reqs.end();){
        if( *it == NULL){
            it = reqs.erase(it);
        }else{
            it++;
        }
    }
    return reqs;
}

Request* Parser::getRequest(std::string req) {
    Request* request;
    std::vector<std::string> tokens = tokenize(req , "\r\n");

    std::vector<std::string> s = tokenize(tokens[0] , " ") ;

    if(s.size() != 3){
        perror("First line in request has wrong format\n Required :\n Method File_name Host_name\n") ;
        return request;
    }

    std::vector<std::string> headers;
    int i = 1;
    for(; i < tokens.size() && tokens[i] != "" ; i++) {
        headers.push_back(tokens[i]);
    }
    request = new Request(s[0], s[1], s[2], headers);

    std::string requestBody;
    while (i + 1 < tokens.size()){
        i++;
        requestBody += tokens[i];
        if(i + 1 < tokens.size() ){
            requestBody += "\r\n";
        }
    }
    request->setBody(requestBody);
    request->setreq(req);
    return request;
}

