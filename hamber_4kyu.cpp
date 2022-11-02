#include <cstdint>

typedef uint64_t ui64;

#include <vector>
#include <math.h>

ui64 do_hamber(int n)
{
    std::vector<ui64> hammings;
    hammings.reserve(n);
    ui64 x2 = 2, x3 = 3, x5 = 5;
    hammings[0] = 1;
    ui64 i = 0, j = 0, k = 0;
    for(int idx = 1; idx < n; idx++)
    {
        hammings[idx] = std::min(x2, std::min(x3, x5));
        if(hammings[idx] == x2) x2 = 2*hammings[++i];
        if(hammings[idx] == x3) x3 = 3*hammings[++j];
        if(hammings[idx] == x5) x5 = 5*hammings[++k];
    }

    return hammings[n-1];
}

int main(int argc, char const *argv[])
{
    ui64 res = do_hamber(4);

    int n =0;
    return 0;
}
