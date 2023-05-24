#include "Dobbelsteen.h"
#include "InputUtils.h"
#include <iostream>
#include <zmq.hpp>

zmq::context_t context(1);

//Outgoing message go out through here
zmq::socket_t ventilator( context, ZMQ_PUSH );



//Incoming messages come in here
zmq::socket_t subscriber( context, ZMQ_SUB );



Dobbelsteen::Dobbelsteen(int numEyes) : gen(rd()), dis(1, numEyes) {}

int Dobbelsteen::gooi() {
    return dis(gen);
}


void Dobbelsteen::play()
{

    ventilator.send("How many dice?", 14);

    zmq::message_t numDiceMsg;
    subscriber.recv(numDiceMsg, zmq::recv_flags::none);

    int numDice = *static_cast<int*>(numDiceMsg.data());


    ventilator.send("How many eyes?", 14);
    zmq::message_t numEyesMsg;
    subscriber.recv(numEyesMsg, zmq::recv_flags::none);

    int numEyes = *static_cast<int*>(numEyesMsg.data());



    //int aantalDobbelstenen, aantalOgen;

    //aantalDobbelstenen = getIntegerInput("Voer het aantal dobbelstenen in: ");
    //aantalOgen = getIntegerInput("Voer het aantal ogen op de dobbelsteen in: ");

    Dobbelsteen dobbelsteen(numEyes);

    int totaleScore = 0;
    for (int i = 0; i < numDice; i++) {
        int worp = dobbelsteen.gooi();
        std::cout << "Dobbelsteen " << i + 1 << ": " << worp << std::endl;
        totaleScore += worp;
    }

    std::cout << "Totale score: " << totaleScore << std::endl;
    ventilator.send(totaleScore, zmq::send_flags::sndmore);


}
