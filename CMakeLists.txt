cmake_minimum_required(VERSION 3.21)
project(libprg C)

set(CMAKE_C_STANDARD 17)

include(FetchContent)

add_library(libprg
        src/structs/fila.c
        src/structs/lista_enc.c
        src/structs/pilha.c
        src/structs/cartao.c
)
target_include_directories(libprg PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/header
)

# Só cria o executável se for o projeto principal
if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    add_executable(libprg_projetoII src/main.c)
    target_link_libraries(libprg_projetoII PUBLIC libprg)
endif()