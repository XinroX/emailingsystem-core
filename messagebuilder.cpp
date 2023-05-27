#include "messagebuilder.h"

namespace core {

MessageBuilder::MessageBuilder(const QDateTime& timestamp)
{
    message.mTimestamp = timestamp;
}

MessageBuilder& MessageBuilder::from(const QString& sender) {
    message.mSender = sender;
    return *this;
}

MessageBuilder& MessageBuilder::to(const QString& receiver) {
    message.mReceiver = receiver;
    return *this;
}

MessageBuilder& MessageBuilder::titled(const QString& title) {
    if (title.isEmpty() || title.isNull()) message.mTitle = QString();
    else message.mTitle = title;
    return *this;
}

MessageBuilder& MessageBuilder::withContent(const QString& content) {
    message.mContent = content;
    return *this;
}

MessageBuilder::operator Message() {
    return std::move(message);
}

} // core
