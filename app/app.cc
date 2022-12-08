#include <iostream>
#include "frontend/include/lexer.hh"
#include "frontend/include/token.hh"
#include "frontend/include/parser.hh"
#include "frontend/include/declarations.hh"
//#include "backend/include/generator.hh"
#include <memory>
#include <vector>

using namespace Essembly;
int main(int argc, char const *argv[])
{
    std::string input = "int a=5+7 + 9;double b = 5 * 7 / 5;int c =  76 * 12 + 54;";
    Lexer lexer = Lexer(input);
    lexer.scan();
    std::vector<std::unique_ptr<Token>> tokens = std::move(lexer.tokens);
    std::vector<std::string> lexemes = lexer.lexemes;
    auto parser = Parser(tokens, lexemes);
    //parser.parse();
}
