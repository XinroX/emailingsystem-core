#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
namespace core {

class Message : public QObject
{
    Q_OBJECT
public:
    explicit Message(const QString& title, const QString& sender, const QString& receiver,
                     const QString& content, QObject *parent = nullptr);

    QString getTitle() const;
    QString getSender() const;
    QString getReceiver() const;
    QString getContent() const;
signals:

private:
    QString mTitle;
    QString mSender;
    QString mReceiver;
    QString mContent;
};
}

#endif // MESSAGE_H
