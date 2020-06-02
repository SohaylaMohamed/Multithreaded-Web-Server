//
// Created by sohayla on 20/11/19.
//

#ifndef HTTP_CLIENT_PARSER_H
#define HTTP_CLIENT_PARSER_H


#include <vector>
#include <string>
#include "FileSystem.h"

class Parser {
private:
    std::vector<std::string> tokenize(std::string s , std::string delimiter);
    FileSystem* f_sys;
    std::string dir;


public:
    Parser(std::string dir, FileSystem* f_sys);
    Request* createRequest(std::string line);
    std::vector<std::string> handleGetResponse(std::string resp);
    std::string handlePostResponse(std::string basic_string);

   // std::string getResponseBody(std::string basic_string);

    std::string getStatus(std::basic_string<char> &basic_string);
};


#endif //HTTP_CLIENT_PARSER_H
