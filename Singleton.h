//
// Created by liel and adi on 1/1/20.
//
#ifndef FLYSIMULATOR1_0_SINGLETON_H
#define FLYSIMULATOR1_0_SINGLETON_H

#include "Client.h"

#include <map>
#include <vector>
#include "ex1.h"
#include <mutex>
#include <iostream>
#include <cstring>
using namespace std;
class Singleton {
private:
    /* Here will be the instance stored. */
    static Singleton *instance;
public:
    //the maps of the simulator
    map<string, int> simToNum ;
    map<string, Variable> singerVar;
    vector<string> infoFromSim  = {"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"};
    mutex mtx;
    bool endProgram = false;
    void makeSingelVar(string str, string val);
    map<string, Variable> infoFromSimulator;
    void parsingXML();
    Singleton();
    void creatingInfoFromSim(string var, string sim);
    // Singleton getInstance();
    static Singleton *getInstance();
    void creatingVarIntoMap(string var, string sim);
    void insertValue(string value, string nameVar);
    vector<string> get();
    void set(vector<string> info);
    Client* _client;
};


#endif //FLYSIMULATOR1_0_SINGLETON_H
