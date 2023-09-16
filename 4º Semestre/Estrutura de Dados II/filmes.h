#ifndef FILMES
#define FILMES

#include <stdlib.h>
#include <string.h>

#define TAM_ENTRADA 192

#ifndef string
#define string char*
#endif

typedef struct filme {
    char codigo[6];     //composto pelas trê primeiras letras do sobrenome do diretor e dois últimos dígitos do ano de lançamento
    string tituloPT;    //título em português
    string tituloOG;    //título original; "Idem" se for o mesmo
    string diretor;     //sobrenome e nome do diretor, separados por vírgula
    char ano[5];        //ano de lançamento
    string pais;        //país em que o filme foi produzido
    char nota;          //inteiro entre 0 e 9 com a nota dada pelo colecionador
} Filme;

Filme *newFilme(string codigo, string tituloPT, string tituloOG, string diretor, string ano, string pais, char nota) {
    Filme *novo = (Filme *) malloc(sizeof(Filme));

    strcpy(novo->codigo, codigo);
    strcpy(novo->tituloPT, tituloPT);
    strcpy(novo->tituloOG, tituloOG);
    strcpy(novo->diretor, diretor);
    strcpy(novo->ano, ano);
    strcpy(novo->pais, pais);
    novo->nota = nota;

    return novo;
}

#endif
