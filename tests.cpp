#include <gtest/gtest.h>
#include "message.h"

TEST(MessageTest, MessageCreatedWithNullTitle) {
    core::Message message{QString(), "Test", "Test", "Test"};

    ASSERT_TRUE(message.getTitle().isNull());
}

TEST(MessageTest, MessageCreatedWithEmptyTitle) {
    core::Message message{"", "Test", "Test", "Test"};

    ASSERT_TRUE(message.getTitle().isNull());
}
