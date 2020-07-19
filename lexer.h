//
// Created by liel and adi on 1/1/20.
//

#ifndef FLYSIMULATOR1_0_LEXER_H
#define FLYSIMULATOR1_0_LEXER_H

#include <map>
#include "Command.h"
#include "vector"
#include <unistd.h>
#include <fstream>
#include <set>
#include <cstring>
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include "DefineVarCommand.h"
#include "WhileCommand.h"
using namespace std;
class lexer {
    vector<string> stringFromFile;
    // char** stringFromFile;
    std::map<string, Command*> mapCommand;
public:
    int countArr = 0;
    void mappingoCommand();
    void readFile(std::string);
    void parser();
};

#endif //FLYSIMULATOR1_0_LEXER_H