#include "playdice.h"




playDice::playDice()
{
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


    functies functie;

    buffer = functie.trim(buffer);


    socket.setsockopt(ZMQ_SUBSCRIBE, "Gokspel<dice", 12);
    std::cout << "Dice" << std::endl;

    zmq::message_t reply1(32);
    memcpy(reply1.data(), "Gamee<Dice<Hoeveel dobbelstenen?", strlen("Gamee>Dice<Hoeveel dobbelstenen?"));
    socket1.send(reply1, zmq::send_flags::none);

    socket.recv(request, zmq::recv_flags::none);
    buffer = std::string(static_cast<char*>(request.data()), request.size());
    std::cout << "Received buffer inside if: \"" << buffer << "\" (length: " << buffer.length() << ")" << std::endl;

    int waarde1 = functie.intValue(buffer);
    std::cout<< waarde1 << std::endl;

    zmq::message_t reply2(41);
    memcpy(reply2.data(), "Game<Dice<Aantal ogen op de dobbelsteen?", strlen("Gamee<Dice<Aantal ogen op de dobbelsteen?"));
    socket1.send(reply2, zmq::send_flags::none);

    socket.recv(request, zmq::recv_flags::none);
    buffer = std::string(static_cast<char*>(request.data()), request.size());
    std::cout << "Received buffer inside if: \"" << buffer << "\" (length: " << buffer.length() << ")" << std::endl;

    int waarde2 = functie.intValue(buffer);
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

    socket.setsockopt(ZMQ_UNSUBSCRIBE, "Gokspel<dice", 12);

}


