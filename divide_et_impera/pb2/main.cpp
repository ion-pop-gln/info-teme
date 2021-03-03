#include <iostream>

constexpr unsigned MAX_N { 50 };

void intersch(int matrix[MAX_N][MAX_N], unsigned p, unsigned k,
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

unsigned index_max(int v[], unsigned st, unsigned dr)
{
    if (st == dr)
        return st;

    unsigned mijl { (st + dr) / 2 };
    unsigned max_st { index_max(v, st, mijl) };
    unsigned max_dr { index_max(v, mijl + 1, dr) };

    return (v[max_st] > v[max_dr]) ? max_st : max_dr;
}

void sort(int matrix[MAX_N][MAX_N], unsigned n, unsigned sus, unsigned jos)
{
    if (sus == jos) {
        unsigned st = n - 1 - sus;
        unsigned index = index_max(matrix[sus], st, n - 1);
        if (index != st)
            intersch(matrix, st, index, 0, n - 1);
    } else {
        unsigned mijl { (sus + jos) / 2 };
        sort(matrix, n, sus, mijl);
        sort(matrix, n, mijl + 1, jos);
    }
}

bool is_sorted(int matrix[MAX_N][MAX_N], unsigned n)
{
    for (unsigned i = 0; i < n - 1; i++)
        if (matrix[n - 1 - i][i] < matrix[n - 2 - i][i + 1])
            return false;
    return true;
}

int main()
{
    int matrix[MAX_N][MAX_N] { 0 };

    std::cout << "Enter n: ";
    unsigned n { 0 };
    std::cin >> n;

    std::cout << "Enter elements:" << std::endl;
    for (unsigned r { 0 }; r < n; r++)
        for (unsigned c { 0 }; c < n; c++)
            std::cin >> matrix[r][c];

    sort(matrix, n, 0, n-1);
    if (!is_sorted(matrix, n)) {
        std::cout << "Matricea nu a putut fi sortata >:(" << std::endl;
        return 1;
    }

    std::cout << "Matricea:" << std::endl;
    for (unsigned r { 0 }; r < n; r++) {
        for (unsigned c { 0 }; c < n; c++)
            std::cout << matrix[r][c] << " ";
        std::cout << std::endl;
    }

    return 0;
}
