cmake_minimum_required(VERSION 3.21)
project(libprg_projetoII C)

set(CMAKE_C_STANDARD 17)

include(FetchContent)

add_library(libprg
            src/structs/fila.c
            src/structs/lista.c
            src/structs/pilha.c
)
target_include_directories(libprg PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/header
)

add_executable(libprg_projetoII src/main.c)

# linking libprg
target_link_libraries(libprg_projetoII PUBLIC libprg)