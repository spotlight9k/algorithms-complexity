#ifndef BIGHW1_MULTIPLICATOR_H
#define BIGHW1_MULTIPLICATOR_H

#include "Num.h"
#include <vector>


class Multiplicator
{
public:

    Multiplicator();
    ~Multiplicator();

    typedef unsigned short Short;
    typedef unsigned int Byte;
    typedef std::pair<Num, Num> Halves;
    typedef std::vector<Num> Nums;

    virtual Num multiply(const Num& n1, const Num& n2) = 0;

    static Byte baseAdd(Byte, Byte, Byte&);                                 // add two digits
    static Byte baseSubstraction(Byte d1, Byte d2, Byte& carry);

};


#endif //BIGHW1_MULTIPLICATOR_H
