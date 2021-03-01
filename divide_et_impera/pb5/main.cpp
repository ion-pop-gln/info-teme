#include <iostream>
#include <cstring>

constexpr unsigned MAX_N = 100;

double sum_poz(double v[], unsigned st, unsigned dr)
{
    if (st == dr)
        return (v[st] > 0) ? v[st] : 0;

    unsigned mijl = (st + dr) / 2;
    return sum_poz(v, st, mijl) + sum_poz(v, mijl + 1, dr);
}

int main()
{
    double v[MAX_N];

    std::cout << "Enter n: ";
    unsigned n { 0 };
    std::cin >> n;

    std::cout << "Enter numbers:" << std::endl;
    for (unsigned i = 0; i < n; i++)
        std::cin >> v[i];
 
    double sum = sum_poz(v, 0, n-1);
    std::cout << sum << std::endl;

    return 0;
}
