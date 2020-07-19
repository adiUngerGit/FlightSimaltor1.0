//
// Created by liel and adi on 1/1/20.
//
#ifndef FLYSIMULATOR1_0_EXPRESSION_H
#define FLYSIMULATOR1_0_EXPRESSION_H


class Expression {

public:
    virtual double calculate() = 0;

    virtual ~Expression() {}
};


#endif //FLYSIMULATOR1_0_EXPRESSION_H
