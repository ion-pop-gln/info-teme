#include <algorithm> // std::sort
#include <iostream>  // std::cout, std::cerr, std::endl
#include <fstream>   // std::ifstream
#include <cstring>   // std::strlen
#include <sstream>   // std::ostringstream
#include <string>    // std::string
#include <vector>    // std::vector
#include <cstdio>    // std::printf

constexpr unsigned MAX_ELEVI { 4096U };
constexpr unsigned MAX_NUME  { 30U };

struct elev {
    int mate { 0 };
    int rom { 0 };
    float media { 0 };

    char nume[MAX_NUME + 1] { 0 };
};

struct elev citeste_elev(std::ifstream& file);
bool compara_elevi(const struct elev& elev1, const struct elev& elev2);
void print_elev(const struct elev& elev, int max_width);
void eroare(std::string mesaj);

int main() {
    std::vector<struct elev> elevi;
    std::ifstream in_file { "date.in" };

    if (!in_file.is_open())
        eroare("Nu s-a putut deschide fisierul [date.in].");

    int max_width { 0 };

    while (in_file) {
        if (in_file.eof()) break;
        if (elevi.size() == MAX_ELEVI) eroare("Prea multi elevi.");

        struct elev elev_citit { citeste_elev(in_file) };
        max_width = std::max(max_width, (int)std::strlen(elev_citit.nume));
        elevi.push_back(elev_citit);
    }

    in_file.close();

    std::sort(elevi.begin(), elevi.end(), compara_elevi);

    for (struct elev elev_curent : elevi)
        print_elev(elev_curent, max_width);

    return 0;
}

struct elev citeste_elev(std::ifstream& file) {
    struct elev elev_citit;

    file >> elev_citit.mate;
    file >> elev_citit.rom;
    elev_citit.media = (float)(elev_citit.mate + elev_citit.rom) / 2;

    std::string nume;
    file >> nume;

    if (nume.size() > MAX_NUME) {
        std::ostringstream mesaj_eroare { "" };
        mesaj_eroare << "Numele [" << nume << "] este prea lung.";
        eroare(mesaj_eroare.str());
    } else {
        nume.copy(elev_citit.nume, nume.size());
    }

    return elev_citit;
}

bool compara_elevi(const struct elev& elev1, const struct elev& elev2) {
    return elev1.media < elev2.media;
}

void print_elev(const struct elev& elev, int max_width) {
    std::printf("%*s %4.2f\n", max_width, elev.nume, elev.media);
}

void eroare(std::string mesaj) {
    std::cerr << "Eroare: " << mesaj << " Se incheie programul..." << std::endl;
    std::exit(EXIT_FAILURE);
}