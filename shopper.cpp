/*
  Name: Junyue Lu
  File name: shopper.cpp
*/

#include "shopper.h"

// produces random #s between 0 and 1
std::default_random_engine generator;
// converts those to equally-likely ints between 1 and 10
std::uniform_int_distribution<int> distribution(1,10);


Shopper::Shopper()
{
    loyalty = distribution(generator);
    cartSize = distribution(generator);
    priority = 0;
}

Shopper::Shopper(int random) {
    priority = random;
    loyalty = distribution(generator);
    cartSize = distribution(generator);
}



bool operator<(const Shopper &left, const Shopper &right)
{
    return left.priority < right.priority;
}


bool operator>(const Shopper &left, const Shopper &right)
{
    return left.priority > right.priority;
}

/*
Shopper Shopper::operator=(const Shopper &right)
{
    cartSize=right.cartSize;
    loyalty=right.loyalty;
    priority=right.priority;
    return *this;
}
*/
