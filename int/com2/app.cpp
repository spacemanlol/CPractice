#include <iostream>
#include "parser.h"
#include "processor.h"



int main()
{
       long double lati = 53.3498;
       long double lon = -6.2603;
       long double alti = 6.096;
       long double X = 0.0;
       long double Y = 0.0;
       long double Z = 0.0;
//       std::cout << X <<", " << Y << ", " << Z << std::endl;
       
       Parser p("SciTec_code_problem_data.csv");
//       std::vector<LLAData> data = p.ParseToLLA();
       LLA_ECEFUtility  utility;
       utility.set_LLAData(p.ParseToLLA());
       utility.convertLLADataToECEFVelocity();

       ECEFVelocity v  = utility.getVelocity(1532334559.04 );
       ECEFVelocity v1 = utility.getVelocity(1532334562.54 );
       ECEFVelocity v2 = utility.getVelocity(1532334570.64 );
       ECEFVelocity v3 = utility.getVelocity(1532334000.00 );
       ECEFVelocity v4 = utility.getVelocity(1532335268.00 );
       v.Print();
       v1.Print();
       v2.Print();
       
       return 0;
}

