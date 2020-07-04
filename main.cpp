#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>  

#include <utility>
#include <map>

std::multimap<int, std::string, std::greater<int>> sorted_map;
std::vector<std::string> vSrt;
std::vector<std::string> mySplit(std::string &str, char delimiter = '\t');
//std::pair<std::string, std::string>  mySplitStr(std::string &str, char delimiter = '\t');
std::pair<std::string, std::string>  mySplitStr(std::string &str, char delimiter = '\t');
void mySort(std::string str,
std::multimap<std::string, std::string, std::greater<std::string>> &res);

void test()
{
    std::multimap<int, std::string, std::greater<int>> sorted_map;
    // Sort the names of animals in descending order of the number of legs
    sorted_map.insert(std::make_pair(6,   "bug"));
    sorted_map.insert(std::make_pair(4,   "cat"));
    sorted_map.insert(std::make_pair(100, "centipede"));
    sorted_map.insert(std::make_pair(2,   "chicken"));
    sorted_map.insert(std::make_pair(0,   "fish"));
    sorted_map.insert(std::make_pair(4,   "horse"));
    sorted_map.insert(std::make_pair(8,   "spider"));

    for (auto const& entry: sorted_map)
    {
        std::cout << entry.second << " (has " << entry.first << " legs)" << '\n';
    }
}

int main()
{
    std::multimap<std::string, std::string, std::greater<std::string>> multiMap;

    std::string str = "1\twold\t!";
    auto res = mySplitStr(str);
    multiMap.emplace(res.first, res.second);

     std::string str2 = "2\twold2\t!";
    auto res2 = mySplitStr(str2);
    multiMap.emplace(res2.first, res2.second);

    for (auto const& entry: multiMap)
    {
        std::cout <<  entry.second << '\n';
    }

    return 0;
}



/***************** mySplitStr ***************/
std::pair<std::string, std::string> mySplitStr(std::string &str, char delimiter)
{
   try
   {
       std::stringstream ss(str);
       std::string tmp;
       while (std::getline(ss, tmp, delimiter)) {
          std::pair<std::string, std::string> res = {tmp, str};
         return res;
         }
   }
   catch(const std::exception& e)
   {
       std::cerr << e.what() << '\n';
       return {"", ""};
   }
  return {"", ""};
}


/******************  mySplit ****************/
std::vector<std::string> mySplit(std::string &str, char delimiter)
{
   std::vector<std::string> res;
   try
   {
       std::stringstream ss(str);
       std::string tmp;
       while (std::getline(ss, tmp, delimiter)) {
         res.push_back(tmp);
         }
   }
   catch(const std::exception& e)
   {
       std::cerr << e.what() << '\n';
   }

   return res;
}