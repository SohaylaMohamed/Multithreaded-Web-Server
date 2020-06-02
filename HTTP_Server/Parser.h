//
// Created by sohayla on 17/11/19.
//

#ifndef HTTP_SERVER_PARSER_H
#define HTTP_SERVER_PARSER_H

#include <string>
#include <vector>
#include "FileSystem.h"
#include "Request.h"

#define SERVER_NAME "test/1.0.1"

class Parser {
private:
    std::vector<std::string> tokenize(std::string s , std::string delimiter);
    std::string fileFormat(std::string uri);
    FileSystem* f_sys;


public:
    Parser(std::string dir, FileSystem* f_sys);
    std::vector<std::vector<std::string>> handleRequest(std::string request);
    std::string handleGET(std::string basic_string, std::string basicString);
    std::string handlePOST(std::string basic_string, std::string basicString, std::vector<std::string> vector);
    int getContentLen(std::vector<std::string> headers);

    std::vector<Request *> getRequests(std::string reqs);

    Request *getRequest(std::string req);

    int parseHeader(std::string token, Request *pRequest);
};


#endif //HTTP_SERVER_PARSER_H
