//
// Created by pauls on 21/01/2022.
//

#include <utility>
#include <iostream>
#include "automaton.h"

Automaton::Automaton(string expr, bool negativeIntegerSupport) {
    this->lexer = new Lexer(std::move(expr), negativeIntegerSupport);
    auto *init = new State0();
    states.push_back(init);
}

void Automaton::shift(Symbol *symbol, State *state) {
    symbols.push_back(symbol);
    states.push_back(state);
    if (symbol->isTerminal()) {
        lexer->MoveForward();
    }
}

void Automaton::reduction(int n, Symbol *symbol) {
    deque<Symbol *> usedSymbols;
    for (int i = 0; i < n; i++) {
        delete (states.back());
        states.pop_back();
        usedSymbols.push_front(symbols.back());
        symbols.pop_back();
    }

    int evaluation = evaluate(n, usedSymbols);

    states.back()->Transition(*this, new Expression(evaluation));
    lexer->addSymbolToBuffer(symbol);
}

int Automaton::evaluate(int n, deque<Symbol *> &symbolsToEval) {
    int evaluation = 0;
    if (n == 1) {
        evaluation = ((Integer *) symbolsToEval.front())->getValue();
    } else if (n == 3) {
        if (*symbolsToEval.front() == OPEN_PAR) {
            symbolsToEval.pop_front();
            evaluation = ((Integer *) symbolsToEval.front())->getValue();
        } else {
            evaluation = ((Integer *) symbolsToEval.front())->getValue();
            symbolsToEval.pop_front();
            if (*symbolsToEval.front() == MULTIPLICATION) {
                symbolsToEval.pop_front();
                evaluation *= ((Integer *) symbolsToEval.front())->getValue();
            } else if (*symbolsToEval.front() == PLUS) {
                symbolsToEval.pop_front();
                evaluation += ((Integer *) symbolsToEval.front())->getValue();
            } else {
                // Should never occur
                cerr << "An unknown error occurred. "
                     << "Be sure to use a valid expression."
                     << endl;
            }
        }
    } else {
        // Should never occur
        cerr << "An unknown error occurred. "
             << "Be sure to use a valid expression."
             << endl;
    }
    return evaluation;
}

bool Automaton::run() {
    bool hasNextState = true;

    while (hasNextState) {
        Symbol *s = lexer->Consult();
        lexer->MoveForward();
        hasNextState = states.back()->Transition(*this, s);
    }

    if (*symbols.back() == ERROR) {
        cerr << "Error: Invalid expression." << endl << "Please retry." << endl;
        return false;

    } else {
        int result = ((Expression *) symbols.back())->getValue();
        cout << "Result: " << result << endl;
        return true;
    }
}
