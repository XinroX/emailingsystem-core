#include <gtest/gtest.h>
#include "message.h"
#include "serializer.h"
#include "deserializer.h"
#include "messagebuilder.h"
#include <QDebug>


TEST(MessageTest, MessageCreatedWithNullTitle) {
    core::Message message = core::Message::Create(QDateTime::currentDateTime())
                                .from("Test").to("Test").titled(QString()).withContent("Test");

    ASSERT_TRUE(message.getTitle().isNull());
}

TEST(MessageTest, MessageCreatedWithEmptyTitle) {
    core::Message message = core::Message::Create(QDateTime::currentDateTime())
                                .from("Test").to("Test").titled("").withContent("Test");

    ASSERT_TRUE(message.getTitle().isNull());
}

TEST(MessageTest, MessageCreatedWithValidTitle) {
    core::Message message = core::Message::Create(QDateTime::currentDateTime())
                                .from("Test").to("Test").titled("Test").withContent("Test");

    ASSERT_FALSE(message.getTitle().isNull());
}

TEST(MessageFormatTest, SerializationTest) {
    QDateTime timestamp = QDateTime::currentDateTime();
    core::Message messageBefore = core::Message::Create(timestamp)
                                      .from("Message Sender").to("Message Receiver")
                                      .titled("Message Title").withContent("Message Content");


    core::ISerialize* serializer = new Serializer;
    QByteArray data = serializer->Serialize(messageBefore);
    core::IDeserialize* deserializer = new Deserializer;
    core::Message messageAfter = deserializer->Deserialize(data);

    EXPECT_EQ(messageAfter.getTimestamp().toString(Qt::ISODate), messageBefore.getTimestamp().toString(Qt::ISODate));
    EXPECT_EQ(messageAfter.getSender(), messageBefore.getSender());
    EXPECT_EQ(messageAfter.getReceiver(), messageBefore.getReceiver());
    EXPECT_EQ(messageAfter.getTitle(), messageBefore.getTitle());
    EXPECT_EQ(messageAfter.getContent(), messageBefore.getContent());
}
