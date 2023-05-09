#include "message.h"

namespace core {
Message::Message(const QString &title, const QString &sender, const QString &receiver,
                       const QString &content, QObject *parent)
    : mSender{sender}, mReceiver{receiver}, mContent{content}, QObject(parent)
{
    if (title.isNull() || title.isEmpty())
        mTitle = QString();
}

QString Message::getTitle() const {
    return mTitle;
}

QString Message::getSender() const {
    return mSender;
}

QString Message::getReceiver() const {
    return mReceiver;
}

QString Message::getContent() const {
    return mContent;
}

}

