#include <iostream>
#include "frontend/include/lexer.hh"
#include "frontend/include/parser.hh"

int main(int argc, char const *argv[])
{
    Lexer lexer = Lexer("5 + 2 * 90 * 21");
    lexer.scan();
    auto tokens = lexer.tokens;
    auto lexemes = lexer.lexemes;
    for (auto lex: lexemes) {
        std::cout << lex << '\n';
    }
    Parser parser = Parser(tokens, lexemes);
    parser.parse();
    parser.printAST();
}
