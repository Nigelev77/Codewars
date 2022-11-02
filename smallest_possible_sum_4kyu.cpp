#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>
typedef unsigned long long uint64;

uint64 gcd(uint64 a, uint64 b)
{
    if(a == 0)
        return b;
    return gcd(b % a, a);
}



unsigned long long solution3(const std::vector<unsigned long long>& arr)
{
    int size = arr.size();
    if(size == 1) return arr[0];

    uint64 res = arr[0];
    for(int i = 0; i<size; i++)
    {
        res = gcd(arr[i], res);
        if(res == 1)
        {
            return size;
        }
    }
    return res*size;
}




unsigned long long solution2(const std::vector<unsigned long long>& arr)
{
    int size = arr.size();
    if(size == 1) return arr[0];
    auto begin = arr.begin(), end = arr.end();
    uint64 first = arr[0];
    if(std::all_of(begin+1, end, [&first](int i){return first == i;})) return first*size;
    if(std::any_of(begin, end, [](uint64 i){return i == 1;})) return size;


    uint64 smallest = *std::min_element(begin, end);
    uint64 biggest = *std::max_element(begin, end);



    std::vector<uint64> vec1{begin, end};
    std::sort(vec1.begin(), vec1.end(), std::greater());
    uint64* ptr = &vec1[0];
    bool flag = std::all_of(begin, end, [ptr](uint64 i){return (*ptr) == i;});
    while(!flag)
    {
        uint64 temp = vec1[0];
        for(int i = 0; i<vec1.size()-1; i++)
        {
            uint64 bigger = vec1[i] > vec1[i+1] ? vec1[i] : vec1[i+1];
            uint64 smaller = vec1[i] < vec1[i+1] ? vec1[i] : vec1[i+1];
            uint64 res = bigger % smaller;
            if(res == 0)
            {
                flag = true;
                vec1[i] = smaller;
            }
            else
            {
                vec1[i] = res;

            }
        }
        uint64 bigger = vec1[vec1.size()-1] > vec1[0] ? vec1[vec1.size()-1] : vec1[0]; 
        uint64 smaller = vec1[vec1.size()-1] < vec1[0] ? vec1[vec1.size()-1] : vec1[0];
        uint64 lastRes = bigger % smaller;
        if(lastRes == 0)
        {
            flag = true;
            vec1[vec1.size()-1] = smaller;
        }
        else
        {
            vec1[vec1.size()-1] = lastRes; 
        }


        if(flag)
        {
            return (*std::min_element(vec1.begin(), vec1.end()) * size);
        }
        flag = std::all_of(begin, end, [ptr](uint64 i){return (*ptr) == i;});
    }
    return vec1[0] * size;
}



unsigned long long solution(const std::vector<unsigned long long>& arr)
{
    int size = arr.size();
    if(size == 1) return arr[0];
    auto begin = arr.begin();
    auto end = arr.end();
    uint64 first = arr[0];
    bool isSame = std::all_of(begin+1, end, [&first](int i){return first == i;});
    if(isSame) return arr[0]*size;
    if(std::any_of(begin, end, [](int i){return i==1;})) return (uint64)size;
    
    uint64 smallest = *std::min_element(begin, end);
    uint64 biggest = *std::max_element(begin, end);
    // WAIIIT IM ACC SMART, THE SMALLEST WILL JUST BE THE LARGEST COMMON FACTOR OF ALL THE NUMBERS NO?
    uint64 limit = biggest/2;

    //sieve of erastothenes
    // std::vector<bool> sieve(limit, false);
    // std::vector<uint64> primes{};
    // std::vector<uint64> res{1};
    // for(int i = 1; i<limit; i++)
    // {

    //     int num = i;
    //     if(!sieve[num]) primes.push_back(i+1);
    //     sieve[num] = true;
    //     while(num < limit)
    //     {
    //         sieve[num] = true;
    //         num+=(i+1);
    //     }
    // }
    // //WAIIIIIT IT SHOULDNT TEST FOR PRIMES (although acc it can nvm)
    // for(int i = primes.size()-1; i>=0; i--)
    // {
    //     bool divis = true;
    //     int prime = primes[i];
    //     for(uint64 num : arr)
    //     {
    //         if(num % prime) divis = false;
    //     }
    //     if(divis) res.push_back(prime);
    // }

    std::vector<uint64> factors{1};


    for(int i = 2; i<=smallest; i++)
    {
        if(!(biggest % i)) factors.push_back(i);
    }

    std::vector<uint64> res;
    for(auto factor : factors)
    {
        bool divis = true;
        for(auto num : arr)
        {
            if(num % factor)
            {
                divis = false;
                break;
            }
        }
        if(divis) res.push_back(factor);
    }

    return res.back()*size;
}


int main(int argc, char const *argv[])
{
    std::vector<uint64> arr{1565924502, 2104684391, 2270844147l, 80561242, 1651523016, 2391686010l, 120841863, 1691803637, 2064403770, 4043209026l, 2683724901l, 1812645500, 1153043748, 3464168516l, 1032201885, 3011007141l, 699882373, 4209368782l, 453161375, 3756207407l, 4169088161l, 3051287762l, 1606205123, 3011007141l, 1857963393, 1898244014, 1485363260, 1565924502, 946603371, 3549767030l, 1898244014, 1359484125, 2930445899l, 1812645500, 327282240, 1606205123, 1485363260, 2764286143l, 3177166897l, 1153043748, 1153043748, 4002928405l, 3011007141l, 740162994, 206440377, 1319203504, 4249649403l, 1525643881, 825761508, 1978805256, 3257728139l, 906322750, 4249649403l, 3177166897l, 246720998, 3796488028l, 1112763127, 3796488028l, 619321131, 2683724901l, 3423887895l, 1485363260, 2185245633l, 1565924502, 367562861, 1238642262, 2225526254l, 3217447518l, 3922367163l, 1606205123, 327282240, 2638407008l, 3096605655l, 40280621, 2557845766l, 866042129, 120841863, 619321131, 327282240, 1525643881, 1606205123, 2351405389l, 120841863, 1399764746, 1112763127, 2517565145l, 2391686010l, 946603371, 2477284524l, 1278922883};
    uint64 res = solution(arr);
    uint64 res2 = solution2(arr);
    uint64 res3 = solution3(arr);

    int n = 0;
    return 0;
}
