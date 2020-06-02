//
// Created by sohayla on 21/11/19.
//

#ifndef HTTP_SERVER_REQUEST_H
#define HTTP_SERVER_REQUEST_H


#include <string>
#include <vector>

class Request {
private:
    std::string method;
    std::string uri;
    std::string version;
    std::string body;
    std::vector<std::string> headers;
    std::string req;

public:
    Request(std::string method, std::string uri, std::string version, std::vector<std::string> headers);
    std::string getMethod();
    std::string& geturi();
    std::string getversion();
    std::string getBody();
    std::string getreq();

    void setBody(std::string body);
    void setreq(std::string req);
    std::vector<std::string> getHeaders();


};


#endif //HTTP_SERVER_REQUEST_H
