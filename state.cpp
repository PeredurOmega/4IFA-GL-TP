//
// Created by pauls on 21/01/2022.
//

#include "state.h"

State::State(string name) {
    this->name = std::move(name);
}

State::~State() = default;

bool State0::Transition(Automaton &automaton, Symbol *symbol) {
    switch (*symbol) {
        case EXPR:
            automaton.shift(symbol, new State1());
            break;
        case INT:
            automaton.shift(symbol, new State3());
            break;
        case OPEN_PAR:
            automaton.shift(symbol, new State2());
            break;
        default:
            automaton.shift(new Error(), nullptr);
            return false;
    }
    return true;
}

bool State1::Transition(Automaton &automaton, Symbol *symbol) {
    switch (*symbol) {
        case PLUS:
            automaton.shift(symbol, new State4());
            break;
        case MULTIPLICATION:
            automaton.shift(symbol, new State5());
            break;
        case END:
            return false;
        default:
            automaton.shift(new Error(), nullptr);
            return false;
    }
    return true;
}

bool State2::Transition(Automaton &automaton, Symbol *symbol) {
    switch (*symbol) {
        case INT:
            automaton.shift(symbol, new State3());
            break;
        case OPEN_PAR:
            automaton.shift(symbol, new State2());
            break;
        case EXPR:
            automaton.shift(symbol, new State6());
            break;
        default:
            automaton.shift(new Error(), nullptr);
            return false;
    }
    return true;
}

bool State3::Transition(Automaton &automaton, Symbol *symbol) {
    switch (*symbol) {
        case PLUS:
            automaton.reduction(1, new Plus());
            break;
        case MULTIPLICATION:
            automaton.reduction(1, new Multiplication());
            break;
        case CLOSE_PAR:
            automaton.reduction(1, new ClosePar());
            break;
        case END:
            automaton.reduction(1, new End());
            break;
        default:
            automaton.shift(new Error(), nullptr);
            return false;
    }
    return true;
}

bool State4::Transition(Automaton &automaton, Symbol *symbol) {
    switch (*symbol) {
        case INT:
            automaton.shift(symbol, new State3());
            break;
        case OPEN_PAR:
            automaton.shift(symbol, new State2());
            break;
        case EXPR:
            automaton.shift(symbol, new State7());
            break;
        default:
            automaton.shift(new Error(), nullptr);
            return false;
    }
    return true;
}

bool State5::Transition(Automaton &automaton, Symbol *symbol) {
    switch (*symbol) {
        case INT:
            automaton.shift(symbol, new State3());
            break;
        case OPEN_PAR:
            automaton.shift(symbol, new State2());
            break;
        case EXPR:
            automaton.shift(symbol, new State8());
            break;
        default:
            automaton.shift(new Error(), nullptr);
            return false;
    }
    return true;
}

bool State6::Transition(Automaton &automaton, Symbol *symbol) {
    switch (*symbol) {
        case PLUS:
            automaton.shift(symbol, new State4());
            break;
        case MULTIPLICATION:
            automaton.shift(symbol, new State5());
            break;
        case CLOSE_PAR:
            automaton.shift(symbol, new State9());
            break;
        default:
            automaton.shift(new Error(), nullptr);
            return false;
    }
    return true;
}

bool State7::Transition(Automaton &automaton, Symbol *symbol) {
    switch (*symbol) {
        case PLUS:
            automaton.reduction(3, new Plus());
            break;
        case MULTIPLICATION:
            automaton.shift(symbol, new State5());
            break;
        case CLOSE_PAR:
            automaton.reduction(3, new ClosePar());
            break;
        case END:
            automaton.reduction(3, new End());
            break;
        default:
            automaton.shift(new Error(), nullptr);
            return false;
    }
    return true;
}

bool State8::Transition(Automaton &automaton, Symbol *symbol) {
    switch (*symbol) {
        case PLUS:
            automaton.reduction(3, new Plus());
            break;
        case MULTIPLICATION:
            automaton.reduction(3, new Multiplication());
            break;
        case CLOSE_PAR:
            automaton.reduction(3, new ClosePar());
            break;
        case END:
            automaton.reduction(3, new End());
            break;
        default:
            automaton.shift(new Error(), nullptr);
            return false;
    }
    return true;
}

bool State9::Transition(Automaton &automaton, Symbol *symbol) {
    switch (*symbol) {
        case PLUS:
            automaton.reduction(3, new Plus());
            break;
        case MULTIPLICATION:
            automaton.reduction(3, new Multiplication());
            break;
        case CLOSE_PAR:
            automaton.reduction(3, new ClosePar());
            break;
        case END:
            automaton.reduction(3, new End());
            break;
        default:
            automaton.shift(new Error(), nullptr);
            return false;
    }
    return true;
}