add_library(backendlib
    src/instruction.cc
    # src/value.cc
    # src/vm.cc
    src/bytecodeVisitor.cc
    src/disassembleVisitor.cc
    src/code.cc
    src/generator.cc
)

target_include_directories(backendlib PUBLIC 
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/libs/sparsehash/src
)