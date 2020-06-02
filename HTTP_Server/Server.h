//
// Created by sohayla on 16/11/19.
//

#ifndef HTTP_SERVER_SERVER_H
#define HTTP_SERVER_SERVER_H
#include <netinet/in.h>
#include <cstdio>
#include <cstdlib>
#include <thread>
#include <mutex>
#include <string>
#include "Parser.h"
#include "Actions.h"
#include "Worker.h"

#define MAX_PENDING 5
#define MAX_LINE 15000

class Server {
/*
 * 1. Initialize server.
 * 2. Listen for connections.
 * 3. Start accepting.
 * 4. Handle threads.
 * 5. Handle timeouts
 * 6. Handle requests.
 * 7. Create Response.
 * */
private:
    void init_server(int port);

    ~Server();

    int num_of_clients;
    int s_socket_fd;
    std::string main_dir;
    std::vector<Worker*> clients;
    Actions * a;

public:
    Server(int port, std::string dir);
   void* checkClients(void* arg);
    void start_server();

};


#endif //HTTP_SERVER_SERVER_H
