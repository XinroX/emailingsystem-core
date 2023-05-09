#include <gtest/gtest.h>
#include "message.h"
#include "serializer.h"
#include "deserializer.h"
#include <iostream>

class MessageFormatTest : public ::testing::Test {
protected:
    void SetUp() override {
        messageBefore = new core::Message{"Message Title", "Message Sender", "Message Receiver", "Message Content"};
        serializer = new Serializer;
        deserializer = new Deserializer;
    }

    void TearDown() override {
        delete messageBefore;
        if (messageAfter != nullptr) {
            delete messageAfter;
            messageAfter = nullptr;
        }
        delete serializer;
        delete deserializer;
    }
    core::ISerialize* serializer = nullptr;
    core::IDeserialize* deserializer = nullptr;
    core::Message* messageBefore = nullptr;
    core::Message* messageAfter = nullptr;
};

TEST(MessageTest, MessageCreatedWithNullTitle) {
    core::Message message{QString(), "Test", "Test", "Test"};

    ASSERT_TRUE(message.getTitle().isNull());
}

TEST(MessageTest, MessageCreatedWithEmptyTitle) {
    core::Message message{"", "Test", "Test", "Test"};

    ASSERT_TRUE(message.getTitle().isNull());
}

TEST(MessageTest, MessageCreatedWithValidTitle) {
    core::Message message{"Test", "Test", "Test", "Test"};

    ASSERT_FALSE(message.getTitle().isNull());
}

TEST_F(MessageFormatTest, MessageDataTest) {
    EXPECT_EQ(messageBefore->getTitle(), "Message Title");
    EXPECT_EQ(messageBefore->getSender(), "Message Sender");
    EXPECT_EQ(messageBefore->getReceiver(), "Message Receiver");
    EXPECT_EQ(messageBefore->getContent(), "Message Content");
}

TEST_F(MessageFormatTest, SerializeTest) {
    QByteArray data = serializer->Serialize(messageBefore);
    messageAfter = deserializer->Deserialize(data);
    EXPECT_EQ(messageBefore->getTitle(), messageAfter->getTitle());
    EXPECT_EQ(messageBefore->getSender(), messageAfter->getSender());
    EXPECT_EQ(messageBefore->getReceiver(), messageAfter->getReceiver());
    EXPECT_EQ(messageBefore->getContent(), messageAfter->getContent());
}
