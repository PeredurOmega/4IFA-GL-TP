#ifndef TP_4IFA_GL_LEXER_H
#define TP_4IFA_GL_LEXER_H

#pragma once

#include "state.h"
#include "symbol.h"
#include <utility>
#include <string>

using namespace std;

class Lexer {

public:
    explicit Lexer(string expr) : flow(std::move(expr)), head(0),
                                  buffer(nullptr) {}

    ~Lexer() = default;

    Symbol *Consult();

    void MoveForward();

protected:
    string flow;
    int head;
    Symbol *buffer;
};

#endif //TP_4IFA_GL_LEXER_H