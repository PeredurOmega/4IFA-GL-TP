#include "lexer.h"

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
                default:
                    if (flow[head] <= '9' && flow[head] >= '0') {
                        int result = flow[head] - '0';
                        int i = 1;
                        while (flow[head + i] <= '9' && flow[head + i] >= '0') {
                            result = result * 10 + (flow[head + i] - '0');
                            i++;
                        }
                        head = head + i;
                        buffer = new Integer(result);
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

