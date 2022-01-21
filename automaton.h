//
// Created by pauls on 21/01/2022.
//

#ifndef TP_4IFA_GL_AUTOMATON_H
#define TP_4IFA_GL_AUTOMATON_H

#pragma once

#include <string>
#include <vector>
#include <deque>
#include "symbol.h"
#include "state.h"
#include "lexer.h"
#include <utility>
#include <deque>
#include <iostream>

using namespace std;

class Automaton {
public:
    explicit Automaton(string expr);

    bool run();

    void shift(Symbol *symbol, State *state);

    void reduction(int n, Symbol *s);

private:
    vector<Symbol *> symbols;
    vector<State *> states;
    Lexer *lexer;

    static int evaluate(int n, std::deque<Symbol *>& symbolsToEval);
};

#endif //TP_4IFA_GL_AUTOMATON_H
