add_library(frontendlib 
    src/expr.cc
    src/lexer.cc
    src/printVisitor.cc 
    src/token.cc
    src/parser.cc
    src/FactoryExpr.cc
)

target_include_directories(frontendlib PUBLIC
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/libs/sparsehash/src
)