#ifndef OPERACOESUSUARIO
#define OPERACOESUSUARIO

#include <stdio.h>
#include "filmes.h"
#include "indices.h"

#ifndef string
#define string char*
#endif

//Menu para inserção de um novo filme
void inserirFilme(FILE *movies);

//Menu para remoção de um filme
void removerFilme(FILE *movies, IndiceP *indexP);

//Menu para modificação de nota
void modificarNota(FILE *movies, IndiceP *indexP);

//Menu para busca de filme (com dois submenus)
void buscarFilme(FILE *movies, IndiceP *indexP, IndiceS *indexS);

//Submenu para busca de filme pela chave primária
void buscarChave(FILE *movies, IndiceP *indexP);

//Submenu para busca de filme pela chave secundária
void buscarTitulo(FILE *movies, IndiceS *indexS);

//Listagem de todos os filmes
void listarFilmes(FILE *movies);

//Impressão de um filme na tela
void imprimirFilme(FILE *movies, int rnn);

#endif