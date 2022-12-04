#include <iostream>
#include "frontend/include/lexer.hh"
#include "frontend/include/parser.hh"
#include "backend/include/generator.hh"
#include <memory>

using namespace Essembly;
int main(int argc, char const *argv[])
{
    Lexer lexer = Lexer("5 + 2 * 90 * 21");
    lexer.scan();
    auto tokens = std::move(lexer.tokens);
    auto lexemes = lexer.lexemes;
    Parser parser = Parser(std::move(tokens), lexemes);
    auto AST = std::move(parser.parse());
    Generator generator = Generator(AST);
    generator.generateBytecode();
    generator.disassemble();
}
