#include <iostream>

constexpr unsigned MAX_N { 50 };

typedef struct Index {
    unsigned x { 0 };
    unsigned y { 0 };
} Index;

void intersch_c(int matrix[MAX_N][MAX_N], unsigned p, unsigned k,
                  unsigned sus, unsigned jos)
{
    if (sus == jos) {
        std::swap(matrix[sus][p], matrix[sus][k]);
    } else {
        unsigned mijl { (sus + jos) / 2 };
        intersch_c(matrix, p, k, sus, mijl);
        intersch_c(matrix, p, k, mijl + 1, jos);
    }
}

void intersch_r(int matrix[MAX_N][MAX_N], unsigned p, unsigned k,
                  unsigned st, unsigned dr)
{
    if (st == dr) {
        std::swap(matrix[p][st], matrix[k][st]);
    } else {
        unsigned mijl { (st + dr) / 2 };
        intersch_r(matrix, p, k, st, mijl);
        intersch_r(matrix, p, k, mijl + 1, dr);
    }
}

Index index_max(int matrix[MAX_N][MAX_N], unsigned n, unsigned st, unsigned jos)
{
    Index max_xy {};
    int max { matrix[st][jos] };

    for (unsigned r { jos }; r >= 0; r--) {
        for (unsigned c { st }; c < n; c++) {
            if (matrix[r][c] > max) {
                max = matrix[r][c];
                max_xy.x = c;
                max_xy.y = r;
            }
        }

        if (r == 0)
            break;
    }

    return max_xy;
}

void sort(int matrix[MAX_N][MAX_N], unsigned n, unsigned st, unsigned jos)
{
    if (jos == 0)
        return;

    Index index { index_max(matrix, n, st, jos) };

    intersch_r(matrix, jos, index.y, st, n - 1);
    intersch_c(matrix, st, index.x, 0, jos);

    sort(matrix, n, st + 1, jos - 1);
}

bool is_sorted(int matrix[MAX_N][MAX_N], unsigned n)
{
    for (unsigned i { 0 }; i < n - 1; i++)
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
