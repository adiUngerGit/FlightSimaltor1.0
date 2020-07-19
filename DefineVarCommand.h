//
// Created by liel and adi on 1/1/20.
//

#ifndef FLYSIMULATOR1_0_DEFINEVARCOMMAND_H
#define FLYSIMULATOR1_0_DEFINEVARCOMMAND_H

#include "Command.h"
class DefineVarCommand : public Command {
public:
    virtual int execute(int i, vector<string> arrCommand);
};

#endif //FLYSIMULATOR1_0_DEFINEVARCOMMAND_H
