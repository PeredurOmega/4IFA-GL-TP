//
// Created by pauls on 21/01/2022.
//

#ifndef TP_4IFA_GL_STATE_H
#define TP_4IFA_GL_STATE_H

#pragma once

#include "symbol.h"
#include "automaton.h"

class State {
public:
    State(string name);

    ~State();

    virtual bool Transition(Automaton &automate, Symbol *symbol) = 0;

protected:
    string name;
};

class State0 : public State {
public:
    State0() : State("I0") {};

    bool Transition(Automaton &automate, Symbol *symbol) override;
};

class State1 : public State {
public:
    State1() : State("I1") {};

    bool Transition(Automaton &automate, Symbol *symbol) override;
};

class State2 : public State {
public:
    State2() : State("I2") {};

    bool Transition(Automaton &automate, Symbol *symbol) override;
};

class State3 : public State {
public:
    State3() : State("I3") {};

    bool Transition(Automaton &automate, Symbol *symbol) override;
};

class State4 : public State {
public:
    State4() : State("I4") {};

    bool Transition(Automaton &automate, Symbol *symbol) override;
};

class State5 : public State {
public:
    State5() : State("I5") {};

    bool Transition(Automaton &automate, Symbol *symbol) override;
};

class State6 : public State {
public:
    State6() : State("I6") {};

    bool Transition(Automaton &automate, Symbol *symbol) override;
};

class State7 : public State {
public:
    State7() : State("I7") {};

    bool Transition(Automaton &automate, Symbol *symbol) override;
};

class State8 : public State {
public:
    State8() : State("I8") {};

    bool Transition(Automaton &automate, Symbol *symbol) override;
};

class State9 : public State {
public:
    State9() : State("I9") {};

    bool Transition(Automaton &automate, Symbol *symbol) override;
};

#endif //TP_4IFA_GL_STATE_H
