#include "Experiment.h"
#include <vector>
#include <ctime>
#include <fstream>


Experiment::Experiment(){}
void Experiment::exp(Num::Short k, Num::Short step, std::ofstream& out)
{

    Num n1, n2,n3,n4,n5;

    gradeSchoolMultiplication gsm;
    divideAndConquer dac;
    karatsubaMultiplication kara;



    int avg_t_sch, avg_t_dc, avg_t_kara;

    std::vector  <std::pair<unsigned int,unsigned int>> avr_t_sch;
    std::vector  <std::pair<unsigned int, unsigned int>> avr_t_dc;
    std::vector  <std::pair<unsigned int, unsigned int>> avr_t_kara;


    for (Num::Short i = 0; i < k; i+=step)
    {
        avg_t_sch = 0;
        avg_t_dc = 0;
        avg_t_kara = 0;


            for (int j = 0; j <3; j++)
            {
                Num n1 = n1.createNumber(i);
                Num n2 = n2.createNumber(i);

                unsigned int start_time_sch =  clock();
                n3 = gsm.multiply(n1, n2);
                unsigned int end_time_sch = clock(); // finish time
                unsigned int search_time_sch = end_time_sch - start_time_sch; // overall time
                avg_t_sch += search_time_sch;

                unsigned int start_time_dc =  clock();
                n4 = dac.multiply(n1, n2);
                unsigned int end_time_dc = clock(); // finish time
                unsigned int search_time_dc = end_time_dc - start_time_dc; // overall time
                avg_t_dc += search_time_dc;

                unsigned int start_time_kara =  clock();
                n5 = kara.multiply(n1, n2);
                unsigned int end_time_kara = clock(); // finish time
                unsigned int search_time_kara = end_time_kara - start_time_kara; // overall time
                avg_t_kara += search_time_kara;
            }



        avr_t_sch.push_back(std::make_pair(i, avg_t_sch/3));
        avr_t_dc.push_back(std::make_pair(i, avg_t_dc/3));
        avr_t_kara.push_back(std::make_pair(i, avg_t_kara/3));

        out << i << ", " << avg_t_sch/3;
        out  << ", " << avg_t_dc/3;
        out << ", " << avg_t_kara/3<< "\n";
    }

}

Experiment::~Experiment(){}




