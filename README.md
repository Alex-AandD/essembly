# BUILDING THE FRONTEND

## THE GRAMMAR
For now the grammar is pretty simple
expr: term
    | factor
    | unary
    | primary

term: factor (+ | -) factor
    | factor

factor: unary (! | -) unary
    | unary

unary: (! | -) unary
    | primary

primary: int

## THE LEXER
The lexer uses a very simple switch statement to generate all the tokens and the lexemes

## THE PARSER
The parser is a recursive descent. It uses a factory to implement the specific expressions (imul, iadd, fadd ...)
