#ifndef ISERIALIZE_H
#define ISERIALIZE_H

#include <QObject>
#include "message.h"

namespace core {

class ISerialize {
public:
    virtual QByteArray Serialize(const Message& message) const = 0;
    virtual ~ISerialize(){}
};

}
#endif // ISERIALIZE_H
