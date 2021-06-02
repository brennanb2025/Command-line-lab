#define CATCH_CONFIG_MAIN
#include "catch.hpp"
// Include the cpp file we're testing
#include "arghandler.cpp"


// One Argument Unit Tests
TEST_CASE("One Argument - Odd", "[classic]") {
    GIVEN("One Argument - Odd"){
        const char *args[3] = { "test", "5", NULL};
        CHECK( oneArgument(const_cast<char**>(args)) == "Odd");
    }
}
TEST_CASE("One Argument - Even", "[classic]") {
    GIVEN("One Argument - Even"){
        const char *args[3] = { "test", "1232323232323232323232", NULL};
        CHECK( oneArgument(const_cast<char**>(args)) == "Even");
    }
}
TEST_CASE("One Argument - Zero", "[classic]") {
    GIVEN("One Argument - Zero"){
        const char *args[3] = { "test", "0", NULL};
        CHECK( oneArgument(const_cast<char**>(args)) == "Zero");
    }
}
TEST_CASE("One Argument - many zeroes", "[classic]") {
    GIVEN("One Argument - many zeroes"){
        const char *args[3] = { "test", "0000000000000", NULL};
        CHECK( oneArgument(const_cast<char**>(args)) == "Zero");
    }
}
TEST_CASE("One Argument - Not An Integer", "[classic]") {
    GIVEN("One Argument - Not An Integer"){
        const char *args[3] = { "test", "Whats up", NULL};
        CHECK( oneArgument(const_cast<char**>(args)) == "Not An Integer");
    }
}

// >1 Argument Unit Tests
TEST_CASE(">1 argument - 0", "[classic]") {
    GIVEN("One Argument - 0"){
        const int argc = 2;
        const char *args[3] = { "test", "None here!", NULL};
        CHECK( multiArguments(argc, const_cast<char**>(args)) == 0);
    }
}
TEST_CASE(">1 argument - 1", "[classic]") {
    GIVEN("One Argument - 1"){
        const int argc = 3;
        const char *args[3] = { "test", "One c here!", NULL};
        CHECK( multiArguments(argc, const_cast<char**>(args)) == 1);
    }
}
TEST_CASE(">1 argument - 4", "[classic]") {
    GIVEN("One Argument - 4"){
        const int argc = 7;
        const char *args[3] = { "test", "4x upper()ase and lower()ase: cC C c", NULL};
        CHECK( multiArguments(argc, const_cast<char**>(args)) == 4);
    }
}