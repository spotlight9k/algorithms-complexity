#ifndef BIGHW1_EXPERIMENT_H
#define BIGHW1_EXPERIMENT_H

#include "Multiplicator.h"
#include "karatsubaMultiplication.h"
#include "gradeSchoolMultiplication.h"
#include "divideAndConquer.h"
#include <vector>

class Experiment
{
public:
    Experiment();
    ~Experiment();

    void exp(Num::Short k, Num::Short step, std::ofstream& out);
};


#endif