#ifndef DOBBELSTEEN_H
#define DOBBELSTEEN_H

#include <random>
#include <iostream>
#include <string>
#include <algorithm>


class Dobbelsteen {
public:
    Dobbelsteen(int numEyes);
    int gooi();

    Dobbelsteen();
    void play();

private:
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> dis;
};

#endif
