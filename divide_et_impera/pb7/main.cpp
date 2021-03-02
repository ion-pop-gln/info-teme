#include <iostream>

constexpr unsigned MAX_N = 100;

double min(double a, double b)
{
    return (a < b) ? a : b;
}

double max(double a, double b)
{
    return (a > b) ? a : b;
}

double find(double v[], unsigned st, unsigned dr, double op(double, double))
{
    if (st == dr)
        return v[st];

    unsigned mijl = (st + dr) / 2;
    double find_st = find(v, st, mijl, op);
    double find_dr = find(v, mijl + 1, dr, op);
    
    return op(find_st, find_dr);
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
 
    double min_val = find(v, 0, n-1, min);
    std::cout << "Minim: " << min_val << std::endl;

    double max_val = find(v, 0, n-1, max);
    std::cout << "Maxim: " << max_val << std::endl;

    return 0;
}
