#include <gtest/gtest.h>
#include "frontend/include/lexer.hh"

/* creating a fixture to reuse Lexer class */
class LexerTest : public ::testing::Test {
protected:
    virtual ~LexerTest() { }
    void SetUp() override {
        lexer = Lexer("");
    }
    Lexer lexer;
};

TEST_F(LexerTest, EmptyInput) {
    /* check how the lexer deals with an empty file */ 
    lexer.scan();
    /* we expect to have an empty list of tokens and an empty list of lexemes */
    auto tokens = lexer.tokens;
    auto lexemes = lexer.lexemes;
    EXPECT_EQ(tokens.size(), 0) << "token array not empty \n";
    EXPECT_EQ(lexemes.size(), 0) << "lexeme array not empty \n";
}

TEST_F(LexerTest, ConstructorWorks) {
    /* check if the constructor works properly */
    /* first empty input */
    std::string input = "";
    Lexer lexer = Lexer(input);
    /* check if the input is correct */
    EXPECT_TRUE(lexer.input == input);
    EXPECT_EQ(lexer.current, 0);
    EXPECT_EQ(lexer.start, 0);
    EXPECT_EQ(lexer.input_len, 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}