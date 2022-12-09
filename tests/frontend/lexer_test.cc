#include <gtest/gtest.h>
#include "frontend/include/lexer.hh"
#include "frontend/include/token.hh"

/* LEXER FIXTURE */
class LexerTest: public ::testing::Test {
public:
    Essembly::Lexer lexer;
};

/* testing for empty input */
TEST_F(LexerTest, EmptyInput) {
    // the vector of tokens should be of size 0;
    lexer.reset("");
    lexer.scan();
    auto tokens = std::move(lexer.tokens);
    EXPECT_EQ(tokens.size(), 0);
}

/* testing for arithmetic operators */
TEST_F(LexerTest, ArithmeticTokens) {
    // the vector of tokens should be of size 0;
    using namespace Essembly;
    lexer.reset("+ - / * + -");
    lexer.scan();

    // first compare the sizes of the two vectors
    EXPECT_EQ(6, lexer.tokens.size());

    auto tokens = std::move(lexer.tokens);
    std::vector<TT> expectedTypes { TT::PLUS, TT::MINUS, TT::SLASH, TT::TIMES, TT::PLUS, TT::MINUS };
    // now compare the actual types
    for (size_t i = 0; i < tokens.size(); i++) {
        EXPECT_EQ(tokens[i]->type, expectedTypes[i]);
    }
}

TEST_F(LexerTest, ComparisonTokens) {

}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}