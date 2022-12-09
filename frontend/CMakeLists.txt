add_library(frontendlib 
    src/lexer.cc
    src/parser.cc
    src/visitors.cc
    src/expr_types.cc
    src/decl_types.cc
    src/token.cc
    src/expr.cc
    src/declarations.cc
    src/FactoryDeclaration.cc
)

target_include_directories(frontendlib PUBLIC
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/libs/sparsehash/src
)