#include "card.h"

card::card()
{
    pushSocket->connect( "tcp://benternet.pxl-ea-ict.be:24041" );
    subscribeSocket->setsockopt( ZMQ_SUBSCRIBE, subscribeSubTopicCards.c_str(), subscribeSubTopicCards.length());
    subscribeSocket->connect( "tcp://benternet.pxl-ea-ict.be:24042" );

    try {

        while(pushSocket->connected())
        {
            subscribeSocket->recv(zmqBuffer);
            std::string buffer(static_cast<char*>(zmqBuffer->data()), zmqBuffer->size());

            if(buffer.find("Do you want to continu or go back?") != std::string::npos);
            {
                std::string continu;
                std::cin>>continu;
                pushSocket->send(continu.c_str(), continu.length());

                subscribeSocket->recv(zmqBuffer);
                std::string buffer(static_cast<char*>(zmqBuffer->data()), zmqBuffer->size());
                std::cout<< subscribeSubTopicCards + buffer;

            }
        }
    }
    catch( zmq::error_t & ex )
    {
        std::cerr << "Caught an exception : " << ex.what();
    }
}
