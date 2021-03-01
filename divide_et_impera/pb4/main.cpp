#include <iostream>
#include <cstring>

constexpr unsigned MAX_N = 100;
constexpr unsigned MAX_WORD = 200;

unsigned long long factorial(unsigned prim, unsigned ultim)
{
    if (prim == ultim)
        return prim;

    unsigned mijl = (prim + ultim) / 2;
    unsigned long long fac_st = factorial(prim, mijl);
    unsigned long long fac_dr = factorial(mijl + 1, ultim);

    return fac_st * fac_dr;
}

int main()
{
    std::cout << "Enter n: ";
    unsigned n { 0 };
    std::cin >> n;

    unsigned long long val = factorial(1, n);
    std::cout << val << std::endl;

    return 0;
}
