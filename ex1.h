//
// Created by liel and adi on 1/1/20.
//

#ifndef FLYSIMULATOR1_0_EX1_H
#define FLYSIMULATOR1_0_EX1_H

#include "Expression.h"
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <queue>
//#include "Singleton.h"
#include <map>
using namespace std;

class Value : public Expression {
protected:
    double val;
public:
    Value(double val);
    double  calculate();
};

class Variable: public Expression {
protected:
    double num;
    string str;
public:
    Variable &operator++();
    Variable &operator++(int);
    Variable &operator--();
    Variable &operator--(int);
    Variable(string str, double num);
    double calculate();
    void setValue(double value);
    double getValue();
    string getSim();
};

class BinaryOperator : public Expression {
protected:
    Expression *left;
    Expression *right;
public:
    BinaryOperator(Expression* left, Expression* right);
    ~BinaryOperator() {
        delete left;
        delete right;
    }
};
class UnaryOperator : public Expression {
protected:
    Expression* expression;
public:
    UnaryOperator(Expression* expression);
    ~UnaryOperator() {
        delete expression;
    }
};
class UMinus : public UnaryOperator {
    Expression* expression;
public:
    UMinus(Expression* expression);
    double calculate();
};
class UPlus : public UnaryOperator {
    Expression* expression;
public:
    UPlus(Expression* expression);
    double calculate();
};
class Plus : public BinaryOperator {
    Expression *left;
    Expression *right;
public:
    Plus(Expression *left, Expression *right);

    double calculate();
};
class Mul : public BinaryOperator {
    Expression *left;
    Expression *right;
public:
    Mul(Expression *left, Expression *right);

    double calculate();
};
class Div : public BinaryOperator {
    Expression *left;
    Expression *right;
public:
    Div(Expression *left, Expression *right);

    double calculate();
};
class Minus : public BinaryOperator {
    Expression *left;
    Expression *right;
public:
    Minus(Expression *left, Expression *right);
    double calculate();
};



class Interpreter {
public:
    map <string, double > mapA;
    void setVariables(string str);
    Expression* interpret(string str);
    string checkSpace(string str);
    void enterMap();
};

#endif //FLYSIMULATOR1_0_EX1_H
