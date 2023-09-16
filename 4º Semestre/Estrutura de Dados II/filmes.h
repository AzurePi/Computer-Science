#ifndef FILMES
#define FILMES

#define STRINGIFY_HELPER(x) #x
#define STRINGIFY(x) STRINGIFY_HELPER(x)

#define TAM_ENTRADA 192
#define PADDING '#'

#define TAM_COD 5
#define TAM_TIT_PT 57
#define TAM_TIT_OG 57
#define TAM_DIR 40
#define TAM_PAIS 20

typedef struct filme {
    char codigo[6];     //composto pelas três primeiras letras do sobrenome do diretor e dois últimos dígitos do ano de lançamento
    char tituloPT[58];  //título em português
    char tituloOG[58];  //título original; "Idem" se for o mesmo
    char diretor[41];   //sobrenome e nome do diretor, separados por vírgula
    char ano[5];        //ano de lançamento
    char pais[21];      //país em que o filme foi produzido
    char nota;          //inteiro entre 0 e 9 com a nota dada pelo colecionador
} Filme;

#endif
