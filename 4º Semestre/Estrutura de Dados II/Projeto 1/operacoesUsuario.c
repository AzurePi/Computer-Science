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

    puts(SUBTITLE
         "\n-----------INSERCAO DE FILME----------"
         CLEAR);
    puts("\t\t\t\t\t"
         FAINT
         ITALIC
         BRIGHT_MAGENTA
         "OBS: Nao utilize acentos"
         CLEAR);

    printf(PROMPT
           "Titulo em Portugues: "
           INPUT);
    scanf("%"
          STRINGIFY(TAM_TIT_PT)
          "[^\n]s", tituloPT);
    clearBuffer();

    printf(PROMPT
           "Titulo Original: "
           INPUT);
    scanf("%"
          STRINGIFY(TAM_TIT_OG)
          "[^\n]", tituloOG);
    clearBuffer();

    printf(PROMPT
           "Primeiro Nome do Diretor: "
           INPUT);
    scanf("%15s", nome);
    clearBuffer();

    printf(PROMPT
           "Ultimo Nome do Diretor: "
           INPUT);
    scanf("%15s", sobrenome);
    clearBuffer();

    printf(PROMPT
           "Ano: "
           INPUT);
    scanf("%4s", ano);
    clearBuffer();

    printf(PROMPT
           "Pais: "
           INPUT);
    scanf("%"
          STRINGIFY(TAM_PAIS)
          "[^\n]s", pais);
    clearBuffer();

    printf(PROMPT
           "Nota: "
           INPUT);
    scanf("%c", &nota);
    clearBuffer();

    //validação de entradas
    if (!isdigit(nota)) {
        puts(ERROR
             "\tERRO: nota invalida"
             CLEAR);

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
        puts(ERROR
             "\tERRO: sobrenome curto"
             CLEAR);

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
            puts(ERROR
                 "\tERRO: ano invalido"
                 CLEAR);

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
        puts(ERROR
             "\tERRO: filme ja cadastrado"
             CLEAR);

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
            filme[i] = '#';
        filme[TAM_FILME] = '\0';
    }

    //imprime no arquivo
    fseek(movies, 0, SEEK_END);
    rnn = ftell(movies) / TAM_FILME;
    fputs(filme, movies);

    //Atualiza os índices
    insereFilme(*indexP, *indexS, codigo, tituloPT, rnn);

    //libera a memória alocada
    free(codigo);
    free(tituloPT);
    free(tituloOG);
    free(ano);
    free(diretor);
    free(pais);
    free(filme);

    puts(SUCESS
         "\tFilme inserido com sucesso"
         CLEAR);
}

void removerFilme(FILE *movies, IndiceP **indexP, IndiceS **indexS) {
    string codigo = malloc(TAM_COD + 1);
    string titulo;
    int rnn;

    puts(SUBTITLE
         "\n-----------REMOCAO DE FILME-----------"
         CLEAR);

    printf(PROMPT
           "Chave: "
           INPUT);
    scanf("%"
          STRINGIFY(TAM_COD)
          "s", codigo);
    clearBuffer();

    //procura a posição do filme correspondente no arquivo
    rnn = rnnFromCodigo(*indexP, codigo);
    if (rnn == -1) {
        puts(ERROR
             "\tFilme nao encontrado"
             CLEAR);
        free(codigo);
        return;
    }

    //salva o título para remoção do índice secundário
    titulo = tituloFromRNN(movies, rnn);

    //marca o filme como deletado
    fseek(movies, rnn * TAM_FILME, SEEK_SET);
    fputs("*|", movies);

    //remove o filme dos índices
    removeFilmeFromIndice(*indexP, *indexS, codigo, titulo);

    free(codigo);
    free(titulo);

    puts(SUCESS
         "\tFilme removido com sucesso"
         CLEAR);
}

void modificarNota(FILE *movies, IndiceP *indexP) {
    string codigo = malloc(TAM_COD + 1);
    int rnn;
    char atual;
    char nova;

    puts(SUBTITLE
         "\n----------MODIFICACAO DE NOTA---------"
         CLEAR);

    printf(PROMPT
           "Codigo: "
           INPUT);
    scanf("%"
          STRINGIFY(TAM_COD)
          "s", codigo);
    clearBuffer();

    rnn = rnnFromCodigo(indexP, codigo);
    free(codigo);
    if (rnn == -1) {
        puts(ERROR
             "Filme nao encontrado"
             CLEAR);
        return;
    }

    fseek(movies, rnn * TAM_FILME, SEEK_SET);

    //lê a entrada do filme, guardando a nota atual e ignorando os demais campos
    fscanf(movies, "%*[^@]@%*[^@]@%*[^@]@%*[^@]@%*[^@]@%*[^@]@%c@", &atual);

    printf(LISTING
           "Nota atual: "
           CLEAR
           "%c\n", atual);
    printf(PROMPT
           "Nova nota: "
           INPUT);
    scanf("%c", &nova);

    if (!isdigit(nova)) {
        puts(ERROR
             "\tERRO: nota invalida"
             CLEAR);
        return;
    }

    //anda no arquivo até a posição onde a nota deveria estar
    fseek(movies, -2, ftell(movies));
    fputc(nova, movies);

    puts(SUCESS
         "\tNota modificada com sucesso"
         CLEAR);
}

void buscarFilme(FILE *movies, IndiceP *indexP, IndiceS *indexS) {
    short int op;
    short int sucess = 0;

    do {
        puts(SUBTITLE
             "\n------------BUSCA DE FILME------------"
             CLEAR);

        puts(MENU
             "1."
             CLEAR
             " Buscar por codigo");
        puts(MENU
             "2."
             CLEAR
             " Buscar por titulo");
        puts(MENU
             "0."
             CLEAR
             " Retornar"
             INPUT);
        scanf("%hd", &op);
        printf(CLEAR);
        clearBuffer();

        switch (op) {
            case 1:
                sucess = buscarCodigo(movies, indexP);
                break;
            case 2:
                sucess = buscarTitulo(movies, indexP, indexS);
                break;
            case 0:
                sucess = 1;
                break;
            default:
                puts(ERROR
                     "\tERRO: Opcao invalida"
                     CLEAR);
                break;
        }
    } while (sucess != 1);
}

int buscarCodigo(FILE *movies, IndiceP *indexP) {
    string codigo = malloc(TAM_COD + 1);
    int rnn;

    puts(SUBSUBTITLE
         "\n------BUSCA POR CODIGO------"
         CLEAR);

    printf(PROMPT
           "Chave: "
           INPUT);
    scanf("%"STRINGIFY(TAM_COD)"s", codigo);
    clearBuffer();

    rnn = rnnFromCodigo(indexP, codigo);
    free(codigo);
    if (rnn == -1) {
        puts(ERROR
             "\tFilme nao encontrado"
             CLEAR);
        return 0;
    }
    printf("\n");
    imprimirFilme(movies, rnn);
    return 1;
}

int buscarTitulo(FILE *movies, IndiceP *indexP, IndiceS *indexS) {
    string titulo = malloc(TAM_TIT_PT + 1);
    NoS *noS;
    NoCodigo *noC;
    int rnn;

    puts(SUBSUBTITLE
         "\n------BUSCA POR TITULO------"
         CLEAR);

    printf(PROMPT
           "Titulo: "
           INPUT);
    scanf("%"STRINGIFY(TAM_TIT_PT)"[^\n]s", titulo);
    clearBuffer();

    //procura o nó do índice secundário associado a esse título
    noS = buscaNoS(indexS, titulo);
    free(titulo);

    if (noS == NULL) {
        printf(ERROR
               "\tFilme nao encontrado\n");
        return 0;
    }

    //analisa todos os códigos associados a esse título
    noC = noS->head;
    while (noC != NULL) {
        rnn = rnnFromCodigo(indexP, noC->codigo);
        if (rnn == -1) {
            printf(ERROR
                   "\tERRO: codigo %s presente no indice não encontrado\n"
                   CLEAR, noC->codigo);
            return 0;
        }

        printf("\n");
        imprimirFilme(movies, rnn);
        noC = noC->prox;
    }
    return 1;
}

void listarFilmes(FILE *movies) {
    int rnn = 0;

    fseek(movies, 0, SEEK_END);
    int total = ftell(movies) / TAM_FILME;

    puts(SUBTITLE
         "\n----------LISTAGEM DE FILMES----------"
         CLEAR"\n");

    while (rnn < total) {
        imprimirFilme(movies, rnn);
        printf("\n");
        rnn++;
    }
}

void imprimirFilme(FILE *movies, int rnn) {
    string codigo = malloc(TAM_COD + 1);
    string tituloPT = malloc(TAM_TIT_PT + 1);
    string tituloOG = malloc(TAM_TIT_OG + 1);
    string diretor = malloc(TAM_DIR + 1);
    string ano = malloc(5);
    string pais = malloc(TAM_PAIS + 1);
    char nota = 0;

    fseek(movies, rnn * TAM_FILME, SEEK_SET);

    //tenta ler do arquivo
    if (fscanf(movies, "%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%c@", codigo, tituloPT, tituloOG, diretor, ano, pais,
               &nota) != EOF) {

        //se a entrada lida foi marcada como apagada, encerra a impressão
        if (codigo[0] == '*' && codigo[1] == '|') {
            free(codigo);
            free(tituloPT);
            free(tituloOG);
            free(diretor);
            free(ano);
            free(pais);
            return;
        }

        //imprime as informações na tela
        printf(LISTING
               "Codigo: "
               CLEAR
               "%s\n", codigo);

        printf(LISTING
               "Titulo em Portugues: "
               CLEAR
               "%s\n", tituloPT);

        printf(LISTING
               "Titulo Original: "
               CLEAR
               "%s\n", tituloOG);

        printf(LISTING
               "Diretor: "
               CLEAR
               "%s\n", diretor);

        printf(LISTING
               "Ano: "
               CLEAR
               "%s\n", ano);

        printf(LISTING
               "Pais: "
               CLEAR
               "%s\n", pais);

        printf(LISTING
               "Nota: "
               CLEAR
               "%c\n", nota);
    }
    free(codigo);
    free(tituloPT);
    free(tituloOG);
    free(diretor);
    free(ano);
    free(pais);
}

FILE *compactar(FILE *movies, IndiceP **indexP) {
    fseek(movies, 0, SEEK_SET);

    FILE *aux = fopen("data/aux.dat", "w+");
    string entrada = malloc(TAM_FILME + 1);

    while (fscanf(movies, "%"STRINGIFY(TAM_FILME)"[^\n]s", entrada) != EOF) {
        if (entrada[0] != '*' && entrada[1] != '|')
            fprintf(aux, "%s", entrada);
    }
    free(entrada);

    //fechamos os arquivos
    fclose(movies);
    fclose(aux);

    //removemos o arquivo de dados antigo, e renomeamos o arquivo auxiliar para ser o novo arquivo de dados
    remove("data/movies.dat");
    rename("data/aux.dat", "data/movies.dat");

    //abrimos o novo arquivo de dados
    movies = fopen("data/movies.dat", "r+a");

    //como os RNN mudaram, apagamos o índice primário da memória, e o refazemos a partir do novo arquivo de dados
    freeIndiceP(*indexP);
    *indexP = refazerP(movies);

    puts(SUCESS
         "\tArquivo de dados compactado com sucesso"
         CLEAR);
    return movies;
}

string tituloFromRNN(FILE *movies, int rnn) {
    string titulo = malloc(TAM_TIT_PT + 1);

    fseek(movies, rnn * TAM_FILME, SEEK_SET);
    fscanf(movies, "%*[^@]@%[^@]@", titulo);
    return titulo;
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}