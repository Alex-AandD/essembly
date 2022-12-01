#include <iostream>
#include "frontend/include/lexer.hh"

int main(int argc, char const *argv[])
{
    Lexer lexer = Lexer("5 + 2 * 90 * 21");
    lexer.scan();
}
