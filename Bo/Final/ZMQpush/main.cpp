#include <iostream>
#include <zmq.hpp>
#include <string>
#include <chrono>
#include <thread>
#include <limits>

#ifndef _WIN32
#include <unistd.h>
#else
#define sleep(n) Sleep(n)
#endif

void sendMessage(zmq::socket_t& socket, const std::string& message) {
    zmq::message_t request(message.size());
    memcpy(request.data(), message.data(), message.size());
    socket.send(request, zmq::send_flags::none);
}

std::string receiveMessage(zmq::socket_t& socket) {
    zmq::message_t reply;
    socket.recv(reply, zmq::recv_flags::none);
    return std::string(static_cast<char*>(reply.data()), reply.size());
}

int main() {
    try {
        zmq::context_t context(1);

        zmq::socket_t outgoingSocket(context, ZMQ_PUSH);
        outgoingSocket.connect("tcp://benternet.pxl-ea-ict.be:24041");

        zmq::socket_t incomingSocket(context, ZMQ_SUB);
        incomingSocket.connect("tcp://benternet.pxl-ea-ict.be:24042");
        incomingSocket.setsockopt(ZMQ_SUBSCRIBE, "Game", 4);

        std::string input;
        std::cout << "Enter input: ";
        std::getline(std::cin, input);

        for (int i = 0; i < 2; i++) {
            sendMessage(outgoingSocket, "Gokspel");
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << receiveMessage(incomingSocket) << std::endl;

            std::cout << "Enter input: ";
            std::getline(std::cin, input);
            std::string input2 = "Gokspel<" + input;
            sendMessage(outgoingSocket, input2);
            std::cout << receiveMessage(incomingSocket) << std::endl;

            if (input == "dice" || input == "Dice") {
                std::getline(std::cin, input);
                int numberOfDice = std::stoi(input);

                std::string diceMessage = "Gokspel<Dice<" + std::to_string(numberOfDice);
                sendMessage(outgoingSocket, diceMessage);
                std::cout << receiveMessage(incomingSocket) << std::endl;


                std::getline(std::cin, input);
                int numberOfEyes = std::stoi(input);
                std::string diceEyesMessage = "Gokspel<Dice<" + std::to_string(numberOfDice) + "<" + std::to_string(numberOfEyes);
                sendMessage(outgoingSocket, diceEyesMessage);
                std::cout << receiveMessage(incomingSocket) << std::endl;

                while (numberOfDice  >0)
                {
                    std::cout << receiveMessage(incomingSocket) << std::endl;
                    numberOfDice = numberOfDice - 1;
                }

                std::cout << receiveMessage(incomingSocket) << std::endl;

            }

            if (input == "cards" || input == "Cards") {
                std::getline(std::cin, input);
                int numberOfCards = std:: stoi(input);

                std::string input2 = "Gokspel<cards<" + input;
                sendMessage(outgoingSocket, input2);

                while (numberOfCards >0)
                {
                    std::cout << receiveMessage(incomingSocket) << std::endl;
                    numberOfCards = numberOfCards - 1;
                }

                std::cout << receiveMessage(incomingSocket) << std::endl;

            }
        }

    } catch (zmq::error_t& ex) {
        std::cerr << "Caught an exception: " << ex.what();
    }

    return 0;
}

