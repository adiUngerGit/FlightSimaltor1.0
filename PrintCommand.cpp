//
// Created by liel and adi on 1/1/20.
//
/**
 * execute : enter to server
 * @param arrCommand : all the info from the file
 * @param i : arrCommend[i] = commend
 * @return : the next i for lexer
 */
#include "PrintCommand.h"
int PrintCommand::execute(int i, vector<string> stringToPrint) {
    Singleton *singleton = singleton->getInstance();
    if(stringToPrint[i+1] == "done") {
        singleton->endProgram = true;
    }
    // if need to print is in the map
    if (singleton->infoFromSimulator.find(stringToPrint[i + 1]) != singleton->infoFromSimulator.end()) {
        cout << singleton->infoFromSimulator.find(stringToPrint[i+1])->second.getValue() << endl;
    } else {
        cout << stringToPrint[i + 1] << endl;
    }
    return 1;
}
