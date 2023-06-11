#include "functies.h"

functies::functies()
{


}

std::string functies::trim(const std::string& str)
{
    std::string trimmed = str;

    // Remove leading whitespace
    trimmed.erase(trimmed.begin(), std::find_if(trimmed.begin(), trimmed.end(), [](int ch) {
        return !std::isspace(ch);
    }));

    // Remove trailing whitespace
    trimmed.erase(std::find_if(trimmed.rbegin(), trimmed.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), trimmed.end());

    // Remove null characters
    trimmed.erase(std::remove(trimmed.begin(), trimmed.end(), '\0'), trimmed.end());

    return trimmed;
}

// Case-insensitive string comparison
bool functies::equalsIgnoreCase(const std::string& str1, const std::string& str2)
{
    return std::equal(str1.begin(), str1.end(), str2.begin(), str2.end(),
                      [](char ch1, char ch2) {
        return std::tolower(ch1) == std::tolower(ch2);
    });
}

bool functies::isInteger(const std::string& str)
{
    return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
}

int functies::intValue(const std::string& expression)
{
    size_t lastLessThanPos = expression.find_last_of('<');
    std::string numberStr = expression.substr(lastLessThanPos + 1);

    int value;
    std::stringstream ss(numberStr);
    if (!(ss >> value)) {
        std::cerr << "Invalid number format: " << numberStr << std::endl;
        // Return a default value or throw an exception, depending on your requirements
    }

    // Return the extracted integer
    return value;
}
