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
    std::string input = "int a = 2;";
    Lexer lexer = Lexer(input);
    lexer.scan();
    for (size_t i = 0; i < lexer.tokens.size(); i++)
    {
        std::cout << TokentoString(lexer.tokens[i].get()) << '\n';
    }
    
    std::vector<std::unique_ptr<Token>> tokens = std::move(lexer.tokens);
    std::vector<std::string> lexemes = lexer.lexemes;
    auto parser = Parser(tokens, lexemes);
    parser.parse();
    parser.printAST();
}
