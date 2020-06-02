//
// Created by sohayla on 20/11/19.
//

#ifndef HTTP_CLIENT_REQUEST_H
#define HTTP_CLIENT_REQUEST_H


#include <string>

class Request {
private:
    std::string method;
    std::string uri;
    std::string version;
    std::string hostName;
    int port;
public:
    Request(std::string method, std::string uri, std::string version, int port, std::string host_name);
    int getPort();
    std::string getMethod();
    std::string& geturi();
    std::string getversion();
    std::string getHostName();

};


#endif //HTTP_CLIENT_REQUEST_H
