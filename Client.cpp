//
// Created by liel and adi on 1/1/20.
//

#include <sstream>
#include "Singleton.h"
#include "Client.h"
/**
 * connectToServer : call from singelton.
 * change the simolator
 * @param v : variable that include sim and double.
 */
int Client::connectToServer(Variable v) {
    Singleton *singleton = singleton->getInstance();
    if(singleton->endProgram) {
        close(this->client_socket);
    }
    double value = v.getValue();
    string sim = v.getSim();
    stringstream ss;
    ss << "set " << sim << " " << value << "\r\n";
    string str = ss.str();
    char const *hello = str.c_str();
    // send hello to simolator
    int is_sent = send(client_socket, hello, strlen(hello), 0);
    if (is_sent == -1) {
        cout << "Error sending message" << endl;
    }
    return 0;
}
//connect to simolator
Client::Client(string ip, int port) {
    this->_port = port;
    this->_ip = ip;

}
int Client::main() {
    //create socket
    if (this->client_socket == -1) {
        //error
        cerr << "Could not create a socket" << endl;
        return -1;
    }
    char *ip = const_cast<char *>((const char *) _ip.c_str());
    //We need to create a sockaddr obj to hold address of server
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;//IP4
    address.sin_addr.s_addr = inet_addr(ip);  //the localhost address
    address.sin_port = htons(_port);
    //we need to convert our number (both port & localhost)
    // to a number that the network understands.

    // Requesting a connection with the server on local host with port 8081
    int is_connect = connect(client_socket, (struct sockaddr *) &address, sizeof(address));
    if (is_connect == -1) {
        cerr << "Could not connect to host server" << endl;
        return -2;
    } else {
        cout << "Client is now connected to server" << endl;
    }
    return 0;
}

