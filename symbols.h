//
// Created by Paul SOUTEYRAT & Alexandre MARTIN on 21/01/2022.
//

#ifndef TP_4IFA_GL_SYMBOLS_H
#define TP_4IFA_GL_SYMBOLS_H

#pragma once

#include <string>
#include <iostream>

using namespace std;

/**
 * Enumeration of the different identifiers.
 */
enum Identifiers {
    OPEN_PAR,
    CLOSE_PAR,
    PLUS,
    MULTIPLICATION,
    INT,
    END,
    ERROR,
    EXPR
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

/**
 * Symbol with a value (i.e. an Integer or an Expression).
 */
class SymbolWithValue : public Symbol {
public:
    explicit SymbolWithValue(int i, bool terminal, int value)
            : Symbol(i, terminal), value(value) {}

    __attribute__((unused)) void Display();

    int getValue() const { return value; }

protected:
    /**
     * Value of the symbol.
     */
    int value;
};

/**
 * Evaluated expression.
 */
class Expression : public SymbolWithValue {
public:
    explicit Expression(int value) : SymbolWithValue(EXPR, false, value) {}
};

/**
 * Evaluated expression for a product of two SymbolWithValue.
 */
class MultiplicationExpr : public Expression {
public:
    /**
     * @param s1 SymbolWithValue *
     * @param s2 SymbolWithValue *
     * @return MultiplicationExpr with an evaluated value of s1 * s2.
     */
    static MultiplicationExpr *
    newMultiplication(SymbolWithValue *s1, SymbolWithValue *s2) {
        return new MultiplicationExpr(s1->getValue() * s2->getValue());
    }

private:
    explicit MultiplicationExpr(int value) : Expression(value) {}
};

/**
 * Evaluated expression for an addition of two SymbolWithValue.
 */
class AdditionExpr : public Expression {
public:
    /**
     * @param s1 SymbolWithValue *
     * @param s2 SymbolWithValue *
     * @return AdditionExpr with an evaluated value of s1 + s2.
     */
    static AdditionExpr *
    newAddition(SymbolWithValue *s1, SymbolWithValue *s2) {
        return new AdditionExpr(s1->getValue() + s2->getValue());
    }

private:
    explicit AdditionExpr(int value) : Expression(value) {}
};

/**
 * Symbol Integer representing an integer which can be negative is the support
 * for negative integers has been added.
 */
class Integer : public SymbolWithValue {
public:
    explicit Integer(int v) : SymbolWithValue(INT, true, v) {}
};

/**
 * Symbol OpenPar representing an open parentheses '('.
 */
class OpenPar : public Symbol {
public:
    OpenPar() : Symbol(OPEN_PAR, true) {}
};

/**
 * Symbol ClosePar representing a close parentheses ')'.
 */
class ClosePar : public Symbol {
public:
    ClosePar() : Symbol(CLOSE_PAR, true) {}
};

/**
 * Symbol Plus representing a plus operator '+'.
 */
class Plus : public Symbol {
public:
    Plus() : Symbol(PLUS, true) {}
};

/**
 * Symbol Multiplication representing a multiplication operator '*'.
 */
class Multiplication : public Symbol {
public:
    Multiplication() : Symbol(MULTIPLICATION, true) {}
};

/**
 * Symbol End representing the end of the analyzed expression (formally
 * represented by '$').
 */
class End : public Symbol {
public:
    End() : Symbol(END, true) {}
};

/**
 * Symbol Error representing an Error.
 */
class Error : public Symbol {
public:
    Error() : Symbol(ERROR, true) {}
};

#endif //TP_4IFA_GL_SYMBOLS_H
