#include "InputUtils.h"
#include <iostream>
#include <limits>

int getIntegerInput(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            if (value > 0) {
                break;
            } else {
                std::cout << "Ongeldige invoer. Voer een positief getal in." << std::endl;
            }
        } else {
            std::cout << "Ongeldige invoer. Voer een geldig geheel getal in." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return value;
}
