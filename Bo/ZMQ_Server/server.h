#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <zmq.hpp>
#include <QObject>
#include <QString>
#ifndef _WIN32
    #include <unistd.h>
#else
    #include <windows.h>
    #define sleep(n)    Sleep(n)
#endif


class server
{
public:
    server();

private:
    std::string pushSubTopicDice        = "Bo>Gambling>Dice!>";
    std::string pushSubTopicCards       = "Bo>Gambling>Cards!>";
    std::string subscribeTopic          = "Bo>Gambling!>";
    std::string subscribeSubTopicDice   = "Bo>Gambling>Dice?>";
    std::string subscribeSubTopicCards  = "Bo>Gambling>Cards?>";
    std::string pushTopic               = "Bo>Gambling?>";
    zmq::context_t *context             = new zmq::context_t(1);
    zmq::message_t *zmqBuffer           = new zmq::message_t();
    zmq::socket_t *pushSocket           = new zmq::socket_t ( *context, ZMQ_PUSH );
    zmq::socket_t *subscribeSocket      = new zmq::socket_t ( *context, ZMQ_SUB );


};

#endif // SERVER_H
