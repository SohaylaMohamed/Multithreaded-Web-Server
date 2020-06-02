//
// Created by sohayla on 19/11/19.
//

#ifndef HTTP_SERVER_ACTIONS_H
#define HTTP_SERVER_ACTIONS_H


#include <string>
#include "Parser.h"

class Actions {
private:
    int MAX_LINE;
    Parser *p;
public:
    Actions(int max_line, std::string main_dir);
    std::string recieve_req(int fd);
    int recieve_sized_req(int fd, char * buffer, int len);
    int send_response(int client_fd, char* message, int size);

};


#endif //HTTP_SERVER_ACTIONS_H
