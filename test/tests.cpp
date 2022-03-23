// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include <stdexcept>
#include "Automata.h"

using std::invalid_argument;
using std::domain_error;

TEST(test1, incorrect_operation) {
    Automata drinking_m;
    drinking_m.state = CHECK;
    try {
        drinking_m.on();
    }
    catch(domain_error& err) {
        ASSERT_STREQ("Error! Incorrect operation.", err.what());
    }
}

TEST(test2, incorrect_operation) {
    Automata drinking_m;
    drinking_m.state = CHECK;
    try {
        drinking_m.off();
    }
    catch(domain_error& err) {
        ASSERT_STREQ("Error! Incorrect operation.", err.what());
    }
}

TEST(test3, incorrect_operation) {
    Automata drinking_m;
    drinking_m.state = OFF;
    try {
        drinking_m.coin(100);
    }
    catch(domain_error& err) {
        ASSERT_STREQ("Error! Incorrect operation.", err.what());
    }
}

TEST(test4, incorrect_operation) {
    Automata drinking_m;
    drinking_m.state = WAIT;
    try {
        drinking_m.cancel();
    }
    catch(domain_error& err) {
        ASSERT_STREQ("Error! Incorrect operation.", err.what());
    }
}

TEST(test5, incorrect_operation) {
    Automata drinking_m;
    drinking_m.state = WAIT;
    try {
        drinking_m.choice(3);
    }
    catch(domain_error& err) {
        ASSERT_STREQ("Error! Incorrect operation.", err.what());
    }
}

TEST(test6, incorrect_operation) {
    Automata drinking_m;
    drinking_m.state = ACCEPT;
    try {
        drinking_m.check();
    }
    catch(domain_error& err) {
        ASSERT_STREQ("Error! Incorrect operation.", err.what());
    }
}

TEST(test7, incorrect_operation) {
    Automata drinking_m;
    drinking_m.state = OFF;
    try {
        drinking_m.cook();
    }
    catch(domain_error& err) {
        ASSERT_STREQ("Error! Incorrect operation.", err.what());
    }
}

TEST(test8, incorrect_operation) {
    Automata drinking_m;
    drinking_m.state = CHECK;
    try {
        drinking_m.finish();
    }
    catch(domain_error& err) {
        ASSERT_STREQ("Error! Incorrect operation.", err.what());
    }
}

TEST(test9, incorrect_value) {
    Automata drinking_m;
    drinking_m.state = ACCEPT;
    try {
        drinking_m.coin(-500);
    }
    catch(invalid_argument& err) {
        ASSERT_STREQ("Error! Incorrect value.", err.what());
    }
}

TEST(test10, incorrect_value) {
    Automata drinking_machine;
    drinking_machine.on();
    drinking_machine.coin(1000);
    try {
        drinking_machine.choice(15);
    }
    catch(invalid_argument& err) {
        ASSERT_STREQ("Error! Incorrect value.", err.what());
    }
}

TEST(test11, TrueOrFalse) {
    Automata drinking_machine;
    drinking_machine.on();
    drinking_machine.coin(1000);
    drinking_machine.choice(5);
    EXPECT_EQ(true, drinking_machine.check());
}

TEST(test12, TrueOrFalse) {
    Automata drinking_machine;
    drinking_machine.on();
    drinking_machine.coin(10);
    drinking_machine.choice(5);
    EXPECT_EQ(false, drinking_machine.check());
}

int main1() {
    Automata drinking_machine;
    drinking_machine.on();
    drinking_machine.coin(1000);
    drinking_machine.choice(5);
    if (drinking_machine.check()) {
        drinking_machine.cook();
        drinking_machine.finish();
    } else {
        drinking_machine.cancel();
    }
    drinking_machine.off();
    return 0;
}

TEST(test12, all_checks) {
    EXPECT_EQ(0, main1());
}
