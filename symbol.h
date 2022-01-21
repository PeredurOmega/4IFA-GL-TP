//
// Created by pauls on 21/01/2022.
//

#ifndef TP_4IFA_GL_SYMBOL_H
#define TP_4IFA_GL_SYMBOL_H

#pragma once

#include <iostream>
#include <string>

using namespace std;

enum Identifiers {
    OPEN_PAR, CLOSE_PAR, PLUS, MULTIPLICATION, INT, END, ERROR, EXPR
};

const string Labels[] = {"OPEN_PAR", "CLOSE_PAR", "PLUS", "MULTIPLICATION", "INT",
                         "END", "ERROR", "EXPR"};

class Symbol {
public:
    Symbol(int i, bool terminal) : ident(i), terminal(terminal) {}

    operator int() const { return ident; } // NOLINT(google-explicit-constructor)

    void Display() const;

    bool isTerminal() const { return terminal; }

protected:
    int ident;
    bool terminal;
};

class Expression : public Symbol {
public:
    explicit Expression(int value) : Symbol(EXPR, false), value(value) {}

    void Display();

    int getValue() const { return value; }

protected:
    int value;
};

class Integer : public Symbol {
public:
    explicit Integer(int v) : Symbol(INT, true), value(v) {}

    void Display();

    int getValue() const { return value; }

protected:
    int value;
};

class OpenPar : public Symbol {
public:
    OpenPar() : Symbol(OPEN_PAR, true) {}
};

class ClosePar : public Symbol {
public:
    ClosePar() : Symbol(CLOSE_PAR, true) {}
};

class Plus : public Symbol {
public:
    Plus() : Symbol(PLUS, true) {}
};

class Multiplication : public Symbol {
public:
    Multiplication() : Symbol(MULTIPLICATION, true) {}
};

class End : public Symbol {
public:
    End() : Symbol(END, true) {}
};

class Error : public Symbol {
public:
    Error() : Symbol(ERROR, true) {}
};

#endif //TP_4IFA_GL_SYMBOL_H
