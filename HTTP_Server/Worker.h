//
// Created by sohayla on 19/11/19.
//

#ifndef HTTP_SERVER_WORKER_H
#define HTTP_SERVER_WORKER_H


#include <zconf.h>
#include "Actions.h"
#define MAX_LINE 15000


class Worker {
private:
    int worker_id;
    int c_fd;
    bool finished;
    pthread_t threadId;
    Actions* a;
    Parser * p;
    FileSystem * f;

public:
    bool is_connected();
    Worker(int c_fd, int max_line, std::string main_dir);
    void start();
    pthread_t getThreadId();
    void run();
    void run_pipeline();
    void run1();
    static void * startHelper(void * runner);
    static void closeHelper(void* client);

};


#endif //HTTP_SERVER_WORKER_H
