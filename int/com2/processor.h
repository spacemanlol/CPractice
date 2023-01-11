#ifndef LLA_ECEFUTILITY_H
#define LLA_ECEFUTILITY_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <unordered_map>
#include "def.h"

class LLA_ECEFUtility
{
  constexpr static long double a{ 6378137.0 };
  constexpr static long double b{ 6356752.31424518 };
  constexpr static long double e_sqr = (a*a - b*b)/(a*a);
  constexpr static long double bsqr_by_asqr = (b*b)/(a*a);
  constexpr static long double DEG_TO_RAD{ 0.0174533 };
  std::vector<LLAData> _llaData;
  std::unordered_map<long long, ECEFVelocity>  maps;
  long long _lowest_epoch;
  long long _highest_epoch;
  int _step_time;
public:

  void set_LLAData(std::vector<LLAData>& lla);
  void set_LLAData(std::vector<LLAData>&& lla);
  void convertLLADataToECEFVelocity();
  ECEFVelocity getVelocity(const long double& epoch);

  static ECEFData convertLLADataToECEFData(const LLAData& llaData);

  static ECEFVelocity calculateVelocity(const ECEFData& from, const ECEFData& to);


  //static std::vector<ECEFData> convertLLADataToECEFData(const std::vector<LLAData>& data);

  static std::vector<ECEFVelocity> calculate_ECEF_Velocity(const std::vector<ECEFData>& data);

  static std::unordered_map<long long, ECEFVelocity>  convertToMap(const std::vector<ECEFVelocity>& velocity);


  static ECEFVelocity  interpolateVelocity(const ECEFVelocity& velocityFrom, const ECEFVelocity& velocityTo, const long double& epoch);
}; 

#endif
