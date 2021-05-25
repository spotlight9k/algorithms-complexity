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

    //   std::cout<<"gsm ="<<t.multiply(n1, n2).base<<"\n";
        return t.multiply(n1, n2); // фвф

    }

    Halves a, b;
    a = n1.getHalf(m);
    b = n2.getHalf(m);

//    std::cout<<"a1 ="<<a.first.base<<"\n";
//    std::cout<<"a2 ="<<a.second.base<<"\n";
//    std::cout<<"b1 ="<<b.first.base<<"\n";
//    std::cout<<"b2 ="<<b.second.base<<"\n";


    Num x1, x2, x3;
    x1 = karatsubaMultiplication ::multiply(a.first, b.first); //фывфв
    Num a_a;
    int per = a.first.getNumber() + a.second.getNumber();
    a_a.size = (a.first + a.second).getSize();
    a_a.base = std::to_string(per);

    Num b_b;
    int per1 = b.first.getNumber() + b.second.getNumber();
    b_b.size = (b.first + b.second).getSize();
    b_b.base = std::to_string(per1);

//    std::cout<<"aa ="<<a_a.base<<"\n";
//    std::cout<<"bb ="<<b_b.base<<"\n";
//
//    std::cout<<"as ="<<a_a.size<<"\n";
//    std::cout<<"bs ="<<b_b.size<<"\n";




    x2 = karatsubaMultiplication ::multiply(a.first + a.second, b.first + b.second); //фвфв
    x3 = karatsubaMultiplication ::multiply(a.second, b.second);

//    std::cout<<"x1j ="<<x1.base<<"\n";
//    std::cout<<"x2j ="<<x2.base<<"\n";
//    std::cout<<"x3j ="<<x3.base<<"\n";



    int t_x2 = x2.getNumber() - x1.getNumber() - x3.getNumber();

    std::string str_t = std::to_string(t_x2);


    Num tk1 = x1.multiplyByPowerOfTen(m);

    Num t_2m (str_t, str_t.size());

    if (m % 2)
    {
        --m;
    }

    Num tk2 = t_2m.multiplyByPowerOfTen(m/2);

    Num x4 =  tk1 + (t_2m).multiplyByPowerOfTen(m / 2) + x3;  //tk2

  //  std::cout<<"x4j ="<<x4.base<<"\n";

    return x4; //x4
}

karatsubaMultiplication :: ~karatsubaMultiplication(){}

