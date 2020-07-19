//
// Created by liel and adi on 1/1/20.
//

#include "lexer.h"


/**
 * readFile
 *@parm sFile :  name of file
 * need to split the info from file
 */
void lexer::readFile(string sFile) {
    int i;
    ifstream fp(sFile);
    if (!fp.good()) {
        throw "Error in open file";
    }
    bool flagNotSplipStart = false;// to know if split the info or not
    set<char> unsign= {'(', ')', ',', ' ','\n','\t'};// to split
    char c;
    string str = "";
    bool flagSpace = true;
    bool flagConnect = false;
    //read the file by char
    while (fp.get(c)) {
        if (c == '"') {
            flagNotSplipStart = !flagNotSplipStart;
        }
        if(flagNotSplipStart && c == '\n') {
            if(str[str.length()-1] == ')') {
                str = str.substr(0, str.length() - 1);
            }
            flagNotSplipStart = false;
        }
        if ((unsign.find(c) == unsign.end()) || (flagNotSplipStart)) {
            if (c != '"' && c != '\\') {
                str = str + c;
                flagSpace = true;
            }
        } else if (flagSpace){
            stringFromFile.push_back(str);
            countArr++;
            if(flagConnect) {
                flagNotSplipStart = true;
                flagConnect = false;
            }
            if (str == "openDataServer" || str == "=" || str == "Sleep" || str == "if" || str == "while"){// || flagConnect) {
                flagNotSplipStart = true;
            }
            if (str == "connectControlClient") {
                flagConnect = true;
            }
            str = "";
            flagSpace = false;

        }
        i++;
    }
}
/**
 * mappingoCommand : mapping all the commend
 */
void lexer::mappingoCommand() {
    this->mapCommand.insert(pair<string, Command*>("openDataServer",  new OpenServerCommand()));
    this->mapCommand.insert(pair<string, Command*>("connectControlClient", new ConnectCommand()));
    this->mapCommand.insert(pair<string, Command*>("var", new DefineVarCommand()));
    this->mapCommand.insert(pair<string, Command*>("Print", new PrintCommand()));
    this->mapCommand.insert(pair<string, Command*>("Sleep", new SleepCommand()));
    this->mapCommand.insert(pair<string, Command*>("if", new WhileCommand()));
    this->mapCommand.insert(pair<string, Command*>("while", new WhileCommand()));

}
/**
 * parser : run all the file and do acxecuet (what all commend need to do)
 */
void lexer::parser() {
    int i;// run on all the info from file
    int  temp;// temp of i
    int  startWhile = 0;// save the start of while to knoe when to start again (becous while is return)
    bool whileLoop = false;// enter to while
    Singleton *singleton = singleton->getInstance();
    //spacial mention to while (run antil founf " } "
    for (i = 0; i < countArr; i++) {
        if (whileLoop) {
            if (stringFromFile[i] == "}") {
                whileLoop = false;
                // tell i that whle us ending and need to return read nurmal
                i = (startWhile - 1);
            }
        }// if the string in the commend map.
        if (this->mapCommand.find(stringFromFile[i]) != this->mapCommand.end()){
            Command *c = this->mapCommand[stringFromFile[i]];
            if ( c != NULL) {
                temp = i + c->execute(i, this->stringFromFile);
                // if c is while
                if (temp < i) {
                       whileLoop = true;
                    temp = temp + 2;
                    startWhile = temp;
                }
                i = temp;
            }
        }
        string str = stringFromFile[i];
        // if string[i] is var
        if ((singleton->infoFromSimulator.find(str) != singleton->infoFromSimulator.end())  || (singleton->singerVar.find(str) != singleton->singerVar.end())) {
            if (stringFromFile[i + 1] == "=") {
                singleton->insertValue(stringFromFile[i + 2], stringFromFile[i]);
            }
        }
    }
}