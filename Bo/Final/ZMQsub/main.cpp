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

#include "playdice.h"
#include "playcards.h"
#include "functies.h"

#ifndef _WIN32
#include <unistd.h>
#else
#include <windows.h>
#define sleep(n)    Sleep(n)
#endif

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

        functies functie;

        while (true)
        {
            zmq::message_t request;
            socket.recv(request, zmq::recv_flags::none);
            std::string receivedMessage(static_cast<char*>(request.data()), request.size());
            std::cout << "Received: [" << receivedMessage << "]" << std::endl;

            sleep(1);

            zmq::message_t reply(19);
            memcpy(reply.data(), "Game<Dice or cards?", sizeof("Game<Dice or cards?"));
            socket1.send(reply, zmq::send_flags::none);

            socket.recv(request, zmq::recv_flags::none);
            std::string buffer(static_cast<char*>(request.data()), request.size());
            std::cout << "Buffer: \"" << buffer << "\"" << std::endl;

            buffer = functie.trim(buffer);

            if (functie.equalsIgnoreCase(buffer, "Gokspel<Dice") || functie.equalsIgnoreCase(buffer, "Gokspel<dice"))
            {
                playDice();
            }
            else if (functie.equalsIgnoreCase(buffer, "Gokspel<Cards") || functie.equalsIgnoreCase(buffer, "Gokspel<cards"))
            {
                playCards();
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



