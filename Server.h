//
// Created by liel and adi on 1/1/20.
//

#ifndef FLYSIMULATOR1_0_SERVER_H
#define FLYSIMULATOR1_0_SERVER_H

#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>
#include <thread>
#include <vector>
#include "Singleton.h"
using namespace std;

class Server {
    int port;
public :
    Server(int _port);
    int main();
};


#endif //FLYSIMULATOR1_0_SERVER_H
