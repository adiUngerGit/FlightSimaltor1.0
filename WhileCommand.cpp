//
// Created by liel and adi on 1/1/20.
//
//
// Created by liel and adi on 1/1/20.
//
//
// Created by liel and adi on 1/1/20.
//

#include "WhileCommand.h"
/**
 * checkSpace : remove all the space in string
 * @param string @return string whitout space
 */
string WhileCommand ::  checkSpace(string str) {
    unsigned i;// run all the str
    string final = "";// new string
    for(i = 0; i < str.size() ; i++) {
        if (str[i] != ' ' && str[i] != ')' && str[i] != '(') {
            final = final + str[i];
        }
    }
    return final;
}
/**
 * WhileCommand : do lop for all the info from "{" to "}"
 */
int WhileCommand::execute(int i, vector<string> stringToPrint) {
    bool twoOperators = false;// false : < > = true: >= <= != ==
    bool isWhile = false; // false = if true = while
    Singleton *singleton = singleton->getInstance();
    set<char> operators{'<', '>', '!', '='};
    int end = 0, temp = i;
    unsigned j = 0;
    if (stringToPrint[i] == "while") {
        isWhile = true;
    }
    // end = the size from "{" to "}'
    while (stringToPrint[temp] != "}") {
        temp++;
    }
    end = temp - i;
    stringToPrint[i + 1] = checkSpace(stringToPrint[i + 1]);
    // check if 1 or 2 operator
    for (j = 0; j < stringToPrint[i + 1].size(); j++) {
        if (operators.find(stringToPrint[i + 1][j]) != operators.end()) {
            if (operators.find(stringToPrint[i + 1][j + 1]) != operators.end()) {
                twoOperators = true;
            }
            break;
        }
    }
    string leftString, rightString;
    leftString = stringToPrint[i + 1].substr(0, j);
    if (twoOperators) {
        rightString = stringToPrint[i + 1].substr(j + 2, stringToPrint[i].size() - 1);
    } else {
        rightString = stringToPrint[i + 1].substr(j + 1, stringToPrint[i].size() - 1);
    }
    Interpreter *rightSide = new Interpreter();
    Interpreter *leftSide = new Interpreter();
    leftSide->enterMap();
    Expression *expressionRight = rightSide->interpret(rightString);
    Expression *expressionLeft = leftSide->interpret(leftString);
    double left = expressionLeft->calculate();
    double right = expressionRight->calculate();
    // return -1 enter to lop while
    // return end if not enter and need to "jump" to next }
    // return 2 enter to if
    if (stringToPrint[i + 1][j] == '<') {
        if (stringToPrint[i + 1][j + 1] == '=') {
            if (left <= right) {
                if(isWhile) {
                    return -1;
                } else {
                    return 1;
                }
            }
            return end;
        }
        if (left < right) {
            if(isWhile) {
                return -1;
            } else {
                return 1;
            }
        }
        return end;
    }
    if (stringToPrint[i + 1][j] == '>') {
        if (stringToPrint[i + 1][j + 1] == '=') {
            if (left >= right) {
                if(isWhile) {
                    return -1;
                } else {
                    return 1;
                }
            }
            return end;
        }
        if (left > right) {
            if (isWhile) {
                return -1;
            } else {
                return 1;
            }
        }
        return end;
    }
    if (stringToPrint[i + 1][j + 1] == '=') {
        if (stringToPrint[i + 1][j] == '=') {
            if (left == right) {
                if(isWhile) {
                    return -1;
                } else {
                    return 1;
                }
            }
            return end;
        }
        if (stringToPrint[i + 1][j] == '!') {
            if (left != right) {
                if(isWhile) {
                    return -1;
                } else {
                    return 1;
                }
            }
            return end;
        }
    }
    return end;
}
