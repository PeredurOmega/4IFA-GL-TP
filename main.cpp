#include <iostream>
#include "automaton.h"


int main() {
    string input;
    bool retry;

    do {
        cout << "Enter an expression to compute: " << endl;
        cin >> input;
        auto *automaton = new Automaton(input);
        retry = !(automaton->run());
    } while (retry);

    return 0;
}

