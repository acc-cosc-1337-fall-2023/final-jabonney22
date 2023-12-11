//
#include "roll.h"
#include<memory>
#include<iostream>

#ifndef SHOOTER_H
#define SHOOTER_H

class Shooter
{
    public:
        Roll* throw_die(Die& dice1, Die& dice2);
        friend std::ostream& operator<<(std::ostream& os, const Shooter& shooter);
        ~Shooter();
    private:
        std::vector<Roll*> rolls;
};
#endif
