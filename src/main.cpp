#include <iostream>
#include <string>
#include "Automata.h"

using namespace std;


int main()
{
    Automata drinking_machine;
    drinking_machine.on();
    drinking_machine.coin(1000);
    drinking_machine.choice(5); // соответствует выбору FlatWhite
    if (drinking_machine.check()) {
        drinking_machine.cook();
        drinking_machine.finish();
    } else {
        drinking_machine.cancel();
    }
    drinking_machine.off();
    return 0;
}