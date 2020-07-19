//
// Created by liel and adi on 1/1/20.
//

#include "ConnectCommand.h"
#include "Singleton.h"
/*
 * startTheClient : make new Client and save in singelton
 */
void startTheClient(string ip, int port) {
    Client *client = new Client(ip,port);
    Singleton *singleton = Singleton().getInstance();
    singleton->_client = client;
    client->main();
}
/**
 *  execute : calculate ip and port and add to client
 */
int ConnectCommand::execute(int i, vector<string> arrCommand) {
    Interpreter *portInter = new Interpreter();
    portInter->enterMap();
    Expression *portExp = portInter->interpret(arrCommand[i+2]);
    ip = arrCommand[i + 1];
    try {
        // try connect
        this->port = portExp->calculate();
        startTheClient(this->ip, this->port);
    }
    catch (...) {
        throw "ERROR WHILE interpeter at connect command";
    }
    return 2;
}