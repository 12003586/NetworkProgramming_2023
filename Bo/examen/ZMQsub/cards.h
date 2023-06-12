#ifndef CARDS_H
#define CARDS_H

#include <string>
#include <vector>

class Deck {
private:
    std::vector<std::string> suits;
    std::vector<std::string> ranks;

public:
    Deck();
    std::string drawRandomCard();
};

std::string vectorToString(const std::vector<std::string>& vec, const std::string& delimiter);

#endif
