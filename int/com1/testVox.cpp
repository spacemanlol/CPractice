#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int digitSum(int x)
{

   int sum = 0;
   while(x > 0)
   {
     int digit = x%10;
     x = x/10;
     sum += digit;

   };
   return sum;
}

vector<vector<int>> neig = { {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int getCount(int startX, int startY, int& count)
{
   int sum = digitSum(startX) + digitSum(startY);
   if (sum > 25)
      return 0;

   count++;
   string tab = "    ";
   queue<pair<int, int>>  neighbors;
   neighbors.push({startX, startY});
   unordered_set<string> visit;
   visit.insert(to_string(startX) + "x" + to_string(startY));
   while(!neighbors.empty())
   {
       int n = neighbors.size();
       for (int i = 0; i < n; i++)
       {
          auto[x, y] = neighbors.front();
          neighbors.pop();
cout << x << " . " << y << endl;

          for (int j = 0; j < neig.size(); j++)
          {
              int x1 = x + neig[j][0];
              int y1 = y + neig[j][1];
  
cout << tab << x1 << " ... " << y1 << endl;

              if ( (digitSum(x1) + digitSum(y1)) <= 25 && visit.find(to_string(x1) + "x" + to_string(y1)) == visit.end())
              {
                 cout << tab << tab << x1 << " x " << y1 << " - " << count << endl;
                 neighbors.push({x1,y1});
                 visit.insert(to_string(x1) + "x" + to_string(y1));
                 count++;
              }
          }

       }     
   };
   return count;
}


int main()
{
 
  int count = 0;
  getCount(10000, 10000, count);
  cout << "count = " << count << endl;


  return 0;
}
