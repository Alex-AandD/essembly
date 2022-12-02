#include <gtest/gtest.h>

TEST(hello, helloWorld) {
    EXPECT_EQ("hello", "hello");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}