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
#include "tarot.h"

#ifndef _WIN32
#include <unistd.h>
#else
#include <windows.h>
#define sleep(n)    Sleep(n)
#endif

std::string trim(const std::string& str)
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
bool equalsIgnoreCase(const std::string& str1, const std::string& str2)
{
    return std::equal(str1.begin(), str1.end(), str2.begin(), str2.end(),
                      [](char ch1, char ch2) {
        return std::tolower(ch1) == std::tolower(ch2);
    });
}

bool isInteger(const std::string& str)
{
    return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
}

int intValue(const std::string& expression)
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

int main()
{
    try
    {
        zmq::context_t context(1);

        // Incoming messages come in here
        zmq::socket_t socket(context, ZMQ_SUB);
        socket.connect("tcp://benternet.pxl-ea-ict.be:24042");
        socket.setsockopt(ZMQ_SUBSCRIBE, "Gokspel", 7);

        zmq::socket_t socket1(context, ZMQ_PUSH);
        socket1.connect("tcp://benternet.pxl-ea-ict.be:24041");

        srand(static_cast<unsigned int>(time(nullptr))); // Initialize random seed

        while (true)
        {
            zmq::message_t request;
            socket.recv(request, zmq::recv_flags::none);
            std::string receivedMessage(static_cast<char*>(request.data()), request.size());
            std::cout << "Received: [" << receivedMessage << "]" << std::endl;

            sleep(1);

            zmq::message_t reply(28);
            memcpy(reply.data(), "Game<Dice or cards or tarot?", sizeof("Game<Dice or cards or tarot?"));
            socket1.send(reply, zmq::send_flags::none);

            socket.recv(request, zmq::recv_flags::none);
            std::string buffer(static_cast<char*>(request.data()), request.size());
            std::cout << "Buffer: \"" << buffer << "\"" << std::endl;

            buffer = trim(buffer);

            if (equalsIgnoreCase(buffer, "Gokspel<Dice") || equalsIgnoreCase(buffer, "Gokspel<dice"))
            {
                socket.setsockopt(ZMQ_SUBSCRIBE, "Gokspel<dice", 12);
                std::cout << "Dice" << std::endl;

                zmq::message_t reply1(32);
                memcpy(reply1.data(), "Gamee<Dice<Hoeveel dobbelstenen?", strlen("Gamee>Dice<Hoeveel dobbelstenen?"));
                socket1.send(reply1, zmq::send_flags::none);

                socket.recv(request, zmq::recv_flags::none);
                buffer = std::string(static_cast<char*>(request.data()), request.size());
                std::cout << "Received buffer inside if: \"" << buffer << "\" (length: " << buffer.length() << ")" << std::endl;

                int waarde1 = intValue(buffer);
                std::cout<< waarde1 << std::endl;

                zmq::message_t reply2(41);
                memcpy(reply2.data(), "Game<Dice<Aantal ogen op de dobbelsteen?", strlen("Gamee<Dice<Aantal ogen op de dobbelsteen?"));
                socket1.send(reply2, zmq::send_flags::none);

                socket.recv(request, zmq::recv_flags::none);
                buffer = std::string(static_cast<char*>(request.data()), request.size());
                std::cout << "Received buffer inside if: \"" << buffer << "\" (length: " << buffer.length() << ")" << std::endl;

                int waarde2 = intValue(buffer);
                std::cout<< waarde2 << std::endl;

                Dobbelsteen dobbelsteen(waarde2);


                int totaleScore = 0;

                for (int i = 0; i < waarde1; i++) {
                    int worp = dobbelsteen.gooi();
                    totaleScore += worp;

                    std::string output = "Game< dobbelsteen " + std::to_string(i) + ": " + std::to_string(worp);

                    output = std::string(output);

                    zmq::message_t reply3(output.size());
                    memcpy(reply3.data(), output.c_str(), output.size());
                    socket1.send(reply3, zmq::send_flags::none);

                    std::cout << output << std::endl;

                }
                std::cout << totaleScore << std::endl;
                std:: string output2 = "Game< totaal gegooid " + std::to_string(totaleScore);

                zmq::message_t reply4(output2.size());
                memcpy(reply4.data(), output2.c_str(), output2.size());
                socket1.send(reply4, zmq::send_flags::none);

            }
            else if (equalsIgnoreCase(buffer, "Gokspel<Cards") || equalsIgnoreCase(buffer, "Gokspel<cards"))
            {
                socket.setsockopt(ZMQ_SUBSCRIBE, "Gokspel<cards", 13);

                zmq::message_t reply1(26);
                memcpy(reply1.data(), "Game<Cards<hoeveel handen?", strlen("Game<Cards<hoeveel handen?"));
                socket1.send(reply1, zmq::send_flags::none);

                socket.recv(request, zmq::recv_flags::none);
                buffer = std::string(static_cast<char*>(request.data()), request.size());
                std::cout << "Received buffer inside if: \"" << buffer << "\" (length: " << buffer.length() << ")" << std::endl;

                int numberOfHands = 0;
                int numberOfCards = 0;

                numberOfHands = intValue(buffer);

                for(int j = 0; j <= numberOfHands; j++)
                {
                    zmq::message_t reply5(27);
                    memcpy(reply5.data(), "Game<Cards<hoeveel kaarten?", strlen("Game<Cards<hoeveel kaarten?"));
                    socket1.send(reply5, zmq::send_flags::none);

                    socket.recv(request, zmq::recv_flags::none);
                    std::string bufferCards = std::string(static_cast<char*>(request.data()), request.size());
                    std::cout << "Received buffer inside if: \"" << bufferCards << "\" (length: " << bufferCards.length() << ")" << std::endl;

                    numberOfCards = intValue(bufferCards);
                }

                Deck deck;

                std::vector<std::string> drawnCards;

                for(int j = 0; j< numberOfHands; j++)
                {

                for (int i = 0; i < numberOfCards; i++)
                {
                        std::string card = deck.drawRandomCard();

                        drawnCards.push_back(card);

                        std::string output = "Game<Hand<" + std::to_string(j) + "Card " + std::to_string(i + 1) + ": " + card;

                        zmq::message_t reply2(output.size());
                        memcpy(reply2.data(), output.c_str(), output.size());
                        socket1.send(reply2, zmq::send_flags::none);

                        std::cout << output << std::endl;
                    }

                    std::string concatenatedCards = "Game<Hand<" + std::to_string(j) + "Drawn cards: ";
                    for (const auto& card : drawnCards)
                    {
                        concatenatedCards += card + ", ";
                    }

                    concatenatedCards = concatenatedCards.substr(0, concatenatedCards.length() - 2);

                    zmq::message_t reply3(concatenatedCards.size());
                    memcpy(reply3.data(), concatenatedCards.c_str(), concatenatedCards.size());
                    socket1.send(reply3, zmq::send_flags::none);
                }
            }

            else if (equalsIgnoreCase(buffer, "Gokspel<Tarot") || equalsIgnoreCase(buffer, "Gokspel<tarot"))
            {
                socket.setsockopt(ZMQ_SUBSCRIBE, "Gokspel<Tarot", 13);


                tarot Tarot;

                std::vector<std::string> drawnTarotCards;        

                std::string card = Tarot.drawRandomCard();
                drawnTarotCards.push_back(card);

                std::string outputTarot = "Game<Gokspel<Tarot : " + card;

                zmq::message_t reply4(outputTarot.size());
                memcpy(reply4.data(), outputTarot.c_str(), outputTarot.size());
                socket1.send(reply4, zmq::send_flags::none);

                std::cout<< outputTarot << std::endl;


            }
            else
            {
                std::cerr << "Invalid input: " << buffer << std::endl;
                // Handle the error accordingly
                continue;  // Move to the next iteration of the loop
            }
        }
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Exception occurred: " << ex.what() << std::endl;
        // Handle the exception accordingly
        return 1;  // Return with an error code
    }

    return 0;
}

