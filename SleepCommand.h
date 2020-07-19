//
// Created by liel and adi on 1/1/20.
//
#ifndef FLYSIMULATOR1_0_SLEEPCOMMAND_H
#define FLYSIMULATOR1_0_SLEEPCOMMAND_H

#include "Command.h"
class SleepCommand : public Command{
public:
    virtual int execute(int i,vector<string> stringToPrint);
};


#endif //FLYSIMULATOR1_0_SLEEPCOMMAND_H
