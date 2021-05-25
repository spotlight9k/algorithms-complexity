
#include "divideAndConquer.h"
#include "gradeSchoolMultiplication.h"

divideAndConquer::divideAndConquer(){}

Num divideAndConquer::multiply(const Num& n1, const Num& n2)
{
    if (n1.size == 1 || n2.size == 1)
    {
        gradeSchoolMultiplication t;

        return t.multiply(n1,n2);
    }

    Short m = std::max(n1.size, n2.size);
    Halves a, b;
    a = n1.getHalf(m);
    b = n2.getHalf(m);


    Num x1, x2, x3, x4;
    x1 = multiply(a.second, b.second);
    x2 = multiply(a.first, b.second);
    x3 = multiply(a.second, b.first);
    x4 = multiply(a.first, b.first);



    int t_x2 = x2.getNumber() + x3.getNumber();

    std::string str_t = std::to_string(t_x2);

    Num tk1 = x4.multiplyByPowerOfTen(m);

    Num t_2m (str_t, str_t.size());

    if (m % 2)
    {
        --m;
    }



    Num x5 =  tk1 + (t_2m).multiplyByPowerOfTen(m / 2) + x1;


   // std::cout<<"dac"<<x5.base<<"\n";

    return x5;

}

divideAndConquer::~divideAndConquer(){}