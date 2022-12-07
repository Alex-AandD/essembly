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
    case TT::ID: return "ID";
    case TT::SHORT_TYPE: return "SHORT_TYPE";
    case TT::STRING_TYPE: return "STRING_TYPE";
    case TT::STRING_LITERAL: return "STRING_LITERAL";
    case TT::DOUBLE_TYPE: return "DOUBLE_TYPE";
    case TT::BOOL_TYPE: return "BOOL_TYPE";
    case TT::FLOAT_TYPE: return "FLOAT_TYPE";
    case TT::EQ: return "EQ";
    case TT::EQE: return "EQE";
    case TT::LEFT_BRACE: return "LEFT_BRACE";
    case TT::RIGHT_BRACE: return "RIGHT_BRACE";
    case TT::IF: return "IF";
    case TT::FOR: return "FOR";
    case TT::WHILE: return "WHILE";
    case TT::FUN: return "FUN";
    default:
        throw "cannot convert token to string. Unexpected token";
    }
}

} // ESSEMBLY