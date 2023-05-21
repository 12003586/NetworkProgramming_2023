#ifndef DOBBELSTEEN_H
#define DOBBELSTEEN_H

#include <random>

class Dobbelsteen {
public:
    Dobbelsteen(int aantalOgen);
    int gooi();

private:
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> dis;
};

#endif
