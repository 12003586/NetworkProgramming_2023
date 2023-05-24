//Service
#include "CardGame.h"
#include "dobbelsteen.h"
#include <QCoreApplication>
#include <iostream>
#include <string>
#include <zmq.hpp>

#ifndef _WIN32
    #include <unistd.h>
#else
    #include <windows.h>
    #define sleep(n)    Sleep(n)
#endif

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    zmq::context_t context(1);

    //Outgoing message go out through here
    zmq::socket_t ventilator( context, ZMQ_PUSH );
//  ventilator.connect( "tcp://localhost:24041" );
    ventilator.connect( "tcp://benternet.pxl-ea-ict.be:24041" );


    //Incoming messages come in here
    zmq::socket_t subscriber( context, ZMQ_SUB );
//  subscriber.connect( "tcp://localhost:24042" );
    subscriber.connect( "tcp://benternet.pxl-ea-ict.be:24042" );
    subscriber.setsockopt( ZMQ_SUBSCRIBE, "Gambling", 8 );

    zmq::message_t * msg = new zmq::message_t();
    while( subscriber.connected() )
   {
        zmq::message_t topic;
        subscriber.recv( topic, zmq::recv_flags::none );

        zmq::message_t msg;
        subscriber.recv(msg, zmq::recv_flags::none);


        if (std::string(static_cast<char*>(topic.data())) == "gambling") {

            ventilator.send("Cards or dice?", 14 );

            // Check the subtopic of the message
            std::string subtopic(static_cast<char*>(msg.data()), msg.size());

            if(subtopic == "cards")
            {
                CardGame game;
                game.play();
            }

            else if(subtopic == "dice")
            {
                Dobbelsteen game;
                game.play();
            }

        }







        std::cout << "Subscribed : [" << std::string( (char*) msg->data(), msg->size() ) << "]" << std::endl;


        ventilator.send("Gambler>>1.Kaarten of 2.Dobblestenen?", 37 );

        subscriber.recv( msg );
        std::cout << "Subscribed : [" << std::string( (char*) msg->data(), msg->size() ) << "]" << std::endl;

    //}

        if(msg = "Kaarten")
        {
            CardGame game;
            game.play();
        }
        else if(msg = "Dobbelsteen")
        {
            Dobbelsteen game;
            game.play();
        }





    return a.exec();
}
