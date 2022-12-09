add_library(frontendlib 
    src/lexer.cc
    src/token.cc
    src/expr.cc
    src/expr_types.cc
    src/decl_types.cc
    src/declarations.cc
    src/parser.cc
    src/FactoryDeclaration.cc
    src/visitors.cc
)

target_include_directories(frontendlib PUBLIC
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/libs/sparsehash/src
)