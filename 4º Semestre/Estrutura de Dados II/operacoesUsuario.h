#ifndef OPERACOESUSUARIO
#define OPERACOESUSUARIO

#include <ctype.h>
#include "filmes.h"
#include "indices.h"

#ifndef string
#define string char*
#endif

//Menu para inserção de um novo filme
void inserirFilme(FILE *movies, FILE *iprimary, FILE *ititle);

//Menu para remoção de um filme
void removerFilme(FILE *movies, IndiceP *indexP, FILE *iprimary, FILE *ititle);

//Menu para modificação de nota
void modificarNota(FILE *movies, IndiceP *indexP, FILE *iprimary, FILE *ititle);

//Menu para busca de filme (com dois submenus)
void buscarFilme(FILE *movies, IndiceP *indexP, IndiceS *indexS);

//Submenu para busca de filme pela chave primária
void buscarChave(FILE *movies, IndiceP *indexP);

//Submenu para busca de filme pela chave secundária
void buscarTitulo(FILE *movies, IndiceS *indexS);

//Listagem de todos os filmes
void listarFilmes(FILE *movies);

//Impressão de um filme na tela
int imprimirFilme(FILE *movies, int rnn);

//Ensures the given string has size TAM_ENTRADA by padding it with '#"
void padString(string str);

//Clears the input buffer;
void clearBuffer();

#endif