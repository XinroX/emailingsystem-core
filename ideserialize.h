#ifndef IDESERIALIZE_H
#define IDESERIALIZE_H

#include "message.h"

namespace core {

class IDeserialize {
public:
    virtual Message Deserialize(const QByteArray& message) const = 0;
    virtual ~IDeserialize(){}
};

}

#endif // IDESERIALIZE_H
