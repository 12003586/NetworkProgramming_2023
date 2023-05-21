#include <iostream>
#include "Dobbelsteen.h"
#include "InputUtils.h"

int main() {
    int aantalDobbelstenen, aantalOgen;

    aantalDobbelstenen = getIntegerInput("Voer het aantal dobbelstenen in: ");
    aantalOgen = getIntegerInput("Voer het aantal ogen op de dobbelsteen in: ");

    Dobbelsteen dobbelsteen(aantalOgen);

    int totaleScore = 0;
    for (int i = 0; i < aantalDobbelstenen; i++) {
        int worp = dobbelsteen.gooi();
        std::cout << "Dobbelsteen " << i + 1 << ": " << worp << std::endl;
        totaleScore += worp;
    }

    std::cout << "Totale score: " << totaleScore << std::endl;

    return 0;
}
