// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include <stdexcept>
#include <iostream>
#include <string>
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

TEST(test10, states) {
    Automata drinking_m;
    drinking_m.on()
    EXPECT_EQ(WAIT, drinking_m.state);
}

TEST(test11, states) {
    Automata drinking_m;
    drinking_m.on()
    drinking_machine.coin(1000);
    EXPECT_EQ(ACCEPT, drinking_m.state);
}

TEST(test12, states) {
    Automata drinking_m;
    drinking_m.on()
    drinking_machine.coin(1000);
    drinking_machine.choice(5); 
    EXPECT_EQ(CHECK, drinking_m.state);
}

TEST(test13, states) {
    Automata drinking_m;
    drinking_m.on()
    drinking_machine.coin(1000);
    drinking_machine.choice(5);
    drinking_machine.cook();
    EXPECT_EQ(COOK, drinking_m.state);
}

TEST(test13, states) {
    Automata drinking_m;
    drinking_m.on()
    drinking_machine.coin(1000);
    drinking_machine.choice(5);
    drinking_machine.cook();
    drinking_machine.finish();
    EXPECT_EQ(WAIT, drinking_m.state);
}

TEST(test14, states) {
    Automata drinking_m;
    drinking_m.on()
    drinking_machine.coin(10);
    drinking_machine.choice(5);
    drinking_machine.cancel()
    EXPECT_EQ(WAIT, drinking_m.state);
}

TEST(test15, states) {
    Automata drinking_m;
    drinking_m.on()
    drinking_machine.coin(1000);
    drinking_machine.choice(5);
    drinking_machine.cook();
    drinking_machine.finish();
    rinking_machine.off();
    EXPECT_EQ(OFF, drinking_m.state);
}