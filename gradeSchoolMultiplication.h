#ifndef BIGHW1_GRADESCHOOLMULTIPLICATION_H
#define BIGHW1_GRADESCHOOLMULTIPLICATION_H

#include "Num.h"
#include "Multiplicator.h"

class gradeSchoolMultiplication : public Multiplicator
        {
public:
    gradeSchoolMultiplication();

    Num multiply(const Num& n1, const Num& n2);

    ~gradeSchoolMultiplication();
};


#endif
