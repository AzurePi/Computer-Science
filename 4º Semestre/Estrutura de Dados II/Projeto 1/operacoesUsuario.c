#include "operacoesUsuario.h"

void inserirFilme(FILE *movies, IndiceP **indexP, IndiceS **indexS) {
    string filme;

    string codigo = malloc(TAM_COD + 1);       //5 caracteres, mais finalizador
    string tituloPT = malloc(TAM_TIT_PT + 1);  //62 caracteres, mais finalizador
    string tituloOG = malloc(TAM_TIT_OG + 1);  //62 caracteres, mais finalizador
    string diretor = malloc(TAM_DIR + 1);      //30 caracteres, mais finalizador
    string ano = malloc(5);                    //4 caracteres, mais finalizador
    string pais = malloc(TAM_PAIS + 1);        //21 caracteres, mais finalizador
    char nota = 0;                                  //1 caractere, e no arquivo um finalizador

    string nome = malloc(16);
    string sobrenome = malloc(16);

    int rnn;

    puts(SUBTITLE"\n-----------INSERCAO DE FILME----------"CLEAR);
    puts("\t\t\t\t\t\33[2;3;95mOBS: Nao utilize acentos"CLEAR);

    printf(CLEAR"Titulo em Portugues: "INPUT);
    scanf("%"STRINGIFY(TAM_TIT_PT)"[^\n]s", tituloPT);
    clearBuffer();

    printf(CLEAR"Titulo Original: "INPUT);
    scanf("%"STRINGIFY(TAM_TIT_OG)"[^\n]", tituloOG);
    clearBuffer();

    printf(CLEAR"Primeiro Nome do Diretor: "INPUT);
    scanf("%15s", nome);
    clearBuffer();

    printf(CLEAR"Ultimo Nome do Diretor: "INPUT);
    scanf("%15s", sobrenome);
    clearBuffer();

    printf(CLEAR"Ano: "INPUT);
    scanf("%4s", ano);
    clearBuffer();

    printf(CLEAR"Pais: "INPUT);
    scanf("%"STRINGIFY(TAM_PAIS)"[^\n]s", pais);
    clearBuffer();

    printf(CLEAR"Nota: "INPUT);
    scanf("%c", &nota);
    printf(CLEAR);
    clearBuffer();

    printf("\n");

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

    //ajusta o título original
    if (strcmp(tituloPT, tituloOG) == 0)
        strcpy(tituloOG, "Idem");

    //montando o nome do diretor
    sprintf(diretor, "%s, %s", sobrenome, nome);

    //montando o código do filme
    string aux = malloc(4);
    for (int i = 0; i < 3; i++)
        aux[i] = toupper(sobrenome[i]);
    aux[3] = '\0';

    sprintf(codigo, "%s%c%c", aux, ano[2], ano[3]);
    free(aux);
    free(nome);
    free(sobrenome);

    //verifica se o código desse filme já está registrado
    rnn = rnnFromCodigo(*indexP, codigo);
    if (rnn != -1) {
        puts(ERROR"\tERRO: filme já cadastrado"CLEAR);

        free(codigo);
        free(tituloPT);
        free(tituloOG);
        free(ano);
        free(diretor);
        free(pais);

        return;
    }

    //monta a string filme
    filme = malloc(TAM_FILME + 1);
    sprintf(filme, "%s@%s@%s@%s@%s@%s@%c@", codigo, tituloPT, tituloOG, diretor, ano, pais, nota);

    int size = strlen(filme);
    if (size < TAM_FILME + 1) {
        for (int i = size; i < TAM_FILME; i++)
            filme[i] = PADDING;
        filme[TAM_FILME] = '\0';
    }

    //imprime no arquivo
    fseek(movies, 0, SEEK_END);
    rnn = ftell(movies) / TAM_FILME;
    fputs(filme, movies);

    //Atualiza os índices
    insereFilme(*indexP, *indexS, codigo, tituloPT, rnn); //TODO: Algo de errado com a inserção

    //libera a memória alocada
    free(codigo);
    free(tituloPT);
    free(tituloOG);
    free(ano);
    free(diretor);
    free(pais);
    free(filme);
}

void removerFilme(FILE *movies, IndiceP **indexP, IndiceS **indexS) {
    string codigo = malloc(TAM_COD + 1);
    string titulo;
    int rnn;

    puts(SUBTITLE"\n----------REMOCAO DE FILME----------"CLEAR);

    printf("Chave: ");
    scanf("%"STRINGIFY(TAM_COD)"s", codigo);
    clearBuffer();

    printf("\n");

    //procura a posição do filme correspondente no arquivo
    rnn = rnnFromCodigo(*indexP, codigo);
    if (rnn == -1) {
        puts("Filme nao encontrado");
        return;
    }

    //salva o título para remoção do índice secundário
    titulo = tituloFromRNN(movies, rnn);

    //marca o filme como deletado
    fseek(movies, rnn * TAM_FILME, SEEK_SET);
    fputs("*|", movies);

    //remove o filme dos índices
    removeFilme(*indexP, *indexS, codigo, titulo);

    free(codigo);
    free(titulo);
}

void modificarNota(FILE *movies, IndiceP *indexP) {
    string codigo = malloc(TAM_COD + 1);
    int rnn;
    string filme = malloc(TAM_FILME + 1);
    char atual;
    char nova;

    puts(SUBTITLE"\n----------MODIFICACAO DE NOTA---------"CLEAR);

    printf("Codigo: "INPUT);
    scanf("%"STRINGIFY(TAM_COD)"s", codigo);
    clearBuffer();
    printf(CLEAR);

    rnn = rnnFromCodigo(indexP, codigo);
    free(codigo);
    if (rnn == -1) {
        puts(ERROR"Filme nao encontrado"CLEAR);
        return;
    }

    fseek(movies, rnn * TAM_FILME, SEEK_SET);
    fgets(filme, TAM_FILME, movies);

    sscanf(filme, "%*[^@]@%*[^@]@%*[^@]@%*[^@]@%*[^@]@%*[^@]@%c@", &atual);

    printf("Nota atual: %c\n", atual);
    printf("Nova nota: "INPUT);
    scanf("%c", &nova);

    printf(CLEAR"\n");

    free(filme);

    if (!isdigit(nova)) {
        puts(ERROR"\tERRO: nota invalida"CLEAR);
        return;
    }

    short int count = 0; //contador dos campos sendo passados
    char c; //iterador dos caracteres

    fseek(movies, rnn * TAM_FILME, SEEK_SET);
    while (count < 6) {
        c = fgetc(movies);
        if (c == '@')
            count++;
    }
    fseek(movies, ftell(movies), SEEK_SET);
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

    noS = buscaNoS(indexS, titulo);
    head = noS->head;

    while (head != NULL) {
        codigo = malloc(TAM_COD + 1);

        strcpy(codigo, head->codigo);

        rnn = rnnFromCodigo(indexP, codigo);

        if (rnn == -1) {
            printf(ERROR"ERRO: codigo %s presente no indice não encontrado\n"CLEAR, codigo);
            return;
        }
        imprimirFilme(movies, rnn);
        free(codigo);

        head = head->prox;
    }
}

void listarFilmes(FILE *movies) {
    int rnn = 0;

    fseek(movies, 0, SEEK_END);
    int total = ftell(movies) / TAM_FILME;

    printf(CLEAR"\n");
    while (rnn < total) {
        imprimirFilme(movies, rnn);
        rnn++;
    }
}

void compactar(FILE *movies) {
    fseek(movies, 0, SEEK_SET);

    FILE *reader, *printer;
    reader = movies;
    printer = movies;
}

void imprimirFilme(FILE *movies, int rnn) {
    string codigo;
    string tituloPT;
    string tituloOG;
    string diretor;
    string ano;
    string pais;
    char nota = 0;

    fseek(movies, rnn * TAM_FILME, SEEK_SET);

    codigo = malloc(TAM_COD + 1);
    tituloPT = malloc(TAM_TIT_PT + 1);
    tituloOG = malloc(TAM_TIT_OG + 1);
    diretor = malloc(TAM_DIR + 1);
    ano = malloc(5);
    pais = malloc(TAM_PAIS + 1);

    fscanf(movies, "%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%c@", codigo, tituloPT, tituloOG, diretor, ano, pais, &nota);
    if (codigo[0] == '*' && codigo[1] == '|') {
        free(codigo);
        free(tituloPT);
        free(tituloOG);
        free(diretor);
        free(ano);
        free(pais);
        return;
    }

    printf(IMPRESSAO"Codigo: "CLEAR"%s\n", codigo);
    printf(IMPRESSAO"Titulo em Portugues: "CLEAR"%s\n", tituloPT);
    printf(IMPRESSAO"Titulo Original: "CLEAR"%s\n", tituloOG);
    printf(IMPRESSAO"Diretor: "CLEAR"%s\n", diretor);
    printf(IMPRESSAO"Ano: "CLEAR"%s\n", ano);
    printf(IMPRESSAO"Pais: "CLEAR"%s\n", pais);
    printf(IMPRESSAO"Nota: "CLEAR"%c\n", nota);
    printf("\n");

    free(codigo);
    free(tituloPT);
    free(tituloOG);
    free(diretor);
    free(ano);
    free(pais);
}

string tituloFromRNN(FILE *movies, int rnn) {
    string codigo = malloc(TAM_COD + 1);
    string titulo = malloc(TAM_TIT_PT + 1);

    fseek(movies, rnn * TAM_FILME, SEEK_SET);
    fscanf(movies, "%s@%s@", codigo, titulo);
    free(codigo);
    return titulo;
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

