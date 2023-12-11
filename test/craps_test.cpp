#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Testing die roll class function") 
{
	srand((unsigned) time(NULL));
	Die dice;
	dice.roll();
	REQUIRE(dice.rolled_value() >= 1);
	REQUIRE(dice.rolled_value() <= 6);

	for(int i = 0; i < 10; i++)
	{
		dice.roll();
		std::cout<<dice.rolled_value()<<"\n";
		REQUIRE(dice.rolled_value() >= 1);
		REQUIRE(dice.rolled_value() <= 6);
	}
}

