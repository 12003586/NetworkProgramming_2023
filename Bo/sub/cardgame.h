#ifndef CARDGAME_H
#define CARDGAME_H

#include <string>
#include <vector>
#include <zmq.hpp>

class CardGame {
public:
    CardGame();
    void play();

private:
    int askNumberOfCards();
    std::string askColor();
    std::string askSymbol();
    std::vector<std::pair<std::string, std::string>> generateCards(int numCards, const std::string& color, const std::string& symbol);
    void printCards(const std::vector<std::pair<std::string, std::string>>& cards);

    std::vector<std::string> colors;
    std::vector<std::string> symbols;
};

#endif  // CARDGAME_H
