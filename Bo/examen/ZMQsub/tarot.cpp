#include "tarot.h"

tarot::tarot()
{
    tarotCards = {"The Fool", "The Juggler", "The Popess", "The Epress", "The emperor", "The Pope", "The Lovers", "The Chariot", "Justice", "The Hermit", "The Wheel of Fortune", "Strength", "The Hanged Man", "Death", "Temperance", "The Devil", "The House of God", "The Star", "The Moon", "The Sun", "Judgement","The World"};
}

std::string tarot::drawRandomCard()
{
    std::string tCards = tarotCards[rand() % tarotCards.size()];
    return tCards;
}
