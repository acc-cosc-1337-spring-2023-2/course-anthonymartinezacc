#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "func.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test the get_gc_content function", "Test if our code gives the correct output") {
	REQUIRE(get_gc_content("AGCTATAG") == .375);
}

TEST_CASE("Test the get_gc_content function", "Test if our code gives the correct output") {
	REQUIRE(get_gc_content("CGCTATAG") == .50);
}

TEST_CASE("Test the reverse_string function", "Test if our code gives the correct output") {
	REQUIRE(reverse_string("AGCTATAG") == "GATATCGA");
}

TEST_CASE("Test the reverse_string function", "Test if our code gives the correct output") {
	REQUIRE(reverse_string("CGCTATAG") == "GATATCGC");
}

TEST_CASE("Test the get_dna_complement function", "Test if our code gives the correct output") {
	REQUIRE(get_dna_complement("AAAACCCGGT") == "ACCGGGTTTT");
}

TEST_CASE("Test the get_dna_complement function", "Test if our code gives the correct output") {
	REQUIRE(get_dna_complement("CCCGGAAAAT") == "ATTTTCCGGG");
}
