#include "operacoesUsuario.h"

void inserirFilme(FILE *movies, FILE *iprimary, FILE *ititle) {
    string filme = malloc(TAM_ENTRADA + 1);

    char codigo[TAM_COD + 1];                       //5 caracteres, mais finalizador
    string tituloPT = malloc(TAM_TIT_PT + 1);  //57 caracteres, mais finalizador
    string tituloOG = malloc(TAM_TIT_OG + 1);  //57 caracteres, mais finalizador
    string diretor = malloc(TAM_DIR + 1);      //40 caracteres, mais finalizador
    char ano[5];                                    //4 caracteres, mais finalizador
    string pais = malloc(TAM_PAIS + 1);        //20 caracteres, mais finalizador
    char nota = 0;                                  //1 caractere, e no arquivo um finalizador

    string nome = malloc(11);
    string sobrenomes = malloc(31);
    string last;

    puts("\n-----------INSERCAO DE FILME----------");
    puts("\t\t\t\t\tOBS: Nao utilize acentos");

    printf("Titulo em Portugues: ");
    scanf("%"STRINGIFY(TAM_TIT_PT)"[^\n]s", tituloPT);
    clearBuffer();
    //printf("%s\n\n", tituloPT);

    printf("Titulo Original: ");
    scanf("%"STRINGIFY(TAM_TIT_OG)"[^\n]", tituloOG);
    clearBuffer();
    //printf("%s\n\n", tituloOG);

    printf("Primeiro Nome do Diretor: ");
    scanf("%11s", nome);
    clearBuffer();
    //printf("%s\n\n", nome);

    printf("Sobrenomes do Diretor: ");
    scanf("%31[^\n]s", sobrenomes);
    clearBuffer();
    //printf("%s\n\n", sobrenomes);

    printf("Ano: ");
    scanf("%4s", ano);
    clearBuffer();
    printf("%s\n\n", ano);

    printf("Pais: ");
    scanf("%"STRINGIFY(TAM_PAIS)"s", pais);
    clearBuffer();
    //printf("%s\n\n", pais);

    printf("Nota: ");
    scanf("%c", &nota);
    clearBuffer();
    //printf("%c\n\n", nota);

    //validação de entradas
    if (!isdigit(nota)) {
        puts("\tERRO: nota invalida");

        free(tituloPT);
        free(tituloOG);
        free(diretor);
        free(pais);
        free(filme);

        free(nome);
        free(sobrenomes);

        return;
    }

    for (int i = 0; i < 5; i++) {
        if (!isdigit(ano[i])) {
            puts("\tERRO: ano invalido");

            free(tituloPT);
            free(tituloOG);
            free(diretor);
            free(pais);
            free(filme);

            free(nome);
            free(sobrenomes);

            return;
        }
    }

    if (strcmp(tituloPT, tituloOG) == 0)
        strcpy(tituloOG, "Idem");

    //montando o nome do diretor no formato padronizado
    last = strtok(sobrenomes, " ");
    while (strtok(NULL, " ") != NULL)
        last = strtok(NULL, " ");

    sprintf(diretor, "%s, %s %s", last, nome, sobrenomes);
    free(nome);
    free(sobrenomes);

    //montando o código do filme
    string cod = malloc(3);
    sprintf(cod, "%3s", last);
    char *aux = cod;
    for (int i = 0; i < 3; i++) {
        *aux = toupper(*aux);
        aux++;
    }
    sprintf(codigo, "%s%c%c", cod, ano[2], ano[3]);
    free(cod);

    //imprime no arquivo
    fseek(movies, 0, SEEK_END);

    sprintf(filme, "%s@%s@%s@%s@%s@%s@%c@", codigo, tituloPT, tituloOG, diretor, ano, pais, nota);
    padString(filme);
    fputs(filme, movies);

    //muda a flag dos aquivos de índice
    fputc('1', iprimary);
    fputc('1', ititle);

    //libera a memória alocada
    free(tituloPT);
    free(tituloOG);
    free(diretor);
    free(pais);
    free(filme);

    //retorna ao começo dos arquivos
    rewind(movies);
    rewind(iprimary);
    rewind(ititle);
}

void removerFilme(FILE *movies, IndiceP *indexP, FILE *iprimary, FILE *ititle) {
    char codigo[TAM_COD + 1];
    int rnn;

    puts("\n----------REMOÇÃO DE FILME----------");

    printf("Chave: ");
    scanf("%"STRINGIFY(TAM_COD)"s", codigo);
    clearBuffer();

    rnn = rnnFromCodigo(indexP, codigo);
    if (rnn == -1) {
        puts("Filme nao encontrado");
        return;
    }

    fseek(movies, rnn * TAM_ENTRADA, SEEK_SET);
    fputs("*|", movies);

    //muda a flag dos aquivos de índice
    fputc('1', iprimary);
    fputc('1', ititle);

    rewind(ititle);
    rewind(iprimary);
    rewind(movies);
}

void modificarNota(FILE *movies, IndiceP *indexP, FILE *iprimary, FILE *ititle) {
    char codigo[TAM_COD + 1];
    int rnn;
    string filme;
    string token;
    char nova;

    puts("\n----------MODIFICACAO DE NOTA---------");

    printf("Chave: ");
    scanf("%"STRINGIFY(TAM_COD)"s", codigo);
    clearBuffer();

    rnn = rnnFromCodigo(indexP, codigo);
    if (rnn == -1) {
        puts("Filme nao encontrado");
        return;
    }

    filme = malloc(TAM_ENTRADA + 1);
    fseek(movies, rnn * TAM_ENTRADA, SEEK_SET);
    fgets(filme, TAM_ENTRADA, movies);

    strtok(filme, "@");
    strtok(NULL, "@");
    strtok(NULL, "@");
    strtok(NULL, "@");
    strtok(NULL, "@");
    strtok(NULL, "@");
    token = strtok(NULL, "@");

    printf("Nota atual: %c\n", token[0]);
    printf("Nova nota: ");
    scanf("%c", &nova);
    clearBuffer();

    if (!isdigit(nova)) {
        puts("\tERRO: nota invalida");

        free(filme);
        rewind(movies);
        return;
    }

    short int count = 0; //contados dos campos sendo passados
    char c; //iterador dos caracteres

    fseek(movies, rnn * TAM_ENTRADA, SEEK_SET);
    while (count < 6) {
        c = fgetc(movies);
        if (c == '@')
            count++;
    }
    fputc(nova, movies);

    //muda a flag dos aquivos de índice
    fputc('1', iprimary);
    fputc('1', ititle);

    rewind(iprimary);
    rewind(ititle);
    rewind(movies);
}

void buscarFilme(FILE *movies, IndiceP *indexP, IndiceS *indexS) {
    short int op;
    do {
        puts("\n------------BUSCA DE FILME------------");

        puts("1. Buscar por codigo");
        puts("2. Buscar por titulo");
        scanf("%hd", &op);

        switch (op) {
            case 1:
                buscarChave(movies, indexP);
                break;
            case 2:
                buscarTitulo(movies, indexS);
                break;
            default:
                puts("\tERRO: Opcao invalida");
                break;
        }
    } while (op < 1 || op > 2);
}

void buscarChave(FILE *movies, IndiceP *indexP) {
    char codigo[TAM_COD + 1];
    int rnn;

    puts("\n------BUSCA POR CHAVE-----");

    printf("Chave: ");
    scanf("%"STRINGIFY(TAM_COD)"s", codigo);
    clearBuffer();

    rnn = rnnFromCodigo(indexP, codigo);
    if (rnn == -1) {
        puts("Filme nao encontrado");
        return;
    }

    imprimirFilme(movies, rnn);
}

void buscarTitulo(FILE *movies, IndiceS *indexS) {

}

void listarFilmes(FILE *movies) {
    int rnn = 0;
    while (imprimirFilme(movies, rnn))
        rnn++;
    rewind(movies);
}

int imprimirFilme(FILE *movies, int rnn) {
    string filme = malloc(TAM_ENTRADA + 1);
    string token;

    fseek(movies, rnn * TAM_ENTRADA, SEEK_SET);
    if (feof(movies))
        return 0;

    fgets(filme, TAM_ENTRADA, movies);
    clearBuffer();

    token = strtok(filme, "@");
    printf("Codigo: %s\n", token);

    token = strtok(NULL, "@");
    printf("Titulo em Portugues: %s\n", token);

    token = strtok(NULL, "@");
    printf("Titulo Original: %s\n", token);

    token = strtok(NULL, "@");
    printf("Diretor: %s\n", token);

    token = strtok(NULL, "@");
    printf("Ano: %s\n", token);

    token = strtok(NULL, "@");
    printf("Pais: %s\n", token);

    token = strtok(NULL, "@");
    printf("Nota: %c\n", token[0]);

    free(filme);
    rewind(movies);

    return 1;
}

void padString(string str) {
    int size = strlen(str);

    if (size == TAM_ENTRADA)
        return;

    int paddingSize = TAM_ENTRADA - size;
    for (int i = 0; i < paddingSize; i++)
        str[size + i] = PADDING;

    str[size] = '\0';
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
