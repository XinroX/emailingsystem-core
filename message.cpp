#include "message.h"


core::Message::Message(const QString &title, const QString &sender, const QString &receiver,
                       const QString &content, QObject *parent)
    : mSender{sender}, mReceiver{receiver}, mContent{content}, QObject(parent)
{
    if (title.isNull() or title.isEmpty())
        mTitle = QString();
}
