//
// Created by pauls on 21/01/2022.
//

#ifndef TP_4IFA_GL_SYMBOL_H
#define TP_4IFA_GL_SYMBOL_H

#pragma once

#include <string>
#include <iostream>

using namespace std;

/**
 * Enumeration of the different identifiers.
 */
enum Identifiers {
    OPEN_PAR, CLOSE_PAR, PLUS, MULTIPLICATION, INT, END, ERROR, EXPR
};

/**
 * Symbol class (to be inherited from by the different symbols).
 */
class Symbol {
public:
    /**
     * Constructor of Symbol.
     * @param i Identifier (to provide from enum).
     * @param terminal Whether it's terminal or not.
     */
    Symbol(int i, bool terminal) : ident(i), terminal(terminal) {}

    /**
     * Auto convert to the identifier when attempting to test equality with an
     * int.
     * @return The identifier.
     */
    operator int() const { return ident; } // NOLINT(google-explicit-constructor)

    /**
     * Debug the Symbol.
     */
    void Display() const;

    /**
     * @return Whether the symbol is terminal or not.
     */
    bool isTerminal() const { return terminal; }

protected:
    /**
     * Identifier of the symbol.
     */
    int ident;

    /**
     * Whether it's terminal or not.
     */
    bool terminal;
};

class Expression : public Symbol {
public:
    explicit Expression(int value) : Symbol(EXPR, false), value(value) {}

    __attribute__((unused)) void Display();

    int getValue() const { return value; }

protected:
    /**
     * Evaluated value of the expression.
     */
    int value;
};

class Integer : public Symbol {
public:
    explicit Integer(int v) : Symbol(INT, true), value(v) {}

    __attribute__((unused)) void Display();

    int getValue() const { return value; }

protected:
    /**
     * Evaluated value of the expression.
     */
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
