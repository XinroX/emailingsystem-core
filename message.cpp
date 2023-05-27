#include "message.h"
#include "messagebuilder.h"

namespace core {



QDateTime Message::getTimestamp() const {
    return mTimestamp;
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

MessageBuilder Message::Create(const QDateTime& timestamp) {
    MessageBuilder builder{timestamp};
    return std::move(builder);
}


} // core

