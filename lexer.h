// Created by Paul SOUTEYRAT & Alexandre MARTIN on 21/01/2022.

#ifndef TP_4IFA_GL_LEXER_H
#define TP_4IFA_GL_LEXER_H

#pragma once

#include <string>
#include "state.h"
#include "symbols.h"

using namespace std;

/**
 * Lexical analyzer to consult the different Symbol to use in the flow.
 */
class Lexer {
public:
    /**
     * Constructor of the Lexer.
     * @param expr String to analyze.
     * @param negativeIntegersSupport True to support negative integers, False
     * otherwise.
     */
    explicit Lexer(string expr, bool negativeIntegersSupport) :
            flow(std::move(expr)), head(0), buffer(nullptr),
            negativeIntegersSupport(negativeIntegersSupport) {}

    ~Lexer();

    /**
     * Consult a symbol in the flow.
     * @return A pointer of the symbol found in the flow.
     */
    Symbol *Consult();

    /**
     * Move forward, i.e. make the buffer non-null.
     */
    void MoveForward();

    /**
     * Set the buffer to the symbol
     * @param s Symbol to use as buffer.
     */
    void addSymbolToBuffer(Symbol *s);

private:
    /**
     * Expr to analyze.
     */
    string flow;

    /**
     * Position in the flow.
     */
    size_t head;

    /**
     * Buffer to use.
     */
    Symbol *buffer;

    /**
     * True if we want to support negative integers, False otherwise.
     */
    bool negativeIntegersSupport;
};

#endif //TP_4IFA_GL_LEXER_H