#ifndef ISERIALIZE_H
#define ISERIALIZE_H

#include <QObject>
#include "message.h"

namespace core {

class ISerialize {
public:
    virtual QByteArray Serialize(Message* message) const = 0;
};

}
#endif // ISERIALIZE_H
