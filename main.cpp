//
// Created by liel and adi on 1/1/20.
//
#include "lexer.h"
int main(int argc, char *argv[]) {
    if (argc <= 2) {
        lexer l;
        l.readFile(argv[1]);
        l.mappingoCommand();
        l.parser();
    }
}