#ifndef MESSAGEBUILDER_H
#define MESSAGEBUILDER_H

#include <QObject>
#include "message.h"

namespace core {

class MessageBuilder
{
public:
    MessageBuilder(const QDateTime& timestamp);

    MessageBuilder& from(const QString& sender);
    MessageBuilder& to(const QString& receiver);
    MessageBuilder& titled(const QString& title);
    MessageBuilder& withContent(const QString& content);
    operator Message();

private:
    Message message;
};



} // core

#endif // MESSAGEBUILDER_H
