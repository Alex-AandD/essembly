#include "frontend/include/lexer.hh"
#include "frontend/include/token.hh"

Lexer::Lexer(std::string _inp): input(std::move(_inp)), current(0), start(0), line(1), input_len(input.size()) { }
Lexer::~Lexer() { }

[[nodiscard]] Token Lexer::createToken(TT type) noexcept {
    Token token = Token(type, start, line, "modules must be implemented");
    return token;
}

void Lexer::pushToken(TT type) noexcept {
    Token token = createToken(type); 
    tokens.push_back(token);
}

void Lexer::pushString() {
    while(!atEnd() && peekNext() != '"') {
        advance();
    }
    if (atEnd()) {
        throw "missing closing quote at some line, IMPLEMENT EXCEPTIONS!!!";
    }
    /* given string "hello" start = '"' so when we substring we do start + 1 to current - start */
    pushToken(TT::STR_LITERAL);
    pushLexeme(input.substr(start+1, current-start));
}

void Lexer::pushNumber() noexcept {
    while(!atEnd() && std::isdigit(peekNext())) { 
        advance();
    }
    if (peekNext() == '.') {
        advance();
        pushFloat();
    }
    pushToken(TT::INT_LITERAL);
    pushLexeme(input.substr(start, current - start + 1));
}

void Lexer::pushFloat() noexcept {
    while(!atEnd() && std::isdigit(peekNext())) { 
        advance();
    }
    pushToken(TT::FLOAT_LITERAL);
    pushLexeme(input.substr(start, current - start + 1));
}

void Lexer::scan() {
    while (!atEnd()){
        start = current;
        char currChar = input[current];
        switch (currChar)
        {
        case ' ':  break;
        case '\t': break;
        case '\n': break; 
        case '+':  pushToken(TT::PLUS);  break;
        case '*':  pushToken(TT::TIMES); break;
        case '/':  pushToken(TT::SLASH); break;
        case '-':  pushToken(TT::MINUS); break;
        case ';':  pushToken(TT::SEMICOLON); break;
        case '"':  pushString(); break;
        case '0':  pushNumber(); break; 
        case '1':  pushNumber(); break;
        case '2':  pushNumber(); break;
        case '3':  pushNumber(); break;
        case '4':  pushNumber(); break;
        case '5':  pushNumber(); break;
        case '6':  pushNumber(); break;
        case '7':  pushNumber(); break;
        case '8':  pushNumber(); break;
        case '9':  pushNumber(); break;
        default:
            throw "unexpected character";
        }
        advance();
    }
}
