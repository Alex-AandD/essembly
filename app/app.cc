#include <iostream>
#include "frontend/include/lexer.hh"
#include "frontend/include/token.hh"
//#include "backend/include/generator.hh"
//#include "backend/include/generator.hh"
#include <memory>

using namespace Essembly;
int main(int argc, char const *argv[])
{
    std::string input = "int a=5+7 + 9;double b = 5 * 7 / 5;int c =  76 * 12 + 54;";
    Lexer lexer = Lexer(input);
    lexer.scan();
    auto tokens = std::move(lexer.tokens);
    auto lexemes = lexer.lexemes;
    for (const auto& tok: tokens) {
        std::cout << TokentoString(tok.get()) << '\n';
    }
}
