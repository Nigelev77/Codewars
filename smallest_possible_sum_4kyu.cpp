#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>
typedef unsigned long long uint64;

unsigned long long solution(const std::vector<unsigned long long>& arr)
{
    int size = arr.size();
    if(size == 1) return arr[0];
    auto begin = arr.begin();
    auto end = arr.end();
    uint64 first = arr[0];
    bool isSame = std::all_of(begin+1, end, [&first](int i){return first == i;});
    if(std::any_of(begin, end, [](int i){return i==1;})) return (uint64)size;
    
    uint64 smallest = *std::min_element(begin, end);
    uint64 biggest = *std::max_element(begin, end);
    // WAIIIT IM ACC SMART, THE SMALLEST WILL JUST BE THE LARGEST COMMON FACTOR OF ALL THE NUMBERS NO?
    uint64 limit = (uint64)std::sqrt(biggest);

    //sieve of erastothenes
    std::vector<bool> sieve(limit, false);
    std::vector<uint64> primes{};
    for(int i = 1; i<limit; i++)
    {

        int num = i;
        if(!sieve[num]) primes.push_back(i+1);
        sieve[num] = true;
        while(num < limit)
        {
            sieve[num] = true;
            num+=(i+1);
        }
    }
    //WAIIIIIT IT SHOULDNT TEST FOR PRIMES (although acc it can nvm)
    for(int i = primes.size()-1; i>=0; i--)
    {
        bool divis = true;
        int prime = primes[i];
        for(uint64 num : arr)
        {
            if(num % prime) divis = false;
        }
        if(divis) return prime*size;
    }
    return 0;
}


int main(int argc, char const *argv[])
{
    std::vector<uint64> arr{1, 21, 55};
    uint64 res = solution(arr);


    int n = 0;
    return 0;
}
