//
#include<iostream>
#include<vector>
 
#ifndef DIE_H
#define DIE_H

class Die {

public:

void roll();
int rolled_value() const;

private:
int roll_value;
std::vector<int> sides = {1,2,3,4,5,6};
};
 


#endif