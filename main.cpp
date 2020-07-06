#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>  

#include <utility>
#include <map>
#include <limits>

std::multimap<int, std::string, std::greater<int>> sorted_map;
std::vector<std::string> vSrt;
std::vector<std::string> mySplit(std::string &str, char delimiter = '\t');
//std::pair<std::string, std::string>  mySplitStr(std::string &str, char delimiter = '\t');
std::pair<std::string, std::string>  mySplitStr(std::string &str, char delimiter = '\t');
void mySort(std::string str,
std::multimap<std::string, std::string, std::greater<std::string>> &res);
std::vector<std::string> Where(std::multimap<std::string, std::string, std::greater<std::string>> multiMap, std::string predicate, bool isAll = false);
void Print(std::multimap<std::string, std::string, std::greater<std::string>> multiMap);
void Print(std::vector<std::string> myVec);

std::vector<std::string> split(const std::string &s, char delim);

void StartApp();

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



int main(int argc, char const *argv[])
{
   std::cout << "enter an empty line to exit the program" << '\n';
    std::multimap<std::string, std::string, std::greater<std::string>> multiMap;
    for(std::string line; std::getline(std::cin, line);)
    {
        auto res = mySplitStr(line);
        
        multiMap.emplace(res.first, res.first);
        Print(multiMap);
        auto vres = Where(multiMap, "1.");
        Print(vres);
        auto vres1 = Where(multiMap, "46.70.");
        Print(vres1);
        auto vres2 = Where(multiMap, "46", true);
        Print(vres2);
        
    }

    return 0;
}

/**************** split *************/
std::vector<std::string> split(std::string &s, char delim) {
    std::vector<std::string> elems;
    std::stringstream ss(s);
    std::string number;
    while(std::getline(ss, number, delim)) {
        elems.push_back(number);
    }
    return elems;
}

/*****************  Print  ************/
void Print(std::vector<std::string> myVec)
{
   for(auto const& value: myVec)
    {
       std::cout << value << '\n';
    }
}

void Print(std::multimap<std::string, std::string, std::greater<std::string>> multiMap)
{
    for (auto const& entry: multiMap)
    {
        std::cout << entry.second << '\n';
    }
}

/***************** StartApp ***********/
void StartApp()
{
  std::multimap<std::string, std::string, std::greater<std::string>> multiMap;

    std::string _str = "1\twold\t!";
    auto res = mySplitStr(_str);
    multiMap.emplace(res.first, res.second);

     std::string str2 = "2\twold2\t!";
    auto res2 = mySplitStr(str2);
    multiMap.emplace(res2.first, res2.second);

    for (auto const& entry: multiMap)
    {
        std::cout <<  entry.second << '\n';
    }

     auto vres = Where(multiMap, "1");

    for(auto const& value: vres)
    {
       std::cout << value << '\n';
    }
}
#include <limits>

/***************** Where ***************/
std::vector<std::string> Where(std::multimap<std::string, std::string, std::greater<std::string>> multiMap, std::string predicate, bool isAll)
{
   std::vector<std::string> res;
    try
    {
        for (auto const& entry: multiMap)
        {
            if(!isAll)
            {
                if(entry.first.find(predicate) == 0)
                {
                    res.push_back(entry.first);
                }
            }
           else
           {
                size_t n = entry.first.find(predicate);
               if(n >= 0 && n <= entry.first.size())
                {
                    res.push_back(entry.first);
                }
           }
           
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
   return res;
}

/***************** mySplitStr ***************/
std::pair<std::string, std::string> mySplitStr(std::string &str, char delimiter)
{
   try
   {
       auto rvec = split(str, delimiter);
       if(rvec.size() > 0)
       {
           return {rvec[0], str};
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