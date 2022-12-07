#include "../include/token.hh"
#include <string>
#include <memory>

namespace Essembly {

Token::Token(TT t, size_t off, size_t l, std::string m): type(t), offset(off), line(l), mod(std::move(m)) { }
Token::~Token() { }

std::string TokentoString(Token* token) {
    TT type = token->type;
    switch (type)
    {
    case TT::PLUS: return "+";
    case TT::MINUS: return "-";
    case TT::TIMES: return "*";
    case TT::SLASH: return "/";
    case TT::NOT: return "!";
    case TT::NEQ: return "!=";
    case TT::INT_TYPE: return "INT_TYPE";
    case TT::SEMICOLON: return ";";
    case TT::INT_LITERAL: return "INT LITERAL";
    case TT::FALSE_LITERAL: return "FALSE";
    case TT::TRUE_LITERAL: return "TRUE";
    default:
        throw "cannot convert token to string. Unexpected token";
    }
}

} // ESSEMBLY