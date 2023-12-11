#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"

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

TEST_CASE("Testing shooter throw die class functions")
{
	srand((unsigned) time(NULL));
	Die dice1;
	Die dice2;
	Shooter shooter;
	Roll* roll = shooter.throw_die(dice1,dice2);
	REQUIRE(roll->roll_value() >= 2);
	REQUIRE(roll->roll_value() <= 12);
	for(int i = 0; i < 10; i++)
	{
		roll = shooter.throw_die(dice1,dice2);
		std::cout<<roll->roll_value()<<"\n";
		REQUIRE(roll->roll_value() >= 2);
		REQUIRE(roll->roll_value() <= 12);
	}

}TEST_CASE("Testing ComeOutPhase class")
{
	srand((unsigned) time(NULL));
	ComeOutPhase comeoutphase;
	Die dice1;
	Die dice2;
	Shooter shooter;
	Roll* roll = shooter.throw_die(dice1,dice2);
	for(int i = 0; i < 10; i++)
	{
		roll->roll_die();
		if(roll->roll_value() == 7 || roll->roll_value() == 11)
		{
			REQUIRE(comeoutphase.get_outcome(roll) == RollOutcome::natural);
		}
		else if(roll->roll_value() == 2 || roll->roll_value() == 3 || roll->roll_value() == 12)
		{
			REQUIRE(comeoutphase.get_outcome(roll) == RollOutcome::craps);
		}
		else
		{
			REQUIRE(comeoutphase.get_outcome(roll) == RollOutcome::point);
		}
	}
}

TEST_CASE("Testing PointPhase class")
{
	srand((unsigned) time(NULL));
	PointPhase pointphase(4);
	Die dice1;
	Die dice2;
	Shooter shooter;
	Roll* roll = shooter.throw_die(dice1,dice2);
	for(int i = 0; i < 10; i++)
	{
		roll->roll_die();
		if(roll->roll_value() == 4)
		{
			REQUIRE(pointphase.get_outcome(roll) == RollOutcome::point);
		}
		else if(roll->roll_value() == 7)
		{
			REQUIRE(pointphase.get_outcome(roll) == RollOutcome::seven_out);
		}
		else
		{
			REQUIRE(pointphase.get_outcome(roll) == RollOutcome::nopoint);
		}
	}
}