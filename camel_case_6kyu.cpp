#include <iostream>
#include <string>
#include <vector>

std::string to_camel_case(std::string text)
{
    if(text.empty()) return "";
    std::string res;
    for(auto it = text.begin(); it<text.end(); it++)
    {
        auto itStart = it;
        while(it!=text.end() && ((*it)!='-' && (*it)!='_')) it++;
        std::string inter{itStart, it};
        if(itStart != text.begin()) inter[0] = std::toupper(inter[0]);
        res += inter;
    }

    return res;

}

int main(int argc, char const *argv[])
{
    std::string str{"the_stealth_warrior"};
    std::string res = to_camel_case(str);

    int n =0;
    return 0;
}
