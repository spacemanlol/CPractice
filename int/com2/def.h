#ifndef DEF_H
#define DEF_H

#define PRECISION 24

#include <iostream>
#include <iomanip>


struct LLAData
{
   long double time_epoch;
   long double latitude;
   long double longitude;
   long double altitude;

   void Print()
   {
     std::cout << std::fixed << std::setprecision(PRECISION);
     std::cout << std::setw(PRECISION) << time_epoch <<", " <<  std::setw(PRECISION) << latitude << ", " << std::setw(PRECISION) << longitude << ", " <<  std::setw(PRECISION) << altitude << std::endl;
   }
};

struct ECEFData
{
   long double time_epoch;
   long double X;
   long double Y;
   long double Z;

   void Print()
   {
     std::cout << std::fixed << std::setprecision(PRECISION);
     std::cout << std::setw(PRECISION) << time_epoch <<", " <<  std::setw(PRECISION) << X << ", " << std::setw(PRECISION) << Y << ", " <<  std::setw(PRECISION) << Z << std::endl;
   }
};

struct ECEFVelocity
{
   long double Xv;
   long double Yv;
   long double Zv;
   long double T_epoch;   

   void Print()
   {
     std::cout << std::fixed << std::setprecision(PRECISION);
     std::cout << std::setw(PRECISION) << T_epoch <<", " <<  std::setw(PRECISION) << Xv << ", " << std::setw(PRECISION) << Yv << ", " <<  std::setw(PRECISION) << Zv << std::endl;
   }
};

#endif
