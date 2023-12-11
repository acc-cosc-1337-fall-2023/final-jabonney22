#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"

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

TEST_CASE("Testing roll roll class functions") 
{
	srand((unsigned) time(NULL));
	Die dice1;
	Die dice2;
	Roll roll(dice1,dice2);
	roll.roll_die();
	REQUIRE(roll.roll_value() >= 2);
	REQUIRE(roll.roll_value() <= 12);

	for(int i = 0; i < 10; i++)
	{
		roll.roll_die();
		std::cout<<roll.roll_value()<<"\n";
		REQUIRE(roll.roll_value() >= 2);
		REQUIRE(roll.roll_value() <= 12);
	}
}