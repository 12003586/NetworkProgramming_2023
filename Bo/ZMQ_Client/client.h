#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <string>
#include <zmq.hpp>
#include <cstdlib>
#include <QObject>
#include <QString>




class client
{
public:
    client();

private:
    std::string subscribeTopic          = "Bo>Gambling?>";
    std::string subscribeSubTopicDice   = "Bo>Gambling>Dice?>";
    std::string subscribeSubTopicCards  = "Bo>Gambling>Cards?>";
    std::string pushTopic               = "Bo>Gambling!>";
    zmq::context_t *context             = new zmq::context_t(1);
    zmq::message_t *zmqBuffer           = new zmq::message_t();
    zmq::socket_t *pushSocket           = new zmq::socket_t(*context, ZMQ_PUSH);
    zmq::socket_t *subSocket            = new zmq::socket_t(*context, ZMQ_SUB);
};

#endif // CLIENT_H
