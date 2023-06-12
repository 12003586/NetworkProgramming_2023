#ifndef TAROT_H
#define TAROT_H
#include <string>
#include <vector>

class tarot
{
public:
    tarot();
    std::string drawRandomCard();

private:
    std::vector<std::string> tarotCards;

};
std::string vectorToString(const std::vector<std::string>& vec, const std::string& delimiter);

#endif // TAROT_H
