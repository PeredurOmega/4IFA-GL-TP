#include <iostream>
#include "automaton.h"


int main() {
    string input;

    while (true) {
        cout << "Enter an expression to compute or 'stop': " << endl;
        cin >> input;
        if (input == "stop") {
            cout << "Ending the process" << endl;
            break;
        }
        auto *automaton = new Automaton(input);
        automaton->run();
    }

    return 0;
}

