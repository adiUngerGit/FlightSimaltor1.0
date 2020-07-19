//
// Created by liel and adi on 1/1/20.
//

#include "Server.h"
void startTheServer(int socketfd, int client_socket) {
    Singleton *singleton = singleton->getInstance();
    vector<string> bufferVector = {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0",
                                   "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0",
                                   "0", "0"};
    if (singleton->endProgram) {
        close(socketfd);
    }
    while (!singleton->endProgram) {
        //change all var's acoording the simolator
        for (auto e : singleton->infoFromSimulator) {
            try {
                    singleton->infoFromSimulator.find(e.first)->second.setValue(
                            stod(singleton->infoFromSim[singleton->simToNum[e.second.getSim()]]));
            } catch (...) {
                cout << "Eror stod" << endl;
            }
        }
        vector<string> info;
        char buffer[1024] = {0};
        //getting info from the client into the server if the reading dosent successed will return -1.
        int valread = read(client_socket, buffer, 1024);
        int i, counter = 0;
        // from \n to \n in buffer
        char newBuffer[1024] = {0};
        for (i = 0; i <= 1024; i++) {
            newBuffer[i] = buffer[i];
            counter++;
            if (buffer[i] == '\n') {
                break;
            }
        }
        //if we get -1 from the valread it will close the server.
        if (valread <= 0) {
            close(socketfd);
        }
        string s = "";
        counter = 0;
        //parse the buffer by ',' parse it to 36 values.
        for (i = 0; i < 1024; i++) {
            if (newBuffer[i] == ',' || newBuffer[i] == '\n') {
                bufferVector[counter] = s;
                s = "";
                counter++;
            } else {
                s = s + buffer[i];
            }
        }
        //setting the vector into the vector in the singleton.
        singleton->set(bufferVector);
    }
}
Server::Server(int _port) {
    this->port = _port;
}
int Server::main() {
    //create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket" << std::endl;
        return -1;
    }

    //bind socket to IP address
    // we first need to create the sockaddr obj.
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(this->port);
    //we need to convert our number
    // to a number that the network understands.
    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr << "Could not bind the socket to an IP" << std::endl;
        return -2;
    }

    //making socket listen to the port
    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr << "Error during listening command" << std::endl;
        return -3;
    } else {
        std::cout << "Server is now listening ..." << std::endl;
    }

    std::cout << "server : printing answer" << std::endl;    // accepting a client
    int client_socket = accept(socketfd, (struct sockaddr *) &address,
                               (socklen_t *) &address);
    if (client_socket == -1) {
        std::cerr << "Error accepting client" << std::endl;
    }
    thread thread(startTheServer, socketfd, client_socket);
    thread.detach();
    return 0;
}
