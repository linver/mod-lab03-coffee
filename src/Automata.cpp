// Copyright 2022 UNN-IASR
#include <iostream>
#include <string>
#include "Automata.h"

using std::cout;
using std::endl;


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
    }
}

void Automata::off() {
    if (state == WAIT) {
        state = OFF;
        getState();
    }
}

void Automata::coin(int money) {
    if (state == WAIT || state == ACCEPT) {
        state = ACCEPT;
        cash += money;
        getState();
    }
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        state = WAIT;
        cout << "You need more money to buy this drink." << endl;
        getCash();
        getState();
    }
}

void Automata::choice(int menu_position) {
    if (state == ACCEPT) {
        state = CHECK;
        option = menu_position;
        cout << "Your choice is " << menu[option-1] << endl;
        getState();
    }
}

bool Automata::check() {
    if (state == CHECK) {
        if (cash >= prices[option]) {
            return true;
        }
    }
    getState();
    return false;
}

void Automata::cook() {
    if (state == CHECK) {
        state = COOK;
        cash -= prices[option];
        getCash();
        getState();
    }
}

void Automata::finish() {
    if (state == COOK) {
        state = WAIT;
        getCash();
        getState();
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
