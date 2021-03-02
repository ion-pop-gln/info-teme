#include <iostream>

typedef unsigned long long ull;

ull sqrt(ull n, ull prim, ull ultim)
{
    ull mijl { (prim + ultim) / 2 };
    ull mijl_next { mijl + 1 };

    if (mijl * mijl <= n) {
        if (mijl_next * mijl_next > n)
            return mijl;
        else
            return sqrt(n, mijl + 1, ultim);
    } else
        return sqrt(n, 0, mijl);
}

int main()
{
    std::cout << "Enter n: ";
    ull n { 0 };
    std::cin >> n;

    ull sqrt_val { sqrt(n, 0, n) };
    std::cout << "Radacina patrata: " << sqrt_val << std::endl;

    return 0;
}
