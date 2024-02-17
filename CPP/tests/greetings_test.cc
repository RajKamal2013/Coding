#include <gtest/gtest.h>
#include "src/lib/greetings.h"

TEST(GreetingShould, ReturnHelloWorld){
    Greeting *greet = new Greeting();
    std::string actual = greet->getGreetingMessage();
    std::string expected = "Hello World!";
    EXPECT_EQ(expected, actual);
}