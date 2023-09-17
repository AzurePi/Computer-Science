cmake_minimum_required(VERSION 3.26)
project(Computer_Science C)

set(CMAKE_C_STANDARD 11)

include_directories("4º Semestre/Estrutura de Dados II/Projeto 1")

add_executable(Computer_Science
        "4º Semestre/Estrutura de Dados II/Projeto 1/main.c"
        "4º Semestre/Estrutura de Dados II/Projeto 1/operacoesUsuario.h"
        "4º Semestre/Estrutura de Dados II/Projeto 1/filmes.h"
        "4º Semestre/Estrutura de Dados II/Projeto 1/indices.h"
        "4º Semestre/Estrutura de Dados II/Projeto 1/indices.c"
        "4º Semestre/Estrutura de Dados II/Projeto 1/operacoesUsuario.c"
        "4º Semestre/Estrutura de Dados II/Projeto 1/style.h"
)
