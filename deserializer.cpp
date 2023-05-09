#include "deserializer.h"

Deserializer::Deserializer(QObject *parent)
    : QObject{parent}
{

}

core::Message* Deserializer::Deserialize(const QByteArray& message) const
{


    QString title = QString(), sender = QString(), receiver = QString(), content = QString();

    QJsonDocument document = QJsonDocument::fromJson(message);

    title = document["title"].toString();
    sender = document["sender"].toString();
    receiver = document["receiver"].toString();
    content = document["content"].toString();

    if (sender.isNull() or sender.isEmpty() or receiver.isNull() or receiver.isEmpty() or
        content.isNull() or content.isEmpty())
        return nullptr;

    core::Message* result = new core::Message{title, sender, receiver, content};
    return result;


}
