#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
// as trade is executed, it call trade_execute("AAPL",400) is call where it say
// 400 shared of AAPL is exected,  find the top N executed share by volume,
// 
class Post_Trade
{
   std::unordered_map<std::string, std::size_t> trades;
   // if asking for top 10 and number 10 is fixed then we can limit the size of topN map  
   std::map<size_t, std::unordered_set<std::string>> topN;
  public:
 void execute_trade(std::string symbol, std::size_t vol)
 {
    std::size_t oldVol = 0;
    if (trades.find(symbol) != trades.end())
    {
         oldVol = trades[symbol];
         trades[symbol] += vol;
    }
    else
    {
        trades[symbol] = vol;
    }

    // if I use priority que, it will keep the topN but when any trade comes and if this symbol already
    // exist in middle of the queue, I can not remove it, so priority que can not be used here
    // what about map which is keep the items sorted based on volume
    auto it = topN.find(oldVol);
    if (it != topN.end())
    {
         // remove the symbol from the set as it will be part of new vol
         // check if this symbol entry in the old vol
         auto it2 = it->second.find(symbol);
         if (it2 != it->second.end())
         {
            it->second.erase(it2);
            // if it is the only one item in the list, then remove it from the topN list, it will be inserted later 
            // with new volume
            if (it->second.size() == 0)
            {
               topN.erase(it);
            } 
         } 
    }

    std::size_t newvol = oldVol + vol;
    //if (topN.find(newvol) != topN.end())
    {
        topN[newvol].insert(symbol);
    }

 }

 void print_topN(std::size_t n)
 {
    std::vector<std::pair<std::string, std::size_t>> topNByVol;
    auto it = topN.rbegin();
    bool done{false};
    std::size_t count{0};

    while(it != topN.rend() && !done)
    {
        std::size_t curVol = it->first;
        for(auto& it2: it->second)
        {
            topNByVol.push_back({it2, curVol});
            count++;
            if (count == n)
            {
               done = true;
               break;
            }
        }

        ++it;

    }

    for(auto& it : topNByVol)
    {
        std::cout << it.first <<"/" << it.second << std::endl;
    }
   
 }



};


int main()
{
   Post_Trade trade;
   trade.execute_trade("MSFT", 400);
   trade.execute_trade("IBM", 1000);
   trade.execute_trade("AAPL", 500);
   trade.execute_trade("NFLX", 1000);
   trade.execute_trade("AAPL", 600);
   trade.execute_trade("AMZN", 700);
   trade.execute_trade("GOGL", 300);

   trade.print_topN(4);

   return 0;
}
