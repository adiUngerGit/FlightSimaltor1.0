//
// Created by liel and adi on 1/1/20.
//
#include "OpenServerCommand.h"
/**
 * startServer : new Server
 */
void startServer(int portListen) {
    Server *server = new Server(portListen);
    server->main();
}
/*
 * execute : enter to server
 * @param arrCommand : all the info from the file
 * @param i : arrCommend[i] = openDataServer
 * @return : 1
 */
int OpenServerCommand::execute(int i, vector<string> arrCommand) {
    Interpreter *portInter = new Interpreter();
    portInter->enterMap();
    Expression *portExp = portInter->interpret(arrCommand[i+1]);
    try {
        this->portListen = portExp->calculate();
        startServer(this->portListen);
    }
    catch (...) {
        throw "ERROR WHILE INTERPETER OPERN DATA SERVER";
    }
    return 1;
}
