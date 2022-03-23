// Copyright 2022 UNN-IASR
#include <iostream>
#include <string>
#include <stdexcept>
#include "Automata.h"

using std::cout;
using std::endl;
using std::invalid_argument;
using std::domain_error;

Automata::Automata() {
    state = OFF;
    cash = 0;
    option = 0;
    getState();
}

void Automata::getMenu() {
    for (int i = 0; i < 10; i++) {
        cout << i+1 << ": "<< menu[i] << " - " << prices[i] << endl;
    }
}

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        cout << "The drink machine is on." << endl;
        getMenu();
        getState();
    } else {
        throw domain_error("Error! Incorrect operation.");
    }
}

void Automata::off() {
    if (state == WAIT) {
        state = OFF;
        getState();
    } else {
        throw domain_error("Error! Incorrect operation.");
    }
}

void Automata::coin(int money) {
    if (state == WAIT || state == ACCEPT) {
        if (money < 0) {
            throw invalid_argument("Error! Incorrect value.");
        }
        state = ACCEPT;
        cash += money;
        getState();
    } else {
        throw domain_error("Error! Incorrect operation.");
    }
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        state = WAIT;
        cout << "You need more money to buy this drink." << endl;
        getCash();
        getState();
    } else {
        throw domain_error("Error! Incorrect operation.");
    }
}

void Automata::choice(int menu_position) {
    if (state == ACCEPT) {
        if (sizeof(menu) < menu_position || menu_position <= 0) {
            throw invalid_argument("Error! Incorrect value.");
        }
        state = CHECK;
        option = menu_position;
        cout << "Your choice is " << menu[option-1] << endl;
        getState();
    } else {
        throw domain_error("Error! Incorrect operation.");
    }
}

bool Automata::check() {
    if (state == CHECK) {
        if (cash >= prices[option]) {
            return true;
        }
        getState();
        return false;
    } else {
        throw domain_error("Error! Incorrect operation.");
    }
}

void Automata::cook() {
    if (state == CHECK) {
        state = COOK;
        cash -= prices[option];
        getCash();
        getState();
    } else {
        throw domain_error("Error! Incorrect operation.");
    }
}

void Automata::finish() {
    if (state == COOK) {
        state = WAIT;
        getCash();
        getState();
    } else {
        throw domain_error("Error! Incorrect operation.");
    }
}

int Automata::getCash() {
    cout << "Your cash is " << cash << endl;
    return cash;
}

void Automata::getState() {
    switch (state) {
        case OFF:
            cout << "The drink machine is off." << endl;
            break;

        case WAIT:
            cout << "The drink machine is waiting for your action." << endl;
            break;

        case ACCEPT:
            cout << "Give money, please." << endl;
            break;

        case CHECK:
            cout << "Checking your balance..." << endl;
            break;
        case COOK:
            cout << "Making your drink..."<< endl;
            break;
    }
}

