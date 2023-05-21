#include <iostream>
#include <random>
#include <algorithm>
#include "CardGame.h"

CardGame::CardGame() {
    colors = { "Harten", "Ruiten", "Klaveren", "Schoppen" };
    symbols = { "Aas", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Boer", "Vrouw", "Heer" };
}

void CardGame::play() {
    int numCards = askNumberOfCards();
    std::string color = askColor();
    std::string symbol = askSymbol();

    std::vector<std::pair<std::string, std::string>> cards = generateCards(numCards, color, symbol);

    if (!cards.empty()) {
        std::cout << "\nDe getrokken kaarten zijn:\n";
        printCards(cards);
    } else {
        std::cout << "\nEr zijn geen kaarten beschikbaar voor de opgegeven keuzes.\n";
    }
}

int CardGame::askNumberOfCards() {
    int num;
    while (true) {
        std::cout << "Hoeveel kaarten wil je trekken? ";
        std::cin >> num;

        if (num > 0) {
            return num;
        } else {
            std::cout << "Voer een positief getal in.\n";
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::string CardGame::askColor() {
    std::string color;
    while (true) {
        std::cout << "Welke kleur wil je? (Harten, Ruiten, Klaveren, Schoppen) ";
        std::cin >> color;

        auto it = std::find(colors.begin(), colors.end(), color);
        if (it != colors.end()) {
            return color;
        } else {
            std::cout << "Ongeldige kleur. Kies uit Harten, Ruiten, Klaveren of Schoppen.\n";
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::string CardGame::askSymbol() {
    std::string symbol;
    while (true) {
        std::cout << "Welk symbool wil je? (Aas, 2, 3, ..., 10, Boer, Vrouw, Heer) ";
        std::cin >> symbol;

        auto it = std::find(symbols.begin(), symbols.end(), symbol);
        if (it != symbols.end()) {
            return symbol;
        } else {
            std::cout << "Ongeldig symbool. Kies uit Aas, 2, 3, ..., 10, Boer, Vrouw of Heer.\n";
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::vector<std::pair<std::string, std::string>> CardGame::generateCards(int numCards, const std::string& color, const std::string& symbol) {
    std::vector<std::pair<std::string, std::string>> availableCards;
    for (const auto& c : colors) {
        for (const auto& s : symbols) {
            availableCards.emplace_back(c, s);
        }
    }

    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(availableCards.begin(), availableCards.end(), rng);

    std::vector<std::pair<std::string, std::string>> selectedCards;
    for (const auto& card : availableCards) {
        if (card.first == color && card.second == symbol) {
            selectedCards.push_back(card);
            if (selectedCards.size() == numCards) {
                break;
            }
        }
    }

    return selectedCards;
}

