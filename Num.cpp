#include "Num.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <random>
#include "Multiplicator.h"
#include <stdlib.h>

using namespace std;

typedef unsigned short Short;
typedef unsigned int Byte;
typedef std::pair<Num, Num> Halves;

//Short size;
//std::string base;

Num:: Num() : size(0), base("") {}                // default constructor
Num:: ~Num() {}                                  // default destructor
Num::Num(Num::Short length, Byte dig)                    // constructor that create a number of a given length consisting of a certain digit
{
    size = length;
    base.append(length, (char) dig + 48);
}
Num::Num(std::string& str, Short k)                      // constructor that create number using a string
{
    size = k;
    base = str;
}

Short Num::getSize() const
{
    return base.size();
}

Byte Num::getDigit(Short k) const
{
    if (k < Num::getSize() && k >= 0)
        return (Byte) (base[k] - 48);
    return 0;
}

void Num::setDigit(Short k, Byte dig)
{
    size = k;
    base[k] = (char) dig + 48;
}


Short Num::getNumber()
{
    return std::atoi(base.c_str());
}

Halves Num::getHalf(Short length)    const  // separate number to halves and reсturn them as a pair of numbers
{
    Short k = length / 2;
    Halves pair;
    std::string s1, s2;
    if (length % 2)
    {
        for (Short i = 0; i < k; ++i)
            s1 += (Num::getDigit(i) + '0');
        for (Short i = k; i <= 2 * k; ++i)
            if (i < getSize())
            {
                s2 += (Num::getDigit(i) + '0');
            }


        pair = {Num(s1, s1.length()), Num(s2,s2.length())};

    }
    else
    {
        for (Short i = 0; i < k; ++i)
            s1 += (Num::getDigit(i) + '0');
        for (Short i = k; i < 2 * k; ++i)
            if (i < getSize())
            {
                s2 += (Num::getDigit(i) + '0');
            }


        pair = {Num(s1, s1.length()), Num(s2, s2.length())};
    }
    return pair;
}


Num Num::multiplyByPowerOfTen(Short length) const // function of multiplication a number by certain power of ten
{
    Num res;
    res.base = base;
    res.base.append(length, '0');
    res.size = res.getSize();
    return res;
}
Num Num::operator+(const Num& n2)
{
    Short m = std::max(getSize(), n2.getSize());


//    std::cout<<"s1 "<<size<<"\n";
//    std::cout<<"s2 "<<n2.size<<"\n";
//    std::cout<<"m "<<m<<"\n";


    Num result(m + 1, 1);
  //  std::cout<<"rs "<<result.size<<"\n";

    Byte carry = 0;
    for (int i = 0; i <= m-1; i++)
    {


        Byte dig = Multiplicator::baseAdd(this->getDigit(getSize() - i-1), n2.getDigit(n2.getSize() - i-1), carry);

        result.setDigit(i, dig);

    }

    result.setDigit(m, carry);
    // delereZeros(result);


    std::reverse(result.base.begin(), result.base.end());

    if (result.base.find("0") == 0)
    {
        result.base = result.base.substr(1);
        result.size = result.size -1;
    }


    return result;
}


Num Num::createNumber(Short k)
{

    std::random_device rd;
    std::mt19937 gen(rd());

//    int gn = rand()%10;
//
//    int gn1 = rand()%9 + 1;

    std::string a;
    if (k == 1)
    {
        std::uniform_int_distribution<> d2(0, 9);
        a.push_back(static_cast<char>(48 + d2(gen)));
    }
    else
    {
        std::uniform_int_distribution<> d1(1, 9);
        std::uniform_int_distribution<> d2(0, 9);
        for (int i = 0; i < k - 1; ++i)
        {
            a.push_back(static_cast<char>(48 + d1(gen)));
        }
        a.push_back(static_cast<char>(48 + d2(gen)));
    }
    Num number(a, k);

   // std::cout<<"nwrw"<<number.base<<"\n";
    return number;
}



void Num::delereZeros(Num& number) // delete insignificant zeros
{
    Num::Short k = number.getSize();
    while (number.getDigit(k - 1) == 0)
    {
        if ((k == 1 && number.base == "0") || (number.base == "" && k == 0))
            break;
        number.base.erase(k - 1);
        --k;
    }
    number.size = number.base.size();
}

Num  Num::operator-(const Num& n2)
{
    Short m = std::max(size, n2.size);
    Num result(m, 0);
    Byte carry = 0;
    for (Short i = 0; i < m; ++i)
    {
        Byte dig = Multiplicator::baseSubstraction(getDigit(i), n2.getDigit(i), carry);
        result.setDigit(i, dig);
    }
    delereZeros(result);
    return result;
};

// substract one number from another
void Num::operator=(const Num& number)
{
    size = number.size;
    base = number.base;
}

std::ostream& Num::operator<<(std::ostream& s)       // output a number
{
    Num number = *this;
    Num::Short k = number.getSize();
    while (number.getDigit(k - 1) == 0)
    {
        if  ((k == 1 && number.base == "0") || (number.base == "" && k == 0))       //
            break;
        number.base.erase(k - 1);
        --k;
    }
    std::reverse(number.base.begin(), number.base.end());
    s << number.base;
    return s;

}




