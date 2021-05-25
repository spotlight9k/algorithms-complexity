#ifndef BIGHW1_KARATSUBAMULTIPLICATION_H
#define BIGHW1_KARATSUBAMULTIPLICATION_H

#include "Num.h"
#include "Multiplicator.h"

class karatsubaMultiplication : public Multiplicator {

public:
    karatsubaMultiplication();

    Num multiply(const Num& n1, const Num& n2);

    ~karatsubaMultiplication();

};


#endif //BIGHW1_KARATSUBAMULTIPLICATION_H
