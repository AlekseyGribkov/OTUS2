#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>  

#include <utility>
#include <map>

std::pair<std::string, std::string>  mySplitStr(std::string &str, char delimiter = '\t');
std::vector<std::string> Where(std::multimap<std::string, std::string, std::greater<std::string>> multiMap, std::string predicate, bool isAll = false);
void Print(std::multimap<std::string, std::string, std::greater<std::string>> multiMap);
void Print(std::vector<std::string> myVec);
std::vector<std::string> split(const std::string &s, char delim);


int main(int argc, char const *argv[])
{
   std::cout << "enter an empty line to exit the program " << '\n';
    std::multimap<std::string, std::string, std::greater<std::string>> multiMap;
    for(std::string line; std::getline(std::cin, line);)
    {
        if(line == "") return 0;
        auto res = mySplitStr(line);
        if(res.first != "")
        {            
            multiMap.emplace(res.first, res.first);
            Print(multiMap);
            auto vres = Where(multiMap, "1.");
            Print(vres);
            auto vres1 = Where(multiMap, "46.70.");
            Print(vres1);
            auto vres2 = Where(multiMap, "46", true);
            Print(vres2);
        }
        
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

