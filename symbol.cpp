//
// Created by pauls on 21/01/2022.
//

#include "symbol.h"

void Symbol::Display() const {
    cout << Labels[ident];
}

void Integer::Display() {
    Symbol::Display();
    cout << "(" << value << ")";
}

void Expr::Display() {
    Symbol::Display();
    cout << "(" << value << ")";
}
