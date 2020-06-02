//
// Created by sohayla on 20/11/19.
//

#include "Request.h"
Request::Request(std::string method, std::string uri, std::string version, int port, std::string host_name) {
    this->port = port;
    this->version = version;
    this->uri = uri;
    this->method = method;
    this->hostName = host_name;
}
int Request::getPort() {
    return this->port;
}
std::string Request::getversion() {
    return this->version;
}
std::string &Request::geturi() {
    return this->uri;
}

std::string Request::getMethod() {
    return this->method;
}
std::string Request::getHostName() {
    return this->hostName;
}