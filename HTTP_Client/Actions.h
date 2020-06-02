//
// Created by sohayla on 20/11/19.
//

#ifndef HTTP_CLIENT_ACTIONS_H
#define HTTP_CLIENT_ACTIONS_H


#include <vector>
#include "Parser.h"
#include "Request.h"
#include <fstream>

class Actions {
private:
    Parser * p;
    FileSystem* f;
    int sock_fd;

public:
    Actions(std::string main_dir);
    std::vector<std::vector<Request *>> readInput(std::ifstream &file);
    int sendRequestsPipelined(std::vector<Request*> reqs, int fd);
    int sendRequestsUnpipelined(std::vector<Request*> reqs, int fd);
    int sendGet(Request* request, int s_fd);
    int sendPost(Request* request, int s_fd);

    std::string createGetHeader(Request *pRequest);

    std::string recieveResponse(int fd);

    int recieveSizedResponse(int fd, char * buffer, int len);

    std::string createPostRequest(Request *request);

    int sendGETpipelined(std::vector<Request *> vector, int fd);
};


#endif //HTTP_CLIENT_ACTIONS_H
