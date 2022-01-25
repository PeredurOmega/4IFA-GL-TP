// Created by Paul SOUTEYRAT & Alexandre MARTIN on 21/01/2022.

#include "lexer.h"


Lexer::~Lexer() {
    delete (buffer);
}

Symbol *Lexer::Consult() {
    if (!buffer) {
        if (head == flow.length()) {
            buffer = new End();
        } else {
            switch (flow[head]) {
                case '(':
                    buffer = new OpenPar();
                    head++;
                    break;
                case ')':
                    buffer = new ClosePar();
                    head++;
                    break;
                case '*':
                    buffer = new Multiplication();
                    head++;
                    break;
                case '+':
                    buffer = new Plus();
                    head++;
                    break;
                case ' ':
                    // nullptr is a Space (i.e. a non-used character)
                    buffer = nullptr;
                    head++;
                    break;
                default:
                    /* Experimental support for subtractions (not supporting parenthesis).
                    if (subtractionsSupport && flow[head] == '-' && head > 0 &&
                        flow[head - 1] <= '9' && flow[head - 1] >= '0') {
                        buffer = new Plus();
                        flow.insert(head, "-");
                        head++;
                    } else*/
                    if ((flow[head] <= '9' && flow[head] >= '0') ||
                        (negativeIntegersSupport && flow[head] == '-' &&
                         (head + 1) < flow.size() && flow[head + 1] <= '9' &&
                         flow[head + 1] >= '0')) {
                        // Handling negative integers
                        int sign = 1;
                        if (flow[head] == '-') {
                            head++;
                            sign = -1;
                        }

                        int result = flow[head] - '0';
                        int i = 1;
                        while (flow[head + i] <= '9' && flow[head + i] >= '0') {
                            result = result * 10 + (flow[head + i] - '0');
                            i++;
                        }
                        head = head + i;
                        buffer = new Integer(sign * result);
                    } else {
                        buffer = new Error();
                    }
            }
        }
    }
    return buffer;
}

void Lexer::MoveForward() {
    buffer = nullptr;
}

void Lexer::addSymbolToBuffer(Symbol *s) {
    buffer = s;
}
