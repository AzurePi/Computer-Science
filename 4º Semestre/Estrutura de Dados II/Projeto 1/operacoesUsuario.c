#include "operacoesUsuario.h"

void inserirFilme(FILE *movies, IndiceP **indexP, IndiceS **indexS) {
    char filme[TAM_FILME + 1];

    string codigo = malloc(TAM_COD + 1);       //5 caracteres, mais finalizador
    string tituloPT = malloc(TAM_TIT_PT + 1);  //62 caracteres, mais finalizador
    string tituloOG = malloc(TAM_TIT_OG + 1);  //62 caracteres, mais finalizador
    string diretor = malloc(TAM_DIR + 1);      //30 caracteres, mais finalizador
    string ano = malloc(5);                    //4 caracteres, mais finalizador
    string pais = malloc(TAM_PAIS + 1);        //21 caracteres, mais finalizador
    char nota = 0;                                  //1 caractere, e no arquivo um finalizador

    string nome = malloc(16);
    string sobrenome = malloc(16);
    string last;

    puts(SUBTITLE"\n-----------INSERCAO DE FILME----------"CLEAR);
    puts("\t\t\t\t\tOBS: Nao utilize acentos");

    printf("Titulo em Portugues: ");
    scanf("%"STRINGIFY(TAM_TIT_PT)"[^\n]s", tituloPT);
    clearBuffer();

    printf("Titulo Original: ");
    scanf("%"STRINGIFY(TAM_TIT_OG)"[^\n]", tituloOG);
    clearBuffer();

    printf("Primeiro Nome do Diretor: ");
    scanf("%15s", nome);
    clearBuffer();

    printf("Ultimo Nome do Diretor: ");
    scanf("%15s", sobrenome);
    clearBuffer();

    printf("Ano: ");
    scanf("%4s", ano);
    clearBuffer();

    printf("Pais: ");
    scanf("%"STRINGIFY(TAM_PAIS)"[^\n]s", pais);
    clearBuffer();

    printf("Nota: ");
    scanf("%c", &nota);
    clearBuffer();

    //validação de entradas
    if (!isdigit(nota)) {
        puts(ERROR"\tERRO: nota invalida"CLEAR);

        free(codigo);
        free(tituloPT);
        free(tituloOG);
        free(ano);
        free(diretor);
        free(pais);

        free(nome);
        free(sobrenome);

        return;
    }

    if (strlen(sobrenome) < 3) {
        puts(ERROR"\tERRO: sobrenome curto"CLEAR);

        free(codigo);
        free(tituloPT);
        free(tituloOG);
        free(ano);
        free(diretor);
        free(pais);

        free(nome);
        free(sobrenome);

        return;
    }

    for (int i = 0; i < 4; i++) {
        if (!isdigit(ano[i])) {
            puts(ERROR"\tERRO: ano invalido"CLEAR);

            free(codigo);
            free(tituloPT);
            free(tituloOG);
            free(ano);
            free(diretor);
            free(pais);

            free(nome);
            free(sobrenome);

            return;
        }
    }

    if (strcmp(tituloPT, tituloOG) == 0)
        strcpy(tituloOG, "Idem");

    //montando o nome do diretor
    sprintf(diretor, "%s, %s", sobrenome, nome);

    //montando o código do filme
    char aux[4];
    for (int i = 0; i < 3; i++)
        aux[i] = toupper(sobrenome[i]);
    sprintf(codigo, "%s%c%c", aux, ano[2], ano[3]);
    free(nome);
    free(sobrenome);

    if (rnnFromCodigo(*indexP, codigo) != -1) {
        puts(ERROR"\tERRO: filme já cadastrado"CLEAR);

        free(codigo);
        free(tituloPT);
        free(tituloOG);
        free(ano);
        free(diretor);
        free(pais);

        return;
    }

    //imprime no arquivo
    fseek(movies, 0, SEEK_END);

    sprintf(filme, "%s@%s@%s@%s@%s@%s@%c@", codigo, tituloPT, tituloOG, diretor, ano, pais, nota);

    int size = strlen(filme);
    int i;
    for (i = size; i < TAM_FILME; i++)
        filme[i] = PADDING;
    filme[i] = '\0';

    fputs(filme, movies);

    //libera a memória alocada
    free(codigo);
    free(tituloPT);
    free(tituloOG);
    free(ano);
    free(diretor);
    free(pais);
}

void removerFilme(FILE *movies, IndiceP **indexP, IndiceS **indexS) {
    string codigo = malloc(TAM_COD + 1);
    int rnn;

    puts(SUBTITLE"\n----------REMOCAO DE FILME----------"CLEAR);

    printf("Chave: ");
    scanf("%"STRINGIFY(TAM_COD)"s", codigo);
    clearBuffer();

    rnn = rnnFromCodigo(*indexP, codigo);
    free(codigo);
    if (rnn == -1) {
        puts("Filme nao encontrado");
        return;
    }

    fseek(movies, rnn * TAM_FILME, SEEK_SET);
    fputs("*|", movies);
}

void modificarNota(FILE *movies, IndiceP *indexP) {
    string codigo = malloc(TAM_COD + 1);
    int rnn;
    string filme = malloc(TAM_FILME + 1);
    string token;
    char nova;

    puts(SUBTITLE"\n----------MODIFICACAO DE NOTA---------"CLEAR);

    printf("Chave: ");
    scanf("%"STRINGIFY(TAM_COD)"s", codigo);
    clearBuffer();

    rnn = rnnFromCodigo(indexP, codigo);
    free(codigo);
    if (rnn == -1) {
        puts(ERROR"Filme nao encontrado"CLEAR);
        return;
    }

    fseek(movies, rnn * TAM_FILME, SEEK_SET);
    fgets(filme, TAM_FILME, movies);

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

    free(filme);

    if (!isdigit(nova)) {
        puts(ERROR"\tERRO: nota invalida"CLEAR);
        return;
    }

    short int count = 0; //contados dos campos sendo passados
    char c; //iterador dos caracteres

    fseek(movies, rnn * TAM_FILME, SEEK_SET);
    while (count < 6) {
        c = fgetc(movies);
        if (c == '@')
            count++;
    }
    fputc(nova, movies);
}

void buscarFilme(FILE *movies, IndiceP *indexP, IndiceS *indexS) {
    short int op;
    do {
        puts(SUBTITLE"\n------------BUSCA DE FILME------------"CLEAR);

        puts("1. Buscar por codigo");
        puts("2. Buscar por titulo");
        scanf("%hd", &op);

        switch (op) {
            case 1:
                buscarChave(movies, indexP);
                break;
            case 2:
                buscarTitulo(movies, NULL, indexS);
                break;
            default:
                puts(ERROR"\tERRO: Opcao invalida"CLEAR);
                break;
        }
    } while (op < 1 || op > 2);
}

void buscarChave(FILE *movies, IndiceP *indexP) {
    string codigo = malloc(TAM_COD + 1);
    int rnn;

    puts("\n-----BUSCA POR CODIGO-----");

    printf("Chave: ");
    scanf("%"STRINGIFY(TAM_COD)"s", codigo);
    clearBuffer();

    rnn = rnnFromCodigo(indexP, codigo);
    free(codigo);
    if (rnn == -1) {
        puts(ERROR"Filme nao encontrado"CLEAR);
        return;
    }
    printf("%d", rnn);
    imprimirFilme(movies, rnn);
}

void buscarTitulo(FILE *movies, IndiceP *indexP, IndiceS *indexS) {
    string titulo = malloc(TAM_TIT_PT + 1);
    NoS *noS;
    NoCodigo *head;
    string codigo;
    int rnn;

    puts("\n-----BUSCA POR TITULO-----");

    printf("Titulo: ");
    scanf("%"STRINGIFY(TAM_TIT_PT)"[^\n]s", titulo);
    clearBuffer();

    noS = localizaTitulo(indexS, titulo);
    head = noS->head;

    while (head) {
        codigo = malloc(TAM_COD + 1);

        strcpy(codigo, head->codigo);

        rnn = rnnFromCodigo(indexP, codigo);

        if (rnn == -1) {
            printf(ERROR"ERRO: codigo %s presente no indice não encontrado\n"CLEAR, codigo);
            return;
        }
        imprimirFilme(movies, rnn);
        printf("\n");
        free(codigo);

        head = head->prox;
    }
}

void listarFilmes(FILE *movies) {
    int rnn = 0;
    while (imprimirFilme(movies, rnn))
        rnn++;
    rewind(movies);
}

int imprimirFilme(FILE *movies, int rnn) {
    string filme = malloc(TAM_FILME + 1);
    string token;

    fseek(movies, rnn * TAM_FILME, SEEK_SET);
    if (feof(movies))
        return 0;

    fgets(filme, TAM_FILME, movies);
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

    return 1;
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
