//
#include "die.h"
#include<stdlib.h>

void Die::roll()
{
    int die = (rand()%6);
    roll_value = sides[die];
}


