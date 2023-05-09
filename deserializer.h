#ifndef DESERIALIZER_H
#define DESERIALIZER_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>

#include "ideserialize.h"

class Deserializer : public QObject, public core::IDeserialize
{
    Q_OBJECT
public:
    explicit Deserializer(QObject *parent = nullptr);
    virtual core::Message* Deserialize(const QByteArray& message) const override;

signals:

};

#endif // DESERIALIZER_H
