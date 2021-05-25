#include "karatsubaMultiplication.h"
#include "gradeSchoolMultiplication.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <random>

karatsubaMultiplication :: karatsubaMultiplication(){}

Num karatsubaMultiplication :: multiply(const Num& n1, const Num& n2)
{
    Short m = std::max(n1.getSize(), n2.getSize());
    if (n1.getSize() == 1 || n2.getSize()== 1)
    {
        gradeSchoolMultiplication t;
        return t.multiply(n1, n2);
    }

    Halves a, b;
    a = n1.getHalf(m);
    b = n2.getHalf(m);

    Num x1, x2, x3;
    x1 = karatsubaMultiplication ::multiply(a.first, b.first);
    Num a_a;
    int per = a.first.getNumber() + a.second.getNumber();
    a_a.size = (a.first + a.second).getSize();
    a_a.base = std::to_string(per);

    Num b_b;
    int per1 = b.first.getNumber() + b.second.getNumber();
    b_b.size = (b.first + b.second).getSize();
    b_b.base = std::to_string(per1);

    x2 = karatsubaMultiplication ::multiply(a.first + a.second, b.first + b.second);
    x3 = karatsubaMultiplication ::multiply(a.second, b.second);

    int t_x2 = x2.getNumber() - x1.getNumber() - x3.getNumber();

    std::string str_t = std::to_string(t_x2);


    Num tk1 = x1.multiplyByPowerOfTen(m);
    Num t_2m (str_t, str_t.size());

    if (m % 2)
    {
        --m;
    }

    Num tk2 = t_2m.multiplyByPowerOfTen(m/2);

    Num x4 =  tk1 + (t_2m).multiplyByPowerOfTen(m / 2) + x3;

    return x4;
}

karatsubaMultiplication :: ~karatsubaMultiplication(){}

