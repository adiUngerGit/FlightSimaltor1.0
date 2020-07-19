//
// Created by liel and adi on 1/1/20.
//
/**
 * DefineVarCommand : make new var
 * 3 option :
 * 1 -> fron sim
 * 2 <- to sim
 * 3 = alon var
 */
#include "DefineVarCommand.h"
int DefineVarCommand::execute(int i, vector<string> arrCommand) {
    Singleton *s = s->getInstance();
    string temp = arrCommand[i+1];
    temp = arrCommand[i+2];
    //to sim
    if(temp == "<-") {
        s->creatingInfoFromSim(arrCommand[i+1], arrCommand[i+4]);
    }    // from sim
    else if (temp == "->") {
        s->creatingInfoFromSim(arrCommand[i+1], arrCommand[i+4]);
     //   s->callServer(s->infoFromSimulator.find(arrCommand[i+1])->second);
    }    // alon var (X = Y)
    else if (temp == "=") {
        s->makeSingelVar(arrCommand[i+1],arrCommand[i+3]);
        return 3;
    }
    return 4;
}