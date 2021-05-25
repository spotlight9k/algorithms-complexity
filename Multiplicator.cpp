#include "Multiplicator.h"
#include <random>
#include <algorithm>

typedef unsigned short Short;
typedef unsigned int Byte;
typedef std::pair<Num, Num> Halves;
typedef std::vector<Num> Nums;


Multiplicator::Multiplicator(){}


Multiplicator::Byte Multiplicator::baseAdd(Byte d1, Byte d2, Byte& carry) // add two digits
{
    Byte sum = (d1 + d2) + carry;
    carry = (Byte) (sum / 10);
    return (Byte) (sum % 10);
}

Multiplicator::Byte Multiplicator::baseSubstraction(Byte d1, Byte d2, Byte& carry) // substraction of digits d1 and d2
{
    Byte sub = 0;
    if (d1 - carry < d2 || (d1 == 0 && carry == 1))
    {
        sub = (10 - d2 + d1) - carry;
        carry = 1;
    }
    else
    {
        sub = d1 - d2 - carry;
        carry = 0;
    }
    return sub;
}

Multiplicator::~Multiplicator(){}



