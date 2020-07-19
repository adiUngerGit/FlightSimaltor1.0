//
// Created by user on 1/1/20.
//

#ifndef FLYSIMULATOR1_0_OPENSERVERCOMMAND_H
#define FLYSIMULATOR1_0_OPENSERVERCOMMAND_H

#include "Command.h"


class OpenServerCommand : public Command {
    int portListen;
public:
    virtual int execute(int i, vector<string> arrCommand);
};


#endif //FLYSIMULATOR1_0_OPENSERVERCOMMAND_H
