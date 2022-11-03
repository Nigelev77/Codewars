#include <iostream>
#include <vector>
#include <algorithm>

long nextBigger(long n)
{
    std::string num;
    long tempNum = n;
    while(tempNum)
    {
        num.push_back(tempNum%10 + '0');
        tempNum /= 10;
    }
    std::reverse(num.begin(), num.end());
    if(!std::next_permutation(num.begin(), num.end())) return -1;
    long res = 0;
    std::reverse(num.begin(), num.end());
    long pow = 1;
    for(int i = 0; i<num.size(); i++)
    {
        res +=  pow * (num[i] - '0');
        pow *= 10;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    long num = 12;
    long res = nextBigger(num);


    int n = 0;


    return 0;
}
