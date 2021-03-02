#include <iostream>
#include <cstring>

constexpr unsigned MAX_N { 100 };
constexpr unsigned MAX_WORD { 200 };

char *lex(char *words[], unsigned st, unsigned dr)
{
    if (st == dr)
        return words[st];

    unsigned mijl { (st + dr) / 2 };
    char *lex_st { lex(words, st, mijl) };
    char *lex_dr { lex(words, mijl + 1, dr) };

    return (std::strcmp(lex_st, lex_dr) > 0) ? lex_st : lex_dr;
}

int main()
{
    char *words[MAX_N];

    std::cout << "Enter n: ";
    unsigned n { 0 };
    std::cin >> n;

    std::cout << "Enter words:" << std::endl;
    char temp[MAX_WORD];
    for (unsigned i { 0 }; i < n; i++) {
        std::cin >> temp;
        unsigned long len { std::strlen(temp) };
        words[i] = new char[len];
        std::strcpy(words[i], temp);
    }
 
    char *word { lex(words, 0, n-1) };
    std::cout << "Cuvantul cel mai mare: " << word << std::endl;

    for (unsigned i { 0 }; i < n; i++)
        delete[] words[i];

    return 0;
}
