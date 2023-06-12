#include "Dobbelsteen.h"

Dobbelsteen::Dobbelsteen(int aantalOgen) : gen(rd()), dis(1, aantalOgen) {}

int Dobbelsteen::gooi() {
    return dis(gen);
}
