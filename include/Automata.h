// Copyright 2022 UNN-IASR
#pragma once
#include <iostream>
#include <string>

enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK};

using std::string;

class Automata {
 public:
        STATES state;  // - текущее состояние автомата
        int cash;  // - для хранения текущей суммы
        const string menu[10] = {
            "Espresso",
            "Americano",
            "Cappuccino",
            "Latte",
            "FlatWhite",
            "Macchiato",
            "BlackTea",
            "GreenTea",
            "Cacao",
            "HotChocolate"
        };
        int option;  // - выбор напитка
        const int prices[10] = {
            80, 100, 150, 180, 160, 190, 120, 120, 140, 170
            };

 public:
        Automata();
        void on();  // - включение автомата
        void off();  // - выключение автомата
        void coin(int x);  // - занесение денег на счёт пользователем
        void getMenu();  // - считывание меню
        void getState();  // - считывание текущего состояния для пользователя
        void choice(int x);  // - выбор напитка пользователем
        bool check();  // - проверка наличия необходимой суммы
        int getCash();  // - возвращает сдачу/деньги
        void cancel();  // - отмена сеанса обслуживания пользователем
        void cook();  // - имитация процесса приготовления напитка
        void finish();  // - завершение обслуживания пользователя
};
