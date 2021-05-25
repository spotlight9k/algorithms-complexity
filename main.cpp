#include <iostream>
#include <string>
#include <algorithm>
#include "Experiment.h"
#include "Num.h"
#include "Multiplicator.h"

#include <string>
#include <iostream>



#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
#include <fstream>





int main()
{
    Num::Short k;
    Num::Short step;
    std::string s;

    std::cin>>k>>step>>s;



    std::ofstream out(s);

    Experiment experiment;
    experiment.exp(k,step, out);

}