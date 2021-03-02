#include <iostream>

constexpr unsigned MAX_N { 50 };

void intersch(char matrix[MAX_N][MAX_N], unsigned p, unsigned k,
              unsigned st, unsigned dr)
{
    if (st == dr) {
        std::swap(matrix[p][st], matrix[k][st]);
    } else {
        unsigned mijl { (st + dr) / 2 };
        intersch(matrix, p, k, st, mijl);
        intersch(matrix, p, k, mijl + 1, dr);
    }
}

int main()
{
    char matrix[MAX_N][MAX_N] { 0 };

    std::cout << "Enter n: ";
    unsigned n { 0 };
    std::cin >> n;

    std::cout << "Enter characters:" << std::endl;
    for (unsigned r { 0 }; r < n; r++)
        for (unsigned c { 0 }; c < n; c++)
            std::cin >> matrix[r][c];
 
    std::cout << "Enter p: ";
    unsigned p { 0 };
    std::cin >> p;
    unsigned index_p { p - 1 };

    std::cout << "Enter k: ";
    unsigned k { 0 };
    std::cin >> k;
    unsigned index_k { k - 1 };

    intersch(matrix, index_p, index_k, 0, n-1);

    std::cout << "Matricea:" << std::endl;
    for (unsigned r { 0 }; r < n; r++) {
        for (unsigned c { 0 }; c < n; c++)
            std::cout << matrix[r][c] << " ";
        std::cout << std::endl;
    }

    return 0;
}
