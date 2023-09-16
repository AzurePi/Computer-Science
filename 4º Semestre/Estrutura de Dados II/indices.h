#ifndef INDICES
#define INDICES

#include <stdio.h>
#include "filmes.h"

#ifndef string
#define string char*
#endif

//Definições de estruturas ---------------------------------------------------------------------------------------------

//Nó que representa uma entrada no índice primário
typedef struct noP {
    //Chave primária, o código do filme
    string chave;
    //RNN, a posição da entrada no arquivo de índice
    int i;
    //Ponteiro para o próximo NoP na lista
    struct noP *prox;
} NoP;

//Nó que representa um código de filme em uma lista de códigos
typedef struct noChaves {
    //Código do filme
    string codigo;
    //Ponteiro para o próximo NoChave na lista
    struct noChaves *prox;
} NoCodigo;

//Nó que representa uma entrada no índice secundário
typedef struct noS {
    //Chave secundária, o título do filme
    string chave;
    //Ponteiro para o início da lista de NoCodigo, representando as chaves do índice primário
    NoCodigo *head;
    //Ponteiro para o próximo NoS na lista
    struct noS *prox;
} NoS;

//Representação na memória do índice primário
typedef struct {
    //Flag que indica se o índice precisa ser alterado
    short int flag;
    //Ponteiro para o começo de uma lista de NoP, representando as entradas do índice primário
    NoP *head;
} IndiceP;

//Representação na memória do índice secundário
typedef struct {
    //Flag que indica se o índice secundário precisa ser alterado
    short int flag;
    //Ponteiro para o começo de uma lista de NoS, representando as entradas do índice secundário
    NoS *head;
} IndiceS;

//Declarações de Funções -----------------------------------------------------------------------------------------------

//Cria um novo NoP, que contém uma chave e um conteúdo, e aponta para NULL
NoP *newNoP(string chave, int conteudo);

//Cria um novo IndiceP, com flag 0, e uma fila vazia de NoP
IndiceP *newIndiceP();

//Insere ordenadamente um NoP na lista do IndiceP
void insereNoP(NoP *no, IndiceP *index);

//Lê um arquivo de índice primário, e monta um IndiceP com as informações
IndiceP *lerP(FILE *index);

//Cria um IndiceP a partir do arquivo de dados
IndiceP *refazerP(FILE *source);

//Slava as informações de um IndiceP em um arquivo
void saveIndiceP(IndiceP *index, FILE *file);

//Libera o espaço alocado para um IndiceP na memória
void freeIndiceP(IndiceP *index);

//Cria um novo NoCodigo, que contém um código, e aponta para NULL;
NoCodigo *newNoCodigo(string codigo);

//Insere ordenadamente um NoCodigo na lista que começa em head
void insereCodigo(NoCodigo *head, NoCodigo *no);

//Cria um novo NoS, que contém uma chave, tem um ponteiro para uma lista vazia de NoChave, e aponta para NULL
NoS *newNoS(string chave);

//Cria um novo IndiceS, com flag 0, e uma fila vazia de NoS
IndiceS *newIndiceS();

//Insere ordenadamente um NoS na lista do IndiceS
void insereNoS(NoS *no, IndiceS *lista);

//Retorna o endereço do NoS com a chave secundária "titulo"; NULL se não está presente
NoS *localizaTitulo(string titulo, IndiceS *lista);

//Lê um arquivo de índice secundário, e monta um IndiceS com as informações
IndiceS *lerS(FILE *index);

//Cria um IndiceS a partir do arquivo de dados
IndiceS *refazerS(FILE *source);

//Salva as informações de IndiceS em um arquivo
void saveIndiceS(IndiceS *index, FILE *file);

//Libera o espaço alocado para um IndiceS na memória
void freeIndiceS(IndiceS *index);

#endif