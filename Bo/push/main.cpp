#include <QCoreApplication>
#include <zmq.hpp>
#include <QString>
#include <stdlib.h>
#include <iostream>
#include <QObject>
#include <QString>

#ifndef _WIN32
    #include <unistd.h>
#else
    #include <windows.h>
    #define sleep(n)    Sleep(n)
#endif
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

        QString standardPrefix("Dobbelsteen");

        zmq::context_t context(1);

        //Outgoing message go out through here
        zmq::socket_t ventilator( context, ZMQ_PUSH );
//      ventilator.connect( "tcp://localhost:24041" );
        ventilator.connect( "tcp://benternet.pxl-ea-ict.be:24041" );

        //Incoming messages come in here
        zmq::socket_t subscriber( context, ZMQ_SUB );
    //  subscriber.connect( "tcp://localhost:24042" );
        subscriber.connect( "tcp://benternet.pxl-ea-ict.be:24042" );
        subscriber.setsockopt( ZMQ_SUBSCRIBE, "Dobbelsteen1", 12 );

        zmq::message_t * msg = new zmq::message_t();

        std::string str_compare("Dobbelsteen");
        std::string input("");


        std::cin >> input;

        int choice = str_compare.compare(input);

        switch (choice) {
        case 0:
        {
            ventilator.send( "Dobbelsteen<<Dobbelsteentest", 29 );
            std::cout << "Pushed : [Dobbelsteen]" << std::endl;



            break;
        }
        default:
            std::cout << "error try again" << std::endl;
        }

        sleep(10);

        subscriber.recv( msg );
        std::cout << std::string( (char*) msg->data(), msg->size() ) << std::endl;







    return a.exec();
}
