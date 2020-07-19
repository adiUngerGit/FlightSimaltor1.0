//
// Created by liel and adi on 1/1/20.
//

#ifndef FLYSIMULATOR1_0_PRINTCOMMAND_H
#define FLYSIMULATOR1_0_PRINTCOMMAND_H

#include "Command.h"
class PrintCommand: public Command {
public:
    virtual int execute(int i, vector<string> stringToPrint);
};


#endif //FLYSIMULATOR1_0_PRINTCOMMAND_H
