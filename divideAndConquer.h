#ifndef BIGHW1_DIVIDEANDCONQUER_H
#define BIGHW1_DIVIDEANDCONQUER_H

#include "Num.h"
#include "Multiplicator.h"

class divideAndConquer : public Multiplicator
        {
public:
    divideAndConquer();

    Num multiply(const Num& n1, const Num& n2);

    ~divideAndConquer();
};





#endif
