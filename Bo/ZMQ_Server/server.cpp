#include "server.h"
#include "cardgame.h"

server::server()
{

    pushSocket->connect( "tcp://localhost:5555" );
    //pushSocket->connect( "tcp://benternet.pxl-ea-ict.be:24041" );
    subscribeSocket->setsockopt( ZMQ_SUBSCRIBE, subscribeTopic.c_str(), subscribeTopic.length());
    //subscribeSocket->connect( "tcp://benternet.pxl-ea-ict.be:24042" );
    subscribeSocket->connect( "tcp://localhost:5555" );


    try
    {

        while(pushSocket->connected() && subscribeSocket->connected())
        {
            //std::cout<<"which topic? ";
            subscribeSocket->recv(zmqBuffer);
            std::string buffer(static_cast<char*>(zmqBuffer->data()), zmqBuffer->size());

            if(buffer.find("Bo>Gambling?") != std::string::npos)
            {
                std::cout<<"received Topic";

                std::string game = "Dice or Cards?";
                pushSocket->send(game.c_str(),game.length());


                subscribeSocket->recv(zmqBuffer);
                std::string buffer(static_cast<char*>(zmqBuffer->data()), zmqBuffer->size());
                std::cout << buffer << std::endl;

                if(buffer == "Dice")
                {
                    std::cout<<subscribeSubTopicCards + "we play dice";
                    subscribeSocket->setsockopt( ZMQ_SUBSCRIBE, subscribeSubTopicDice.c_str(), subscribeSubTopicDice.length());

                }
                else if (buffer == "Cards")
                {
                    std::cout<< subscribeSubTopicDice + "we play cards";
                    subscribeSocket->setsockopt( ZMQ_SUBSCRIBE, subscribeSubTopicCards.c_str(), subscribeSubTopicCards.length());
                    cardgame();
                }
            }
            else
            {
                std::cout<<"wrong topic";
            }





        }
    }
    catch( zmq::error_t & ex )
    {
        std::cerr << "Caught an exception 1 : " << ex.what();
    }



}
