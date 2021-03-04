#include <iostream>

constexpr unsigned MAX_N { 50 };
constexpr unsigned MAX_M { 50 };

void intersch(double matrix[MAX_N][MAX_M], unsigned p, unsigned k,
              unsigned sus, unsigned jos)
{
    if (sus == jos) {
        std::swap(matrix[sus][p], matrix[sus][k]);
    } else {
        unsigned mijl { (sus + jos) / 2 };
        intersch(matrix, p, k, sus, mijl);
        intersch(matrix, p, k, mijl + 1, jos);
    }
}

int main()
{
    double matrix[MAX_N][MAX_M] { 0 };

    std::cout << "Enter n: ";
    unsigned n { 0 };
    std::cin >> n;

    std::cout << "Enter m: ";
    unsigned m { 0 };
    std::cin >> m;

    std::cout << "Enter elements:" << std::endl;
    for (unsigned r { 0 }; r < n; r++)
        for (unsigned c { 0 }; c < m; c++)
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
        for (unsigned c { 0 }; c < m; c++)
            std::cout << matrix[r][c] << " ";
        std::cout << std::endl;
    }

    return 0;
}
