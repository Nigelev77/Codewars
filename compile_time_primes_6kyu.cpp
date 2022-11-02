
#include <iostream>

template<unsigned int n>
struct is_prime
{
  static constexpr int value = !(n%2) && is_prime<n/2>::value;
};

template <>
struct is_prime<1>
{
  static constexpr bool value = false;
};

template<>
struct is_prime<2>
{
  static constexpr bool value = true;
};

template<>
struct is_prime<3>
{
  static constexpr bool value = true;
};


int main(int argc, char const *argv[])
{
    is_prime<5> k;
    std::cout<<k.value<<'\n';
    return 0;
}
