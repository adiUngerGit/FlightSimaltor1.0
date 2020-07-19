//
// Created by liel and adi on 1/1/20.
//

#ifndef FLYSIMULATOR1_0_CONNECTCOMMAND_H
#define FLYSIMULATOR1_0_CONNECTCOMMAND_H

#include "Command.h"

class ConnectCommand : public Command{
    string ip;
    int port;
public:
    virtual int execute(int i, vector<string> arrCommand);
};


#endif //FLYSIMULATOR1_0_CONNECTCOMMAND_H
