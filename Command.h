//
// Created by liel and adi on 1/1/20.
//

#ifndef FLYSIMULATOR1_0_COMMAND_H
#define FLYSIMULATOR1_0_COMMAND_H
#include <iostream>
#include <map>
#include "thread"
#include "Client.h"
#include "Server.h"
#include "Singleton.h"
#include <vector>
#include <unistd.h>
using namespace std;
class Command {
public:
/*
 * execute : enter to server
 * @param arrCommand : all the info from the file
 * @param i : arrCommend[i] = commend
 * @return : the next i for lexer
 */
    virtual int execute(int i,  vector<string> arrCommand) = 0;
    virtual ~Command() = default;
};


#endif //FLYSIMULATOR1_0_COMMAND_H
