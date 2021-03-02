#include <iostream>

constexpr unsigned MAX_N = 100;

unsigned num_pare(int v[], unsigned st, unsigned dr)
{
    if (st == dr)
        return v[st] % 2 == 0;

    unsigned mijl = (st + dr) / 2;
    return num_pare(v, st, mijl) + num_pare(v, mijl + 1, dr);
}

int main()
{
    int v[MAX_N];

    std::cout << "Enter n: ";
    unsigned n { 0 };
    std::cin >> n;

    std::cout << "Enter numbers:" << std::endl;
    for (unsigned i = 0; i < n; i++)
        std::cin >> v[i];
 
    unsigned num = num_pare(v, 0, n-1);
    std::cout << "Numere pare: " << num << std::endl;

    return 0;
}
