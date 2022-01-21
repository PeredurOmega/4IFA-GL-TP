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
    explicit Lexer(string expr, bool negativeIntegersSupport) :
            flow(std::move(expr)),
            head(0),
            buffer(nullptr),
            negativeIntegersSupport(negativeIntegersSupport) {}

    ~Lexer() = default;

    Symbol *Consult();

    void MoveForward();

    void addSymbolToBuffer(Symbol *s);

private:
    string flow;
    size_t head;
    Symbol *buffer;
    bool negativeIntegersSupport;

};

#endif //TP_4IFA_GL_LEXER_H