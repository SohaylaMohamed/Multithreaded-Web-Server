//
// Created by sohayla on 16/11/19.
//

#include <vector>
#include <algorithm>
#include <cstring>
#include "Server.h"

std::mutex mtx;
void spawn_worker(int client);


Server::Server(int port, std::string main_dir) {
    s_socket_fd = 0;
    this->main_dir = main_dir;
    init_server(port);
}

void Server::init_server(int port) {
    num_of_clients = 0;

    // Creating socket file descriptor for the server
    if ((s_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    int opt = 1;
    // Check if it is used and forcefully attaching socket to our desired address and port
    if (setsockopt(s_socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    int ret = bind(s_socket_fd, (struct sockaddr *)&address, sizeof(address));
    if (ret < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
}

void Server::start_server() {
    if (listen(s_socket_fd, MAX_PENDING) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    printf("Server is waiting for connections\n");
    int client_fd;

    while (1) {
        /* server main loop */
        struct sockaddr_in c_addr;
        socklen_t s_size;
        s_size = sizeof(c_addr);
        client_fd = accept(s_socket_fd, (struct sockaddr *) &c_addr, &s_size);
        if (client_fd == -1) {
            perror("accept error ");
            continue;
        }

        printf("Successfully Connected with client's fd = %d \n", client_fd);
        if (clients.size() == MAX_PENDING) {
            printf("Reached the max limit number of connections, So server can't handle that client connection\n");
            continue;
        }
        Worker *client = new Worker(client_fd, MAX_LINE, main_dir);
        client->start();
        clients.push_back(client);
    }

}

void *Server::checkClients(void *arg) {
    while (true){
        for (Worker* client: clients) {
            if(!client->is_connected()){
                clients.erase(std::remove(clients.begin(), clients.end(), client), clients.end());
            }
        }
    }
}

