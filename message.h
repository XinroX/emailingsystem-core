#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include <QDateTime>

namespace core {
class MessageBuilder;
class Message
{
public:

    static MessageBuilder Create(const QDateTime& timestamp);

    QDateTime getTimestamp() const;
    QString getTitle() const;
    QString getSender() const;
    QString getReceiver() const;
    QString getContent() const;

private:
    friend class MessageBuilder;
    QDateTime mTimestamp;
    QString mTitle;
    QString mSender;
    QString mReceiver;
    QString mContent;
};
}

#endif // MESSAGE_H
