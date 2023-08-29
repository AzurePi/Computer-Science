#ifndef FILMES
#define FILMES

typedef struct {
    char codigo[5]; //composto pelas trê primeiras letras do sobrenome do diretor e dois últimos dígitos do ano de lançamento
    char *tituloPT; //título em português
    char *tituloOG; //título original; "Idem" se for o mesmo
    char *diretor;  //sobrenome e nome do diretor, separados por vírgula
    char ano[4];    //ano de lançamento
    char *pais;     //país em que o filme foi produzido
    char nota;       //inteiro entre 0 e 9 com a nota dada pelo colecionador
} Filme;









#endif
