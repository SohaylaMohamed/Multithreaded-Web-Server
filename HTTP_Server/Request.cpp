//
// Created by sohayla on 21/11/19.
//

#include "Request.h"
Request::Request(std::string method, std::string uri, std::string version, std::vector<std::string> headers) {
    this->version = version;
    this->uri = uri;
    this->method = method;
    this->headers = headers;

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

std::string Request::getBody() {

    return this->body;
}

void Request::setBody(std::string body) {
    this->body = body;
}

std::vector<std::string> Request::getHeaders() {
    return this->headers;
}

std::string Request::getreq() {
    return req;
}

void Request::setreq(std::string req) {
    this->req = req;

}
