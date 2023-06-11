#ifndef FUNCTIES_H
#define FUNCTIES_H

#include "playcards.h"
#include <vector>
#include <iostream>
#include <string>
#include <zmq.hpp>
#include <algorithm>
#include <cctype>
#include <locale>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "Dobbelsteen.h"
#include "InputUtils.h"
#include "cards.h"



class functies
{
public:
    functies();

    std::string trim(const std::string& str);
    bool equalsIgnoreCase(const std::string& str1, const std::string& str2);
    bool isInteger(const std::string& str);
    int intValue(const std::string& expression);


/*
private:
    const std::string& str;
    const std::string& str2;
    const std::string& expression;
    */
};

#endif // FUNCTIES_H
