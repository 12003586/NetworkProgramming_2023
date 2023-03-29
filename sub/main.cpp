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
    subscriber.setsockopt( ZMQ_SUBSCRIBE, "Dobbelsteen", 11 );

    zmq::message_t * msg = new zmq::message_t();
   // while( subscriber.connected() )
   // {
        subscriber.recv( msg );
        std::cout << "Subscribed : [" << std::string( (char*) msg->data(), msg->size() ) << "]" << std::endl;


        ventilator.send("Dobbelsteen1<<Hoeveel dobbelstenen?", 35 );

    //}

    return a.exec();
}
