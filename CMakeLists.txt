cmake_minimum_required(VERSION 3.26)
project(Computer_Science C)

set(CMAKE_C_STANDARD 11)

include_directories("4º Semestre/Estrutura de Dados II")

add_executable(Computer_Science
        "4º Semestre/Estrutura de Dados II/main.c"
        "4º Semestre/Estrutura de Dados II/operacoesUsuario.h"
        "4º Semestre/Estrutura de Dados II/filmes.h"
        "4º Semestre/Estrutura de Dados II/indices.h"
        "4º Semestre/Estrutura de Dados II/indices.c"
        "4º Semestre/Estrutura de Dados II/operacoesUsuario.c")
