#ifndef SERVER_H
#define SERVER_H
#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QtNetwork>
#include <QDebug>
#include <QTimer>
#include <set>
#include <zmq.hpp>


class server : public QObject
{
    Q_OBJECT
public:
    server();
    void kaarten(QString);
    void dobbelsteen(QString);

    // Gets the length of subscribeTopic
    int getSubscribeTopicLen(void)
    {
        return subscribeTopic.length();
    }

    // Gets the length of pushTopic
    int getPushTopicLen(void)
    {
        return pushTopic.length();
    }

signals:
    // Signal used to receive messages
    void messageReceived(QString);

private:
    // Self explanatory naming.
    zmq::context_t *context = new zmq::context_t(1);
    zmq::message_t *zmqBuffer  = new zmq::message_t();
    zmq::socket_t *pushSocket = new zmq::socket_t(*context, ZMQ_PUSH);
    zmq::socket_t *subSocket = new zmq::socket_t(*context, ZMQ_SUB);

    std::string subscribeTopic = "Gambling>";
    std::string pushTopic = "Gambler>";

    QMap<QString, QString> idNameMap;

    QSocketNotifier *notifier;
    QTimer* alertTimer;
};



#endif // SERVER_H
