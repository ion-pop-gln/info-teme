#include <iostream>

constexpr unsigned MAX_N { 100 };

typedef struct MinMax {
    double min { 0 };
    double max { 0 };
} MinMax;

double min(double a, double b)
{
    return (a < b) ? a : b;
}

double max(double a, double b)
{
    return (a > b) ? a : b;
}

MinMax find(double v[], unsigned st, unsigned dr)
{
    if (st == dr)
        return MinMax { v[st], v[st] };

    unsigned mijl { (st + dr) / 2 };
    MinMax find_st { find(v, st, mijl) };
    MinMax find_dr { find(v, mijl + 1, dr) };

    double min_val { min(find_st.min, find_dr.min) };
    double max_val { max(find_st.max, find_dr.max) };
    return MinMax { min_val, max_val };
}

int main()
{
    double v[MAX_N];

    std::cout << "Enter n: ";
    unsigned n { 0 };
    std::cin >> n;

    std::cout << "Enter numbers:" << std::endl;
    for (unsigned i { 0 }; i < n; i++)
        std::cin >> v[i];

    MinMax result = find(v, 0, n - 1);

    std::cout << "Minim: " << result.min << std::endl;
    std::cout << "Maxim: " << result.max << std::endl;

    return 0;
}
