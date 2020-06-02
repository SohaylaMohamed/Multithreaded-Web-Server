//
// Created by sohayla on 20/11/19.
//

#ifndef HTTP_CLIENT_REQUEST_H
#define HTTP_CLIENT_REQUEST_H


#include <string>

class Structs {
    struct Request {
        std::string method;
        std::string uri;
        std::string version;
        char * data;
    };

    struct Response {
        std::string method;
        std::string type;
        char * data;
        int fd;
    };

};


#endif //HTTP_CLIENT_REQUEST_H
