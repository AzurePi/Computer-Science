#ifndef OPERACOESUSUARIO
#define OPERACOESUSUARIO

#include <ctype.h>
#include "filmes.h"
#include "indices.h"
#include "style.h"

#ifndef string
#define string char*
#endif

//Menu para inserção de um novo filme
void inserirFilme(FILE *movies, IndiceP **indexP, IndiceS **indexS);

//Menu para remoção de um filme
void removerFilme(FILE *movies, IndiceP **indexP, IndiceS **indexS);

//Menu para modificação de nota
void modificarNota(FILE *movies, IndiceP *indexP);

//Menu para busca de filme (com dois submenus)
void buscarFilme(FILE *movies, IndiceP *indexP, IndiceS *indexS);

//Submenu para busca de filme pela titulo primária
void buscarChave(FILE *movies, IndiceP *indexP);

//Submenu para busca de filme pela titulo secundária
void buscarTitulo(FILE *movies, IndiceP *indexP, IndiceS *indexS);

//Listagem de todos os filmes
void listarFilmes(FILE *movies);

//Impressão de um filme na tela
int imprimirFilme(FILE *movies, int rnn);

//Clears the input buffer;
void clearBuffer();

#endif