//
// Created by liel and adi on 1/1/20.
//
#include "SleepCommand.h"
#include <thread>
#include <chrono>
using namespace std;
int SleepCommand::execute(int i, vector<string> stringToPrint) {
    Interpreter *sleepInt = new Interpreter();
    sleepInt->enterMap();
    Expression *sleepExp = sleepInt->interpret(stringToPrint[i+1]);
    try {
        int time = sleepExp->calculate();
        std::this_thread::sleep_for(std::chrono::milliseconds (time));
    } catch (...) {
        cout << "Error in interpeter at sleep command";
    }
    return 1;
}
