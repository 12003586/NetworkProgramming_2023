#ifndef CARD_H
#define CARD_H
#include "server.h"
#include <cstdlib>
#include <ctime>

enum Rank {
    ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
};

enum Suit {
    CLUBS, DIAMONDS, HEARTS, SPADES
};

struct Card {
    Rank rank;
    Suit suit;
};

void printCard(const Card& card);
Card getRandomCard();

std::string generatedCard;

class card
{




public:
    card();





private:

    int askNumberOfCards;
    std::vector<std::string> colors;
    std::vector<std::string> symbols;


    std::string subscribeSubTopicCards  = "Bo>Gambling>Cards?>";
    std::string pushSubTopicCards       = "Bo>Gambling>Cards!>";
    std::string pushTopic               = "Bo>Gambling?>";
    zmq::context_t *context             = new zmq::context_t(1);
    zmq::message_t *zmqBuffer           = new zmq::message_t();
    zmq::socket_t *pushSocket           = new zmq::socket_t ( *context, ZMQ_PUSH );
    zmq::socket_t *subscribeSocket      = new zmq::socket_t ( *context, ZMQ_SUB );



};

#endif // CARD_H
