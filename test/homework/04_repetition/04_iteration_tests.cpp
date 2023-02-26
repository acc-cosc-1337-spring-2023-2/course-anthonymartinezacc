#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
//#include "main.cpp"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test to get the factorial of 3", "Test if our factorial code gives the correct output") {
	REQUIRE(factorial(3) == 6);
}

TEST_CASE("Test to get the factorial of 5", "Test if our factorial code gives the correct output") {
	REQUIRE(factorial(5) == 120);
}

TEST_CASE("Test to get the factorial of 3", "Test if our factorial code gives the correct output") {
	REQUIRE(factorial(6) == 720);
}

TEST_CASE("Test to get the gcd of 5 & 15", "Test if our gcd code gives the correct output") {
	REQUIRE(factorial(5,15) == 5);
}

TEST_CASE("Test to get the gcd of 21 & 28", "Test if our gcd code gives the correct output") {
	REQUIRE(factorial(21,28) == 7);
}

TEST_CASE("Test to get the gcd of 5 & 15", "Test if our gcd code gives the correct output") {
	REQUIRE(factorial(25,100) == 25);
}
