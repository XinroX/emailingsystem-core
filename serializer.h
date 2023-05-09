#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include "ISerialize.h"

class Serializer : public QObject, public core::ISerialize
{
    Q_OBJECT
public:
    explicit Serializer(QObject *parent = nullptr);

    virtual QByteArray Serialize(core::Message* message) const override;

signals:

};

#endif // SERIALIZER_H
