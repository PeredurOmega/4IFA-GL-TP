//
// Created by Paul SOUTEYRAT & Alexandre MARTIN on 21/01/2022.
//

#include <utility>
#include <iostream>
#include "automaton.h"

Automaton::Automaton(string expr, bool negativeIntegerSupport) {
    this->lexer = new Lexer(std::move(expr), negativeIntegerSupport);
    auto *init = new State0();
    states.push_back(init);
}

Automaton::~Automaton() {
    delete (lexer);
    while (!states.empty()) {
        delete (states.back());
        states.pop_back();
    }
    while (!symbols.empty()) {
        delete (symbols.back());
        symbols.pop_back();
    }
}

bool Automaton::run() {
    bool hasNextState = true;

    while (hasNextState) {
        Symbol *s = nullptr;
        do {
            delete (s);
            s = lexer->Consult();
        } while (s == nullptr); // Support for spaces in expressions

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

void Automaton::shift(Symbol *symbol, State *state) {
    symbols.push_back(symbol);
    states.push_back(state);
    if (symbol->isTerminal()) {
        lexer->MoveForward();
    }
}

void Automaton::reduction(int n, Symbol *symbol) {
    vector<Symbol *> usedSymbols;
    for (int i = 0; i < n; i++) {
        delete (states.back());
        states.pop_back();
        usedSymbols.push_back(symbols.back());
        symbols.pop_back();
    }

    Expression *expr = evaluate(n, usedSymbols);
    states.back()->Transition(*this, expr);
    lexer->addSymbolToBuffer(symbol);
}

Expression *Automaton::evaluate(int n, vector<Symbol *> &symbolsToEval) {
    Expression *expr;
    if (n == 1) {
        expr = new Expression(
                ((SymbolWithValue *) symbolsToEval[0])->getValue());
    } else if (n == 3) {
        if (*symbolsToEval[2] == OPEN_PAR) {
            expr = new Expression(
                    ((SymbolWithValue *) symbolsToEval[1])->getValue());
        } else {
            auto s2 = ((SymbolWithValue *) symbolsToEval[0]);
            Symbol sOperator = *(symbolsToEval[1]);
            auto s1 = ((SymbolWithValue *) symbolsToEval[2]);
            if (sOperator == MULTIPLICATION) {
                expr = MultiplicationExpr::newMultiplication(s1, s2);
            } else if (sOperator == PLUS) {
                expr = AdditionExpr::newAddition(s1, s2);
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
    //We erase the vector
    while (!symbolsToEval.empty()) {
        delete (symbolsToEval.back());
        symbolsToEval.pop_back();
    }
    return expr;
}
