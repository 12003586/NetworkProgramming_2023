#include "playcards.h"




playCards::playCards()
{

    functies functie;

    zmq::context_t context(1);

    // Incoming messages come in here
    zmq::socket_t socket(context, ZMQ_SUB);
    socket.connect("tcp://benternet.pxl-ea-ict.be:24042");

    zmq::socket_t socket1(context, ZMQ_PUSH);
    socket1.connect("tcp://benternet.pxl-ea-ict.be:24041");

    srand(static_cast<unsigned int>(time(nullptr))); // Initialize random seed

    zmq::message_t request;
    //socket.recv(request, zmq::recv_flags::none);
    std::string receivedMessage(static_cast<char*>(request.data()), request.size());

    std::string buffer(static_cast<char*>(request.data()), request.size());

    buffer = functie.trim(buffer);


    socket.setsockopt(ZMQ_SUBSCRIBE, "Gokspel<cards", 13);

    zmq::message_t reply1(44);
    memcpy(reply1.data(), "Game<Cards<hoeveel kaarten wilt u trekken?", strlen("Gamee<Cards<hoeveel kaarten wilt u trekken?"));
    socket1.send(reply1, zmq::send_flags::none);

    socket.recv(request, zmq::recv_flags::none);
    buffer = std::string(static_cast<char*>(request.data()), request.size());
    std::cout << "Received buffer inside if: \"" << buffer << "\" (length: " << buffer.length() << ")" << std::endl;

    int numberOfCards = 0;

    numberOfCards = functie.intValue(buffer);
    Deck deck;

    std::vector<std::string> drawnCards;

    for (int i = 0; i < numberOfCards; i++)
    {
        std::string card = deck.drawRandomCard();

        drawnCards.push_back(card);

        std::string output = "Game<Card " + std::to_string(i + 1) + ": " + card;

        zmq::message_t reply2(output.size());
        memcpy(reply2.data(), output.c_str(), output.size());
        socket1.send(reply2, zmq::send_flags::none);

        std::cout << output << std::endl;
    }

    std::string concatenatedCards = "Game<Drawn cards: ";
    for (const auto& card : drawnCards)
    {
        concatenatedCards += card + ", ";
    }

    concatenatedCards = concatenatedCards.substr(0, concatenatedCards.length() - 2);

    zmq::message_t reply3(concatenatedCards.size());
    memcpy(reply3.data(), concatenatedCards.c_str(), concatenatedCards.size());
    socket1.send(reply3, zmq::send_flags::none);

    socket.setsockopt(ZMQ_UNSUBSCRIBE, "Gokspel<cards", 13);
}



