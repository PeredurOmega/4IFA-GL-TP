#include <iostream>
#include "automaton.h"

/**
 * Main function allowing the use of our Automaton.
 * @return status
 */
int main() {
    string input;

    cout << "Do you want to support negative integers ? Y/N " << endl;
    cin >> input;
    bool negativeIntegersSupport = false;
    if (input == "Y" || input == "y") {
        negativeIntegersSupport = true;
        cout << "Support for negative integers enabled." << endl;
    } else {
        cout << "Support for negative integers disabled." << endl;
    }

    while (true) {
        cout << "Enter an expression to compute or 'stop': " << endl;
        cin >> input;
        if (input == "stop") {
            cout << "Ending the process" << endl;
            break;
        }
        auto *automaton = new Automaton(input, negativeIntegersSupport);
        automaton->run();
        delete (automaton);
    }
    return 0;
}

