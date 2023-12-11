//
#include "shooter.h"

Roll* Shooter::throw_die(Die& dice1, Die& dice2)
{
    Roll* roll = new Roll(dice1,dice2);
    roll->roll_die();
    rolls.push_back(roll);
    return roll;
}


std::ostream& operator<<(std::ostream& os, const Shooter& shooter)
{
    for(const auto& roll : shooter.rolls)
    {
        os <<"Rolled Value: "<<roll->roll_value()<<"\n"<<std::endl;
    }
}

Shooter::~Shooter()
{
    for(auto& roll : rolls)
    {
        delete roll;
    }
    rolls.clear();
}