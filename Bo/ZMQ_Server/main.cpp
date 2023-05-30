#include <QCoreApplication>
#include "server.h"
#include <QObject>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    server();

    return a.exec();
}
