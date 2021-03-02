#include <iostream>

typedef unsigned long long ull;

ull factorial(unsigned prim, unsigned ultim)
{
    if (prim == ultim)
        return prim;

    unsigned mijl { (prim + ultim) / 2 };
    ull fac_st { factorial(prim, mijl) };
    ull fac_dr { factorial(mijl + 1, ultim) };

    return fac_st * fac_dr;
}

int main()
{
    std::cout << "Enter n: ";
    unsigned n { 0 };
    std::cin >> n;

    ull val { factorial(1, n) };
    std::cout << "Factorial: " << val << std::endl;

    return 0;
}
