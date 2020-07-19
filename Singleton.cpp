//
// Created by liel and adi on 1/1/20.
//

#include "Singleton.h"
/**
 * parsingXML : enter info to simToNun
 * where sim in xml (the file to sim)
 */
void Singleton::parsingXML() {
    this->simToNum["/instrumentation/airspeed-indicator/indicated-speed-kt"] =  0;
    this->simToNum["/sim/time/warp"] = 1;
    this->simToNum["/controls/switches/magnetos"] = 2;
    this->simToNum["/instrumentation/heading-indicator/offset-deg"] = 3;
    this->simToNum["/instrumentation/altimeter/indicated-altitude-ft"] = 4;
    this->simToNum["/instrumentation/altimeter/pressure-alt-ft"] = 5;
    this->simToNum["/instrumentation/attitude-indicator/indicated-pitch-deg"] = 6;
    this->simToNum["/instrumentation/attitude-indicator/indicated-roll-deg"] = 7;
    this->simToNum["/instrumentation/attitude-indicator/internal-pitch-deg"] = 8;
    this->simToNum["/instrumentation/attitude-indicator/internal-roll-deg"] = 9;
    this->simToNum["/instrumentation/encoder/indicated-altitude-ft"] = 10;
    this->simToNum["/instrumentation/encoder/pressure-alt-ft"]  = 11;
    this->simToNum["/instrumentation/gps/indicated-altitude-ft"] = 12;
    this->simToNum["/instrumentation/gps/indicated-ground-speed-kt"] = 13;
    this->simToNum["/instrumentation/gps/indicated-vertical-speed"] = 14;
    this->simToNum["/instrumentation/heading-indicator/indicated-heading-deg"] = 15;
    this->simToNum["/instrumentation/magnetic-compass/indicated-heading-deg"] = 16;
    this->simToNum["/instrumentation/slip-skid-ball/indicated-slip-skid"] = 17;
    this->simToNum["/instrumentation/turn-indicator/indicated-turn-rate"] = 18;
    this->simToNum["/instrumentation/vertical-speed-indicator/indicated-speed-fpm"] = 19;
    this->simToNum["/controls/flight/aileron"] = 20;
    this->simToNum["/controls/flight/elevator"] = 21;
    this->simToNum["/controls/flight/rudder"] = 22;
    this->simToNum["/controls/flight/flaps"] = 23;
    this->simToNum["/controls/engines/engine/throttle"] = 24;
    this->simToNum["/controls/engines/current-engine/throttle"] = 25;
    this->simToNum["/controls/switches/master-avionics"] = 26;
    this->simToNum["/controls/switches/starter"] = 27;
    this->simToNum["/engines/active-engine/auto-start"] = 28;
    this->simToNum["/controls/flight/speedbrake"] = 29;
    this->simToNum ["/sim/model/c172p/brake-parking"] = 30;
    this->simToNum ["/controls/engines/engine/primer"] = 31;
    this->simToNum["/controls/engines/current-engine/mixture"] = 32;
    this->simToNum["/controls/switches/master-bat"] = 33;
    this->simToNum["/controls/switches/master-alt"] = 34;
    this->simToNum["/engines/engine/rpm"] = 35;
}
/*
 * @return infoFromSim
 */
vector<string>  Singleton::get() {
    return this->infoFromSim;
}
/*
 * set : change infoFromSim
 * @param : info : vector
 */
void Singleton::set(vector<string> info) {
    int i;
    for (i = 0 ; i < 36; i++) {
        this->infoFromSim[i] = info[i];
    }
}
/**
 * makeSingelVar : enter value to map that save all the singel var { X = Y } whiout connect to simolator
 * @param : namevar and value
 */
void Singleton ::makeSingelVar(string nameVar, string val) {
    mtx.lock();
    Interpreter *valInter = new Interpreter();
    valInter->enterMap();
    Expression *valExp = valInter->interpret(val);
    Variable v("0",valExp->calculate());
    try {
        this->singerVar.insert({nameVar,v});
    } catch(...) {
        cout << "Error in interpeter value in make single var in singleton" << endl;
    }
    mtx.unlock();
}
/*
 * creatingInfoFromSim :  enter value to map that save the info from var's that connect to simolator
 * @param : namevar and value
 */
void Singleton::creatingInfoFromSim(string var, string sim) {
    mtx.lock();
    double value;
    this->parsingXML();
    int index = this->simToNum[sim];
    string temp = this->infoFromSim[index];
    try {
        value = stod(temp);
    } catch (...) {
        cout << "Error in stod";
    }
    Variable v(sim,value);
    this->infoFromSimulator.insert({var,v});
    mtx.unlock();
}
/*
 * insertValue :  enter value to map that save the info from var's that connect to simolator
 * @param : namevar and value
 */
void Singleton::insertValue(string value, string nameVar) {
    mtx.lock();
Interpreter *valueInter = new Interpreter();
    valueInter->enterMap();
    Expression *valueExp = valueInter->interpret(value);
    try {
        // if the var need to change in mapFromSimolator
        if(this->infoFromSimulator.find(nameVar) != this->infoFromSimulator.end()) {
            this->infoFromSimulator.find(nameVar)->second.setValue(valueExp->calculate());
            Variable v(this->infoFromSimulator.find(nameVar)->second.getSim(),this->infoFromSimulator.find(nameVar)->second.getValue());
            //call to server and change the simolator
            _client->connectToServer(v);
        }        // if the var need to change in singelVar
        if(this->singerVar.find(nameVar) != this->singerVar.end()) {
            this->singerVar.find(nameVar)->second.setValue(valueExp->calculate());
        }
    } catch (...) {
        cout << "Error in interpeter ins insert value at Singleton"<< endl;
    }
    mtx.unlock();
}
Singleton *Singleton::instance = 0;
Singleton::Singleton() {}
Singleton *Singleton::getInstance() {
    if (instance == 0) {
        instance = new Singleton();
    }
    return instance;
}
// taken from : value singelton wikipedia