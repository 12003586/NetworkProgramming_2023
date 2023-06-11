#include "cards.h"
#include <cstdlib>
#include <ctime>

Deck::Deck() {
    suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
    ranks = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    srand(time(0)); // Initialize random seed
}

std::string Deck::drawRandomCard() {
    std::string suit = suits[rand() % suits.size()];
    std::string rank = ranks[rand() % ranks.size()];
    return rank + " of " + suit;
}

std::string vectorToString(const std::vector<std::string>& vec, const std::string& delimiter) {
    std::string result;
    for (size_t i = 0; i < vec.size(); ++i) {
        result += vec[i];
        if (i != vec.size() - 1) {
            result += delimiter;
        }
    }
    return result;
}
