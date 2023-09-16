#include "operacoesUsuario.h"

void inserirFilme(FILE *movies) {
    char codigo[6];
    string tituloPT = NULL;
    string tituloOG = NULL;
    string diretor;
    char ano[5];
    string pais = NULL;
    char nota = 0;

    string nome = NULL;
    string sobrenomes = NULL;

    puts("\n----------INSERÇÃO DE FILME---------\n");
    puts("\t\t\t\t\tOBS: Não utilize acentos\n");

    //TODO: validar entradas
    puts("Título em Português: ");
    scanf("%[^\n]s", tituloPT);
    puts("Título Original: ");
    scanf("%[^\n]", tituloOG);
    puts("Primeiro Nome do Diretor: ");
    scanf("%s", nome);
    puts("Sobrenomes do Diretor: ");
    scanf("%[^\n]s", sobrenomes);
    puts("Ano: ");
    scanf("%4s", ano);
    puts("País: ");
    scanf("%s", pais);
    puts("Nota: ");
    scanf("%c", &nota);

    //TODO: montar o código e o diretor
    string aux = strtok(sobrenomes, " ");
    string last;
    string sobre = NULL;
    while (aux != NULL){
        last = aux;
        aux = strtok(NULL, " ");
    }


    sprintf(diretor, "%s, %s %s", last, nome, sobre);




    //encontra o último sobrenome do diretor
    //pega as três primeiras letras
    //pega os dois últimos caracteres do ano
    //concatena e guarda o código

    //TODO: print to file



    rewind(movies)
}

void removerFilme(FILE *movies, IndiceP *indexP) {

}

void modificarNota(FILE *movies, IndiceP *indexP) {

}

void buscarFilme(FILE *movies, IndiceP *indexP, IndiceS *indexS) {
    short int op;
    do {
        puts("\n------------BUSCA DE FILME------------\n");

        puts("1. Buscar por código\n");
        puts("2. Buscar por título\n");
        scanf("%hd", &op);

        switch (op) {
            case 1:
                buscarChave(movies, indexP);
                break;
            case 2:
                buscarTitulo(movies, indexS);
                break;
            default:
                puts("ERRO: Opção inválida");
                break;
        }
    } while (op < 1 || op > 2);
}

void buscarChave(FILE *movies, IndiceP *indexP) {


}

void buscarTitulo(FILE *movies, IndiceS *indexS) {

}

void listarFilmes(FILE *movies) {

}

void imprimirFilme(FILE *movies, int rnn){

}
