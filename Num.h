#ifndef BIGHW1_NUM_H
#define BIGHW1_NUM_H

#include <string>
#include <iostream>


using namespace std;


class Num
{
public:


    typedef unsigned short Short;
    typedef unsigned int Byte;
    typedef std::pair<Num, Num> Halves;

    Short size;
    std::string base;

    Num();                                    // default constructor
    ~Num() ;                                   // default destructor
    Num(Short length, Byte dig);                // constructor that create a number of a given length consisting of a certain digit
    Num(std::string& str, Short k);             // constructor that create number using a string

    Short getSize() const;
    Byte getDigit(Short k) const;
    void setDigit(Short k, Byte dig);
    Num createNumber(Short k);
    void delereZeros(Num&);
    Short getNumber();
    Halves getHalf(Short length) const;                 // separate number to halves and reсturn them as a pair of numbers
    Num multiplyByPowerOfTen(Short length) const;

    Num operator+(const Num& n2);                // add two numbers
    Num operator-(const Num& n2);                 // function of multiplication a number by certain power of ten
    void operator=(const Num&);
    std::ostream& operator<<(std::ostream& s);          // output a number



};


#endif
