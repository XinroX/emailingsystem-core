#include "deserializer.h"
#include "messagebuilder.h"

Deserializer::Deserializer(QObject *parent)
    : QObject{parent}
{

}

core::Message Deserializer::Deserialize(const QByteArray& message) const
{


    QString title = QString(), sender = QString(), receiver = QString(), content = QString();
    QDateTime timestamp;

    QJsonDocument document = QJsonDocument::fromJson(message);

    timestamp = QDateTime::fromString(document["timestamp"].toString(), Qt::DateFormat::ISODate);
    title = document["title"].toString();
    sender = document["sender"].toString();
    receiver = document["receiver"].toString();
    content = document["content"].toString();

    if (sender.isNull() or sender.isEmpty() or receiver.isNull() or receiver.isEmpty() or
        content.isNull() or content.isEmpty())
        throw std::runtime_error("Invalid message format");

    core::Message result = core::Message::Create(timestamp).from(sender).to(receiver).titled(title).withContent(content);
    return std::move(result);


}
