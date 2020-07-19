//
// Created by liel and adi on 1/1/20.
//
#ifndef FLYSIMULATOR1_0_CLIENT_H
#define FLYSIMULATOR1_0_CLIENT_H
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <thread>
#include "ex1.h"
//#include "Singleton.h"
using namespace std;
/*
 * Client : connect to simolator
 */
class Client {
    int _port;
    string _ip;
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
public:
    Client(string ip, int port);
    int main();
    int connectToServer(Variable v);
};


#endif //FLYSIMULATOR1_0_CLIENT_H
