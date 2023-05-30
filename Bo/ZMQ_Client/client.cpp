#include "client.h"

client::client()
{
    //subSocket->connect( "tcp://benternet.pxl-ea-ict.be:24042" );
    pushSocket->connect( "tcp://localhost:5555" );

    //pushSocket->connect( "tcp://benternet.pxl-ea-ict.be:24041" );
    subSocket->setsockopt( ZMQ_SUBSCRIBE, subscribeTopic.c_str(), subscribeTopic.length());
    //pushSocket->setsockopt(ZMQ_PUSH,pushTopic.c_str(),subscribeTopic.length());
    subSocket->connect( "tcp://localhost:5555" );

    try
    {
        zmq::message_t * msg = new zmq::message_t();
        while (pushSocket->connected() && subSocket->connected())
        {
            std::cout<<"which topic? ";
            std::string inputTopic = "Bo>Gambling?";
            //std::cin>> inputTopic;
            pushSocket->send(inputTopic.c_str(),inputTopic.length());
            std::cout << inputTopic << std::endl;


            subSocket->recv(msg);
            std::string buffer(static_cast<char*>(msg->data()),msg->size());

            if(buffer.find("Dice or Cards?") != std::string::npos)
            {
                std::cout<<"Dice or Cards?" << std::endl;

                std::string input;
                std::cin>>input;
                pushSocket->send(input.c_str(), input.length());
            }


        }
    }
    catch( zmq::error_t & ex )
    {
        std::cerr << "Caught an exception : " << ex.what();
    }
}
