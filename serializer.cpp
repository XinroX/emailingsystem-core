#include "serializer.h"
#include <QFile>

Serializer::Serializer(QObject *parent)
    : QObject{parent}
{

}

QByteArray Serializer::Serialize(core::Message *message) const
{
    QByteArray result;
    QVariantMap map;
    QFile file("test.txt");
    file.open(QIODevice::WriteOnly);
    map["title"] = message->getTitle();
    map["sender"] = message->getSender();
    map["receiver"] = message->getReceiver();
    map["content"] = message->getContent();
    QJsonDocument document = QJsonDocument::fromVariant(map);
    result = document.toJson();
    file.write(document.toJson());

    return result;
}
