#include "gradeSchoolMultiplication.h"

#include <string>
#include <iostream>
#include <algorithm>
#include <random>



gradeSchoolMultiplication :: gradeSchoolMultiplication(){}

Num gradeSchoolMultiplication :: multiply(const Num& n1, const Num& n2)
{
    int basis = 10;
    //Num result = n1.createNumber((n1.size  + n2.size));

    Num result = result.createNumber(n1.getSize()  + n2.getSize());

    int total = 0; //Byte

   // std::cout<<"s1 "<<n1.size + n2.size<<" "<<n1.getSize()  + n2.getSize()<<"\n";

    for (int i = 0; i <= n1.getSize() + n2.getSize() - 2 ; i++)
    {

        for (int j = std::max(0, i - n1.getSize() + 1); j <= std::min(i, n2.getSize() - 1); j++)
        {
            int n2_dig = i - j;

            total += (n1.getDigit(n1.getSize() - n2_dig - 1) * n2.getDigit(n2.getSize() - j - 1));
        }

        result.setDigit(i, (total % basis));
        total /= basis;

    }
    result.setDigit(n1.getSize() + n2.getSize()-1, (total % basis));

    std::reverse(result.base.begin(), result.base.end());
    if (result.base.find("0") == 0)
    {
        result.base = result.base.substr(1);
        result.size = result.size -1;
    }

  //  std::cout<<"dgs"<<result.base<<"\n";
    return result;


};

gradeSchoolMultiplication :: ~gradeSchoolMultiplication(){};