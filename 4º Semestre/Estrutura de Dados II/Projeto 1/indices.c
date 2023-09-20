#include "indices.h"

NoP *newNoP(string codigo, int rnn) {
    NoP *novo = malloc(sizeof(NoP));
    novo->codigo = malloc(TAM_COD + 1);
    strcpy(novo->codigo, codigo);
    novo->rnn = rnn;
    novo->prox = NULL;
    return novo;
}

NoCodigo *newNoCodigo(string codigo) {
    NoCodigo *novo = malloc(sizeof(NoCodigo));
    novo->codigo = malloc(TAM_COD + 1);
    strcpy(novo->codigo, codigo);
    novo->prox = NULL;
    return novo;
}

void insereCodigo(NoS *noS, NoCodigo *noC) {
    //se a lista está vazia
    if (noS->head == NULL) {
        noS->head = noC;
        return;
    }

    NoCodigo *aux = noS->head;
    NoCodigo *prev = NULL;

    //procuramos a posição certa
    while (aux != NULL && strcmp(noC->codigo, aux->codigo) > 0) {
        prev = aux;
        aux = aux->prox;
    }

    //se estamos na posição certa, inserimos
    if (strcmp(noC->codigo, aux->codigo) < 0) {
        prev->prox = noC;
        noC->prox = aux;
        return;
    }

    //senão, estamos no final, e inserimos
    prev->prox = noC;
}

NoS *newNoS(string titulo) {
    NoS *novo = malloc(sizeof(NoS));
    novo->titulo = malloc(TAM_TIT_PT + 1);
    strcpy(novo->titulo, titulo);
    novo->head = NULL;
    novo->prox = NULL;
    return novo;
}

IndiceP *newIndiceP() {
    IndiceP *novo = malloc(sizeof(IndiceP));
    novo->head = NULL;
    novo->tamanho = 0;
    return novo;
}

IndiceS *newIndiceS() {
    IndiceS *novo = malloc(sizeof(IndiceS));
    novo->head = NULL;
    novo->tamanho = 0;
    return novo;
}

void insereNoP(IndiceP *index, NoP *no) {
    //se o índice está vazio
    if (index->head == NULL) {
        index->head = no;
        index->tamanho++;
        return;
    }

    NoP *aux = index->head;
    NoP *prev = NULL;

    //procuramos a posição certa; sai do while quando é menor ou igual que aux, ou se chegamos ao final da index
    while (aux != NULL && strcmp(no->codigo, aux->codigo) > 0) {
        prev = aux;
        aux = aux->prox;
    }

    //se estamos na posição certa, inserimos
    if (strcmp(no->codigo, aux->codigo) < 0) {
        prev->prox = no;
        no->prox = aux;
        index->tamanho++;
        return;
    }

    //senão, estamos no final, e inserimos
    prev->prox = no;
    index->tamanho++;
}

void insereNoS(IndiceS *index, NoS *no) {
    //se a lista está vazia
    if (index->head == NULL) {
        index->head = no;
        index->tamanho++;
        return;
    }

    //não estamos no começo
    NoS *aux = index->head;
    NoS *prev = NULL;

    //procuramos a posição certa; sai do while quando no é menor ou igual que aux, ou se chegamos ao final da lista
    while (aux != NULL && strcmp(no->titulo, aux->titulo) > 0) {
        prev = aux;
        aux = aux->prox;
    }

    //se estamos na posição certa, inserimos
    if (strcmp(no->titulo, aux->titulo) < 0) {
        prev->prox = no;
        no->prox = aux;
        index->tamanho++;
        return;
    }

    //senão, estamos no final, e inserimos
    prev->prox = no;
    index->tamanho++;
}

NoP *buscaNoP(IndiceP *index, string codigo) {
    NoP *current;

    int left = 0;
    int right = index->tamanho - 1;
    int middle;

    while (left <= right) {
        middle = left + (right - left) / 2;

        current = index->head;
        for (int i = 0; i < middle; i++)
            current = current->prox;

        if (strcmp(current->codigo, codigo) == 0)
            return current;
        else if (strcmp(current->codigo, codigo) < 0)
            left = middle + 1;
        else
            right = middle - 1;
    }

    return NULL;
}

NoS *buscaNoS(IndiceS *index, string titulo) {
    if (index->head == NULL)
        return NULL;

    NoS *aux = NULL;

    int left = 0;
    int right = index->tamanho;
    int middle;

    while (left <= right) {
        middle = left + (right - left) / 2;

        aux = index->head;
        for (int i = 0; i < middle; i++)
            aux = aux->prox;

        if (strcmp(aux->titulo, titulo) == 0)
            return aux;
        else if (strcmp(aux->titulo, titulo) < 0)
            right = middle - 1;
        else
            left = middle - 1;
    }

    return NULL;
}

IndiceP *lerP(FILE *iprimary) {
    IndiceP *novo = newIndiceP(); //aloca na memória e inicializa
    NoP *current; //nó do filme sendo lido

    string codigo = malloc(TAM_COD + 1);
    int rnn;

    //enquanto há linhas para ler, armazena as informações, cria um novo nó, e o insere no índice
    fseek(iprimary, 1, SEEK_SET);
    while (fscanf(iprimary, "%s@%d@", codigo, &rnn) != EOF) {
        current = newNoP(codigo, rnn);
        insereNoP(novo, current);
    }
    free(codigo);
    return novo;
}

IndiceS *lerS(FILE *ititle) {
    IndiceS *novo = newIndiceS(); //aloca na memória e inicializa
    NoS *auxS = NULL; //nó do filme sendo lido
    NoCodigo *auxC = NULL;  //nó de código que será adicionado

    string titulo = malloc(TAM_TIT_PT + 1);
    string codigos = malloc((TAM_COD + 1) * 10);
    string codigo = malloc(TAM_COD + 1);

    //enquanto há linhas para ler, lê a linha e armazena as informações
    fseek(ititle, 1, SEEK_SET);
    while (fscanf(ititle, "%[^\n]s@%s@", titulo, codigos) != EOF) {
        auxS = newNoS(titulo); //cria um novo NoS, com o título lido

        //nesse NoS, colocaremos uma lista de códigos
        auxC = NULL;

        //enquanto houverem códigos, adicionamos à lista
        while (sscanf(codigos, "%s,", codigo) == 1) {
            auxC = newNoCodigo(codigo);
            insereCodigo(auxS, auxC);
        }

        insereNoS(novo, auxS); //inserimos o nó criado no índice
    }
    free(titulo);
    free(codigos);
    free(codigo);
    return novo;
}

IndiceP *refazerP(FILE *movies) {
    IndiceP *novo = newIndiceP(); //aloca e inicializa um IndiceP

    int rnn = 0; //RNN do filme sendo lido

    string filme = malloc(TAM_FILME + 1);
    string codigo = malloc(TAM_COD + 1);

    NoP *current = NULL;

    //enquanto há filmes para ler, lê o filme
    fseek(movies, 0, SEEK_SET);
    while (fscanf(movies, "%"STRINGIFY(TAM_FILME)"[^\n]s", filme) != EOF) {
        if (filme[0] != '*' && filme[1] != '|') {
            sscanf(filme, "%"STRINGIFY(TAM_COD)"s", codigo);
            current = newNoP(codigo, rnn);
            insereNoP(novo, current);
        }
        rnn++; //passamos para o próximo filme
    }
    free(filme);
    free(codigo);
    return novo;
}

IndiceS *refazerS(FILE *movies) {
    IndiceS *novo = newIndiceS();

    string filme = malloc(TAM_FILME + 1);
    string codigo = malloc(TAM_COD + 1);
    string titulo = malloc(TAM_TIT_PT + 1);

    NoS *currentS = NULL;
    NoCodigo *currentC = NULL;

    //enquanto há filmes para ler, lê o filme
    fseek(movies, 0, SEEK_SET);
    while (fscanf(movies, "%"STRINGIFY(TAM_FILME)"[^\n]s", filme) != EOF) {
        if (filme[0] != '*' && filme[1] != '|') {
            sscanf(filme, "%"STRINGIFY(TAM_COD)"s@%"STRINGIFY(TAM_TIT_PT)"[^@]s", codigo, titulo);

            currentC = newNoCodigo(codigo);

            //verifica se o título já tem um NoS correspondente em IndiceS
            currentS = buscaNoS(novo, titulo);
            if (currentS == NULL) { //se não há um NoS para esse título
                currentS = newNoS(titulo); //cria um novo NoS para esse título
                insereCodigo(currentS, currentC); //coloca o código nesse NoS
                insereNoS(novo, currentS); //insere o NoS no IndiceS
            } else //insere um novo NoCodigo, para esse titulo, na lista do NoS já existente
                insereCodigo(currentS, currentC);
        }
    }
    free(filme);
    free(codigo);
    free(titulo);
    return novo;
}

void saveIndiceP(IndiceP *index) {
    FILE *iprimary = fopen("data/iprimary.idx", "w");

    fputc('1', iprimary);

    NoP *printHead = index->head;
    while (printHead) {
        fprintf(iprimary, "%s@%d@", printHead->codigo, printHead->rnn);
        printHead = printHead->prox;
    }

    fseek(iprimary, 0, SEEK_SET);
    fputc('0', iprimary);
    fclose(iprimary);
}

void saveIndiceS(IndiceS *index) {
    FILE *ititle = fopen("data/ititle.idx", "w");

    fputc('1', ititle);

    NoS *printHeadS = index->head;
    NoCodigo *printHeadCod;

    while (printHeadS) {
        fprintf(ititle, "%s@", printHeadS->titulo);

        printHeadCod = printHeadS->head;
        while (printHeadCod) {
            fprintf(ititle, "%s", printHeadCod->codigo);
            printHeadCod = printHeadCod->prox;
            if (printHeadCod != NULL)
                fputc(',', ititle);
        }
        fputc('@', ititle);

        printHeadS = printHeadS->prox;
    }

    fseek(ititle, 0, SEEK_SET);
    fputc('0', ititle);
    fclose(ititle);
}

void freeIndiceP(IndiceP *index) {
    NoP *aux;
    while (index->head) {
        aux = index->head->prox;
        free(index->head);
        index->head = aux;
    }
    free(index);
}

void freeIndiceS(IndiceS *index) {
    NoS *auxS;
    NoCodigo *auxCod;

    while (index->head) {
        auxS = index->head->prox;

        while (auxS->head) {
            auxCod = auxS->head->prox;
            free(auxS->head);
            auxS->head = auxCod;
        }
        free(index->head);

        index->head = auxS;
    }
    free(index);
}

int rnnFromCodigo(IndiceP *index, string codigo) {
    NoP *aux = NULL;

    int l = 0;
    int r = index->tamanho - 1;
    int m;

    while (l <= r) {
        m = l + (r - l) / 2;

        aux = index->head;
        for (int i = 0; i < m; i++)
            aux = aux->prox;

        if (strcmp(aux->codigo, codigo) == 0)
            return aux->rnn;
        else if (strcmp(aux->codigo, codigo) < 0)
            l = m + 1;
        else
            r = m - 1;
    }

    return -1;
}

void removerNoP(IndiceP *index, string codigo) {
    NoP *current, *prev;

    int left = 0;
    int right = index->tamanho - 1;
    int middle;

    while (left <= right) {
        middle = left + (right - left) / 2;

        current = index->head;
        for (int i = 0; i < middle; i++) {
            prev = current;
            current = current->prox;
        }

        if (strcmp(current->codigo, codigo) == 0) {
            prev->prox = current->prox;
            free(current);
            return;
        } else if (strcmp(current->codigo, codigo) < 0)
            left = middle + 1;
        else
            right = middle - 1;
    }
}

void removerNoCodigo(NoS *no, char *codigo) {
    NoCodigo *current = no->head;
    NoCodigo *prev;

    while (strcmp(current->codigo, codigo) != 0) {
        prev = current;
        current = current->prox;
    }

    prev->prox = current->prox;
    free(current);
}

void insereFilme(IndiceP *indexP, IndiceS *indexS, string codigo, string titulo, int rnn) {
    NoP *noP = newNoP(codigo, rnn);
    NoS *noS = buscaNoS(indexS, titulo);
    NoCodigo *novoC = newNoCodigo(codigo);

    insereNoP(indexP, noP);

    if (noS == NULL) {
        noS = newNoS(titulo);
        insereCodigo(noS, novoC);
        insereNoS(indexS, noS);
    } else {
        insereCodigo(noS, novoC);
    }
}

void removeFilme(IndiceP *indexP, IndiceS *indexS, string codigo, string titulo) {
    removerNoP(indexP, codigo);
    NoS *noS = buscaNoS(indexS, titulo);
    removerNoCodigo(noS, codigo);
}

