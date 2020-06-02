//
// Created by sohayla on 20/11/19.
//

#include <err.h>
#include <sstream>
#include <iostream>
#include "Parser.h"

Parser::Parser(std::string dir, FileSystem *f_sys) {
    this->dir = dir;
    this->f_sys = f_sys;
}

Request *Parser::createRequest(std::string line) {
    Request* req;
    std::vector<std::string> tokens = tokenize(line, " ");
    int port;
    if (tokens.size() == 4) {
        port = (u_short) (stoi(tokens[3]));
    } else {
        port = 80;
    }
    if(tokens.size() > 2 ) {
        req = new Request(tokens[0], tokens[1], "HTTP/1.1", port, tokens[2]);
    }
    return req;
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



/*std::string Parser::getResponseBody(std::string resp) {
    std::vector<std::string> tokens = tokenize(resp , "\r\n");
    int i = 1;
    while (i < tokens.size() && tokens[i] != "") {
       i++;
    }
    std::string requestBody;
    while (i + 1 < tokens.size()){
        i++;
        requestBody += tokens[i];
        if(i + 1 < tokens.size() ){
            requestBody += "\r\n";
        }
    }
    return requestBody;
}*/

std::vector<std::string> Parser::handleGetResponse(std::string resp) {
    std::vector<std::string> ret;
    std::vector<std::string> tokens = tokenize(resp , "\r\n");
    std::stringstream ss;


    std::string status = getStatus(tokens[0]);
    if(status == "error" )
        return ret;
    ret.push_back(status);
    std::string contentLen ;

    ss << tokens[0] << "\r\n";

    int i = 1;
    for(; i < tokens.size() && tokens[i] != "" ; i++) {
        std::string tmp = tokens[i];
        size_t pos = 0;
        if ((pos = tmp.find(": ")) != std::string::npos) {
            std::string key = tmp.substr(0, pos);
            if(key == "Content-Length") {
                tmp.erase(0, pos + 2);
                contentLen = tmp;
            }
        }
        ss << tokens[i] << "\r\n";
    }
    std::cout << contentLen << std::endl;

    int size = ss.str().size();
    ss.clear();
    ss.str(std::string());
    ss << size;
    std::string header_len =ss.str();
    std::cout << header_len << std::endl;
    ret.push_back(contentLen);
    ret.push_back(header_len);

    return ret;
}

std::string Parser::getStatus(std::basic_string<char> &basic_string) {
    std::vector<std::string> vstrings = tokenize(basic_string , " ") ;
    if(vstrings.size() < 3){
        return "error";
    }
    return vstrings[1];
}

std::string Parser::handlePostResponse(std::string resp) {
    std::vector<std::string> ret;
    std::vector<std::string> tokens = tokenize(resp , "\r\n");
    std::stringstream ss;


    std::string status = getStatus(tokens[0]);

    return status;
}
