#include "server.h"

server::server()
{
    pushSocket->connect("tcp://benternet.pxl-ea-ict.be:24041");

    subSocket->setsockopt(ZMQ_SUBSCRIBE, subscribeTopic.c_str(), subscribeTopic.length());
    subSocket->connect("tcp://benternet.pxl-ea-ict.be:24042");
}

server::~server()
{
    delete context;
    delete zmqBuffer;
    delete pushSocket;
    delete subSocket;
    delete notifier;
    delete alertTimer;
}


void server::kaarten(QString)
{

}
