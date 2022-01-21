//
// Created by pauls on 21/01/2022.
//

#include "automaton.h"

Automaton::Automaton(string expr) {
    this->lexer = new Lexer(std::move(expr));
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

void Automaton::reduction(int n, Symbol *s) {
    deque<Symbol *> usedSymbols;
    for (int i = 0; i < n; i++) {
        delete (states.back());
        states.pop_back();
        usedSymbols.push_front(
                symbols.back()); //TODO EVENTUALLY REPLACE WITH push_back + reverse
        symbols.pop_back();
    }

    int evaluation = evaluate(n, usedSymbols);

    states.back()->Transition(*this, new Expr(evaluation));
    //TODO lexer->addSymbolToBuffer(s);
}

int Automaton::evaluate(int n, deque<Symbol *> &symbolsToEval) {
    int evaluation;
    if (n == 1) {
        evaluation = ((Integer *) symbolsToEval.front())->getValue();
    } else if (n == 3) {
        if (*symbolsToEval.front() == OPENPAR) {
            symbolsToEval.pop_front();
            evaluation = ((Integer *) symbolsToEval.front())->getValue();
        } else {
            evaluation = ((Integer *) symbolsToEval.front())->getValue();
            symbolsToEval.pop_front();
            if (*symbolsToEval.front() == MULT) {
                symbolsToEval.pop_front();
                evaluation *= ((Integer *) symbolsToEval.front())->getValue();
            } else if (*symbolsToEval.front() == PLUS) {
                symbolsToEval.pop_front();
                evaluation += ((Integer *) symbolsToEval.front())->getValue();
            } else {
                //TODO ERROR
            }
        }
    } else {
        //TODO PRINT DEBUG ERROR
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
        int result = ((Expr *) symbols.back())->getValue();
        cout << "Result: " << result << endl;
        return true;
    }
}
