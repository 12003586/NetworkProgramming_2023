#ifndef KAARTEN_H
#define KAARTEN_H

#include <QCoreApplication>
#include <QRandomGenerator>
#include <QStringList>
#include <iostream>

class kaarten
{
public:
    kaarten(int numCards) : numCards_(numCards) {}



    QStringList pickCards()
    {
        // Generate random cards
        QString suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
        QString ranks[] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };

        QStringList cards;

        for (int i = 0; i < numCards_; i++) {
            int suitIndex = QRandomGenerator::global()->bounded(4);
            int rankIndex = QRandomGenerator::global()->bounded(13);

            QString card = ranks[rankIndex] + " of " + suits[suitIndex];
            cards.append(card);
        }

        return cards;
    }

private:
    int numCards_;
};

#endif // KAARTEN_H


/*
    // Ask the user for the number of cards
    int numCards;
    std::cout << "How many cards do you want to draw? ";
    std::cin >> numCards;

    kaarten picker(numCards);
    QStringList cards = picker.pickCards();

    // Print the drawn cards
    std::cout << "Drawn Cards:";
    for (const QString &card : cards) {
        std::cout << card.toStdString() << std::endl;
    }

*/
