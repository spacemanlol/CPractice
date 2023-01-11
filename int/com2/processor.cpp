#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <cmath>
#include "processor.h"

  void LLA_ECEFUtility::set_LLAData(std::vector<LLAData>& lla)
  {
     std::cout << "Setting data by copying" << std::endl;

      _llaData = lla;
  }

  void LLA_ECEFUtility::set_LLAData(std::vector<LLAData>&& lla)
  {
     std::cout << "Setting data by moving" << std::endl;
      _llaData = lla;
      if (_llaData.size() > 1)
      {
	_lowest_epoch = static_cast<long long>(_llaData[0].time_epoch);
        _highest_epoch = static_cast<long long>(_llaData[_llaData.size() - 1].time_epoch);
        _step_time = static_cast<int>(_llaData[1].time_epoch - _llaData[0].time_epoch);
      }      
//       std::vector<ECEFData> ecefDataStore = LLA_ECEFUtility::convertLLADataToECEFData(_llaData);
//       std::vector<ECEFVelocity> ecefVelocity = LLA_ECEFUtility::calculate_ECEF_Velocity(ecefDataStore);
//       std::unordered_map<long long, ECEFVelocity> mapVelocity = LLA_ECEFUtility::convertToMap(ecefVelocity);
//       std::cout << "Total ECEF Data: " << mapVelocity.size() << std::endl;
  }

  ECEFData LLA_ECEFUtility::convertLLADataToECEFData(const LLAData& llaData)
  {
      long double cos_lat = cos(llaData.latitude * DEG_TO_RAD);
      long double sin_lat = sin(llaData.latitude * DEG_TO_RAD);
      long double cos_lon = cos(llaData.longitude * DEG_TO_RAD);
      long double sin_lon = sin(llaData.longitude * DEG_TO_RAD);

      long double inn = 1 - e_sqr * sin_lat * sin_lat;
      long double N = a/sqrt(inn);

      ECEFData ecefData;
      ecefData.time_epoch = llaData.time_epoch;
      ecefData.X = (N + llaData.altitude) * cos_lat * cos_lon;
      ecefData.Y = (N + llaData.altitude) * cos_lat * sin_lon;
      ecefData.Z = (bsqr_by_asqr * N + llaData.altitude) * sin_lat;    
      return ecefData;
  }

 void LLA_ECEFUtility::convertLLADataToECEFVelocity()
 {
   ECEFData prev;
   ECEFData curr;

   if (_llaData.size() < 2)
	return;

   maps.clear();
   // take care of first data point before the loop to avoid writing conditional statement
   // inside the loop, first data has no  velocity
   curr = convertLLADataToECEFData(_llaData[0]);
   maps[_llaData[0].time_epoch] = {0.0, 0.0, 0.0, _llaData[0].time_epoch};

   for (int i = 1; i < _llaData.size(); i++)
   {
       prev = curr;
       curr = convertLLADataToECEFData(_llaData[i]);
       ECEFVelocity ecefVelocity = calculateVelocity(prev, curr);       
       std::cout << "ECEF " << i+1 << ": ";
       curr.Print();
       std::cout << "Velocity " << i+1 << ": ";
       ecefVelocity.Print();
       maps[_llaData[i].time_epoch] = ecefVelocity; 
   }
   
 }

 //std::vector<ECEFData> LLA_ECEFUtility::convertLLADataToECEFData(const std::vector<LLAData>& data)
 //{
 //  std::vector<ECEFData> ecefStore;
 //  for (int i = 0; i < data.size(); i++)
 //  {
 //      ECEFData ecefData = convertLLADataToECEFData(data[i]);
 //      std::cout << "ECEF " << i+1 << ": ";
 //      ecefData.Print();
 //      ecefStore.push_back(ecefData);
 //  }
   
 //  std::vector<ECEFVelocity> ecefVelocity = calculate_ECEF_Velocity(ecefStore);

 //  return ecefStore;
 // }

   ECEFVelocity LLA_ECEFUtility::calculateVelocity(const ECEFData& from, const ECEFData& to)
   {
        long double deltaT = to.time_epoch - from.time_epoch;
        long double deltaX = to.X - from.X;
        long double deltaY = to.Y - from.Y;
        long double deltaZ = to.Z - from.Z;

        ECEFVelocity ecefVelocity;
        ecefVelocity.T_epoch = to.time_epoch;
        ecefVelocity.Xv = deltaX/deltaT;
        ecefVelocity.Yv = deltaY/deltaT;
        ecefVelocity.Zv = deltaZ/deltaT;
        return ecefVelocity;
   }

   std::vector<ECEFVelocity> LLA_ECEFUtility::calculate_ECEF_Velocity(const std::vector<ECEFData>& data)
   {

    std::vector<ECEFVelocity> velocity;
   
    velocity.reserve(data.size());
    velocity.push_back({0.0, 0.0, 0.0, data[0].time_epoch});

    std::cout << "Velocity " << 1 << ": ";
    velocity[0].Print();

    for (int i = 1; i < data.size(); i++)
    {
        long double deltaT = data[i].time_epoch - data[i-1].time_epoch;
        long double deltaX = data[i].X - data[i-1].X;
        long double deltaY = data[i].Y - data[i-1].Y;
        long double deltaZ = data[i].Z - data[i-1].Z;
        ECEFVelocity ecefVelocity;
        ecefVelocity.T_epoch = data[i].time_epoch;
        ecefVelocity.Xv = deltaX/deltaT;
        ecefVelocity.Yv = deltaY/deltaT;
        ecefVelocity.Zv = deltaZ/deltaT;
        std::cout << "Velocity " << i+1 << ": ";
        ecefVelocity.Print();
        velocity.push_back(ecefVelocity);
         
    }
    return velocity;
  }

 std::unordered_map<long long, ECEFVelocity>  LLA_ECEFUtility::convertToMap(const std::vector<ECEFVelocity>& velocity)
  {

      std::unordered_map<long long, ECEFVelocity>  maps;

      for (int i = 0; i < velocity.size(); i++)
      {
	   maps[velocity[i].T_epoch] = velocity[i];
      }

      return maps;

  }

 ECEFVelocity LLA_ECEFUtility::getVelocity(const long double& epoch)
 {

   long long epoch_x = epoch;
   long long lower = (epoch_x/_step_time)*_step_time - 1;
   long long higher = lower + _step_time;
   
   ECEFVelocity ecefVelocity;
   
   if (lower <= 0)
       return ecefVelocity;    
   auto it = maps.find(epoch_x); 
   if (	maps.find(epoch_x) == maps.end())
   {
        auto it1 = maps.find(lower);
        auto it2 = maps.find(higher);
        if (it1 != maps.end() && it2 != maps.end())
        {
           ECEFVelocity vLower  = it1->second;
           ECEFVelocity vHigher = it2->second;
           ecefVelocity = interpolateVelocity(vLower, vHigher, epoch);

        }
        else
        {
          // return empty one
        }
   }
   else
   {
       	ecefVelocity = it->second;

   }

  	return ecefVelocity;	
  }

  ECEFVelocity  LLA_ECEFUtility::interpolateVelocity(const ECEFVelocity& velocityFrom, const ECEFVelocity& velocityTo, const long double& epoch)
  {
        ECEFVelocity ecefVelocity;
        
        long double epochRatio = (epoch - velocityFrom.T_epoch) / (velocityTo.T_epoch - velocityFrom.T_epoch);
        ecefVelocity.Xv = (velocityTo.Xv - velocityFrom.Xv) * epochRatio;
        ecefVelocity.Yv = (velocityTo.Yv - velocityFrom.Yv) * epochRatio;
        ecefVelocity.Zv = (velocityTo.Zv - velocityFrom.Zv) * epochRatio;
        ecefVelocity.T_epoch = epoch; 
        return ecefVelocity;
  }
