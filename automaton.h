//
// Created by pauls on 21/01/2022.
//

#ifndef TP_4IFA_GL_AUTOMATON_H
#define TP_4IFA_GL_AUTOMATON_H

#pragma once

#include <string>
#include <vector>
#include <deque>
#include <utility>
#include <deque>
#include <iostream>

#include "symbol.h"
#include "state.h"
#include "lexer.h"

using namespace std;

/**
 * Forward declaration of State. Solve circular dependency issue.
 */
class State;

/**
 * Forward declaration of Lexer. Solve circular dependency issue.
 */
class Lexer;

/**
 * Automaton LALR for a bottom up analysis with the State design pattern and
 * using the vector data structure.
 */
class Automaton {
public:
    /**
     * Explicit Automaton constructor.
     * @param expr Expression to analyze (i.e. to get the result from).
     * @param negativeIntegersSupport True if you want to support negative
     * integers in the grammar (i.e. '-12', '4-12' or '(-12)' but not '4-4').
     */
    explicit Automaton(string expr, bool negativeIntegersSupport);

    /**
     * Launch the Automaton to analyze expr and print the result.
     * @return False if there was no error, True otherwise.
     */
    bool run();

    /**
     * Type of transition.
     * Push back the symbol in the vector symbols.
     * Push back the state in the vector states.
     * If the symbol is terminal we move forward (i.e. reset the lexer' buffer).
     * @param symbol Current symbol analyzed in the transition.
     * @param state State to shift to.
     */
    void shift(Symbol *symbol, State *state);

    /**
     * When using a reduction we are in a state that contains a final item.
     * That means we have recognized a non-terminal symbol (the left-hand side
     * of the item).
     * We proceed in two steps:
     * Pop back n elements from the vector.
     * Apply the transition associated to the non-terminal symbol and the new
     * current top state of the vector (and thus push the target state on the
     * vector). This transition is applied on an Expression with the evaluated
     * value.
     * @param n Size of the right-hand side.
     * @param symbol Current symbol analyzed in the transition.
     */
    void reduction(int n, Symbol *symbol);

private:
    /**
     * Vector of the symbols through which we passed in the shift using our
     * states' transitions.
     */
    vector<Symbol *> symbols;

    /**
     * Vector of the browsed states.
     * The first state is always State0.
     */
    vector<State *> states;

    /**
     * Lexical analyzer used by the automaton in order to Consult the symbols
     * of the expr. It is also used in the run's loop and the shift in order to
     * MoveForward.
     */
    Lexer *lexer;

    /**
     * Evaluation of the symbolsToEval (of size n) passed by the reduction.
     * For instance, '4' returns 4. '4+4' returns 8. '4*4' returns 24.
     * '(4)' returns 4.
     * @param n Size of symbolsToEval.
     * @param symbolsToEval Dequeue of the symbols to evaluate should be of
     * size 3.
     * @return The evaluated value of the symbols.
     */
    static int evaluate(int n, std::deque<Symbol *> &symbolsToEval);
};

#endif //TP_4IFA_GL_AUTOMATON_H
