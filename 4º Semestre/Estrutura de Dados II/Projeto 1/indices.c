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

    //começamos pelo começo da lista
    NoCodigo *aux = noS->head;
    NoCodigo *prev = NULL;

    //procuramos a posição certa; sai do while se quando noC é menor do que aux, ou se chegamos no final da lista
    while (aux != NULL && strcmp(noC->codigo, aux->codigo) > 0) {
        prev = aux;
        aux = aux->prox;
    }

    //se estamos no final da lista
    if (aux == NULL) {
        prev->prox = noC;
        return;
    }

    //se estamos na posição certa
    if (strcmp(noC->codigo, aux->codigo) < 0) {
        //se estamos no começo da lista
        if (prev == NULL) {
            noC->prox = noS->head;
            noS->head = noC;
        } else { //se estamos no meio da lista
            prev->prox = noC;
            noC->prox = aux;
        }
    }
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

    //começamos pelo começo da lista
    NoP *aux = index->head;
    NoP *prev = NULL;

    //procuramos a posição certa; sai do while quando no é menor ou igual que aux, ou se chegamos ao final da index
    while (aux != NULL && strcmp(no->codigo, aux->codigo) > 0) {
        prev = aux;
        aux = aux->prox;
    }

    //se estamos no final
    if (aux == NULL) {
        prev->prox = no;
        index->tamanho++;
        return;
    }

    //se estamos na posição certa
    if (strcmp(no->codigo, aux->codigo) < 0) {
        //se estamos no início da lista
        if (prev == NULL) {
            no->prox = index->head;
            index->head = no;
        } else { //se estamos no meio da lista
            prev->prox = no;
            no->prox = aux;
        }
        index->tamanho++;
    }
}

void insereNoS(IndiceS *index, NoS *no) {
    //se a lista está vazia
    if (index->head == NULL) {
        index->head = no;
        index->tamanho++;
        return;
    }

    //começamos pelo começo da lista
    NoS *aux = index->head;
    NoS *prev = NULL;

    //procuramos a posição certa; sai do while quando no é menor ou igual que aux, ou se chegamos ao final da lista
    while (aux != NULL && strcmp(no->titulo, aux->titulo) > 0) {
        prev = aux;
        aux = aux->prox;
    }

    //se estamos no final da lista
    if (aux == NULL) {
        prev->prox = no;
        index->tamanho++;
        return;
    }

    //se estamos na posição certa
    if (strcmp(no->titulo, aux->titulo) < 0) {
        //se estamos no começo da lista
        if (prev == NULL) {
            no->prox = index->head;
            index->head = no;
        } else { //se estamos no meio da lista
            prev->prox = no;
            no->prox = aux;
        }
        index->tamanho++;
    }
}

NoP *buscaNoP(IndiceP *index, string codigo) {
    //se a lista está vazia
    if (index->head == NULL)
        return NULL;

    NoP *aux;

    int l = 0;
    int r = index->tamanho - 1;
    int m;

    while (l <= r) {
        m = l + (r - l) / 2;

        aux = index->head;
        for (int i = 0; i < m; i++)
            aux = aux->prox;

        if (strcmp(aux->codigo, codigo) == 0)
            return aux;
        else if (strcmp(aux->codigo, codigo) < 0)
            l = m + 1;
        else
            r = m - 1;
    }

    return NULL;
}

NoS *buscaNoS(IndiceS *index, string titulo) {
    //se a lista está vazia
    if (index->head == NULL)
        return NULL;

    NoS *aux;

    int l = 0;
    int r = index->tamanho - 1;
    int m;

    while (l <= r) {
        m = l + (r - l) / 2;

        aux = index->head;
        for (int i = 0; i < m; i++)
            aux = aux->prox;

        if (strcmp(aux->titulo, titulo) == 0)
            return aux;
        else if (strcmp(aux->titulo, titulo) < 0)
            l = m + 1;
        else
            r = m - 1;
    }

    return NULL;
}

IndiceP *lerP(FILE *iprimary) {
    IndiceP *novo = newIndiceP(); //aloca e inicializa um IndiceP
    NoP *current = NULL; //NoP sendo lido

    string codigo = malloc(TAM_COD + 1);
    int rnn;

    //enquanto há linhas para ler, armazena as informações
    fseek(iprimary, 1, SEEK_SET);
    while (fscanf(iprimary, "%[^@]@%d@", codigo, &rnn) != EOF) {
        current = newNoP(codigo, rnn);      //cria um NoP
        insereNoP(novo, current); //insere o NoP no índice
    }
    free(codigo);
    return novo;
}

IndiceS *lerS(FILE *ititle) {
    IndiceS *novo = newIndiceS(); //aloca e inicializa um IndiceS
    NoS *auxS = NULL; //NoS sendo lido
    NoCodigo *auxC = NULL;  //NoCodigo que irá iterar pelos códigos a serem adicionado ao NoS

    string titulo = malloc(TAM_TIT_PT + 1);
    string codigos = malloc((TAM_COD + 1) * 10);
    string codigo = malloc(TAM_COD + 1);

    //enquanto há linhas para ler, armazena as informações
    fseek(ititle, 1, SEEK_SET);
    while (fscanf(ititle, "%[^@]@%[^@]@", titulo, codigos) != EOF) {
        auxS = newNoS(titulo); //cria um novo NoS, com o título lido

        //nesse NoS, colocaremos uma lista de códigos
        auxC = NULL;

        //enquanto houverem códigos, lemos as informações
        int i = 0;
        while (sscanf_s(codigos + i, "%5s", codigo, sizeof(codigo)) == 1) {
            auxC = newNoCodigo(codigo);         //criamos um NoCodigo
            insereCodigo(auxS, auxC); //inserimos o NoCodigo no NoS
            i += 5; // Avança para o próximo conjunto de 5 caracteres
        }

        insereNoS(novo, auxS); //inserimos o NoS criado no IndiceS novo
    }
    free(titulo);
    free(codigos);
    free(codigo);
    return novo;
}

IndiceP *refazerP(FILE *movies) {
    IndiceP *novo = newIndiceP(); //aloca e inicializa um IndiceP
    NoP *current = NULL; //NoP da entrada sendo lida

    int rnn = 0; //RNN da entrada sendo lida; começamos em 0

    string filme = malloc(TAM_FILME + 1);
    string codigo = malloc(TAM_COD + 1);

    //enquanto há entradas para ler, armazena as informações
    fseek(movies, 0, SEEK_SET);
    while (fscanf(movies, "%"STRINGIFY(TAM_FILME)"[^\n]s", filme) != EOF) {
        if (filme[0] != '*' && filme[1] != '|') {
            sscanf(filme, "%[^@]@", codigo); //lê o primeiro campo, o código
            current = newNoP(codigo, rnn); //cria um NoP
            insereNoP(novo, current); //insere o NoP no IndiceP novo
        }
        rnn++; //passamos para a prósxima entrada
    }
    free(filme);
    free(codigo);
    return novo;
}

IndiceS *refazerS(FILE *movies) {
    IndiceS *novo = newIndiceS(); //aloca e inicializa um IndiceS

    string filme = malloc(TAM_FILME + 1);
    string codigo = malloc(TAM_COD + 1);
    string titulo = malloc(TAM_TIT_PT + 1);

    NoS *currentS = NULL;
    NoCodigo *currentC = NULL;

    //enquanto há entradas para ler, armazena as informações
    fseek(movies, 0, SEEK_SET);
    while (fscanf(movies, "%"STRINGIFY(TAM_FILME)"[^\n]s", filme) != EOF) {
        if (filme[0] != '*' && filme[1] != '|') {
            sscanf(filme, "%[^@]@%[^@]@", codigo, titulo);

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
    FILE *iprimary = fopen("data/iprimary.idx", "w"); //abre o arquivo para ser reescrito

    fputc('1', iprimary); //marca ele como inconsistente, caso o processo seja interrompido

    //percorre a lista de índice primario, imprimindo as informações no arquivo
    NoP *printHead = index->head;
    while (printHead) {
        fprintf(iprimary, "%s@%d@", printHead->codigo, printHead->rnn);
        printHead = printHead->prox;
    }

    fseek(iprimary, 0, SEEK_SET); //retorna ao começo do arquivo
    fputc('0', iprimary); //marca o arquivo como consistente
    fclose(iprimary); //fecha o arquivo
}

void saveIndiceS(IndiceS *index) {
    FILE *ititle = fopen("data/ititle.idx", "w"); //abre o arquivo para ser reescrito

    fputc('1', ititle); //marca ele como inconsistente, caso o processo seja interrompido

    //percorre a lista de índice secundário, imprimindo as informações no arquivo
    NoS *printHeadS = index->head;
    NoCodigo *printHeadCod; //para iterar pela lista de códigos de cada NoS
    while (printHeadS) {
        fprintf(ititle, "%s@", printHeadS->titulo); //imprime o campo do título

        //percorre a lista de códigos, imprimindo as informações no campo correspondente
        printHeadCod = printHeadS->head;
        while (printHeadCod) {
            fprintf(ititle, "%s", printHeadCod->codigo);
            printHeadCod = printHeadCod->prox;
        }
        fputc('@', ititle); //encerra o campo dos códigos

        printHeadS = printHeadS->prox;
    }

    fseek(ititle, 0, SEEK_SET); //retorna ao começo do arquivo
    fputc('0', ititle); //marca o arquivo como consistente
    fclose(ititle); //fecha o arquivo
}

void freeIndiceP(IndiceP *index) {
    NoP *aux;
    while (index->head) {
        aux = index->head->prox;
        free(index->head->codigo);
        free(index->head);
        index->head = aux;
    }
    free(index);
}

void freeCodigos(NoCodigo *head) {
    while (head != NULL) {
        NoCodigo *freela = head;
        head = head->prox;
        free(freela->codigo); // Libera o código do filme
        free(freela); // Libera o NoCodigo
    }
}

void freeIndiceS(IndiceS *indice) {
    NoS *current = indice->head;
    while (current != NULL) {
        NoS *freela = current;
        current = current->prox;
        free(freela->titulo); // Libera o título do filme
        freeCodigos(freela->head); // Libera a lista de códigos associada a este NoS
        free(freela); // Libera o NoS
    }
    free(indice); // Libera o IndiceS
}

int rnnFromCodigo(IndiceP *index, string codigo) {
    //se o IndiceP está vazio
    if(index->head == NULL)
        return -1;

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

void insereFilme(IndiceP *indexP, IndiceS *indexS, string codigo, string titulo, int rnn) {
    NoP *noP = newNoP(codigo, rnn); //cria um NoP
    NoS *noS = NULL; //noS do título
    NoCodigo *novoC = newNoCodigo(codigo); //cria um NoCodigo

    insereNoP(indexP, noP); //insere NoP no IndiceP

    //verifica se já existe um NoS para o título sendo inserido
    noS = buscaNoS(indexS, titulo);
    if (noS == NULL) { //se não existe
        noS = newNoS(titulo); //cria um NoS
        insereCodigo(noS, novoC); //insere o NoCodigo no NoS
        insereNoS(indexS, noS); //insere o NoS no IndiceS
    } else //se existe
        insereCodigo(noS, novoC); //insere o NoC no NoS encontrado
}

void removeNoP(IndiceP *index, string codigo) {
    NoP *current, *prev;

    int l = 0;
    int r = index->tamanho - 1;
    int m;

    while (l <= r) {
        m = l + (r - l) / 2;

        current = index->head;
        for (int i = 0; i < m; i++) {
            prev = current;
            current = current->prox;
        }

        if (strcmp(current->codigo, codigo) == 0) {
            prev->prox = current->prox;
            free(current->codigo);
            free(current);
            return;
        } else if (strcmp(current->codigo, codigo) < 0)
            l = m + 1;
        else
            r = m - 1;
    }
}

void removeNoCodigo(NoS *no, char *codigo) {
    NoCodigo *current = no->head;
    NoCodigo *prev;

    while (strcmp(current->codigo, codigo) != 0) {
        prev = current;
        current = current->prox;
    }

    prev->prox = current->prox;
    free(current->codigo);
    free(current);
}

void removeNoS(IndiceS *index, string titulo) {
    NoS *current, *prev;

    int l = 0;
    int r = index->tamanho - 1;
    int m;

    while (l <= r) {
        m = l + (r - l) / 2;

        current = index->head;
        for (int i = 0; i < m; i++) {
            prev = current;
            current = current->prox;
        }

        if (strcmp(current->titulo, titulo) == 0) {
            prev->prox = current->prox;
            freeCodigos(current->head); //libera todos os NoCodigo associados
            free(current);
            return;
        } else if (strcmp(current->titulo, titulo) < 0)
            l = m + 1;
        else
            r = m - 1;
    }
}

void removeFilmeFromIndice(IndiceP *indexP, IndiceS *indexS, string codigo, string titulo) {
    removeNoP(indexP, codigo); //remove o código do índice primário
    NoS *noS = buscaNoS(indexS, titulo); //encontra o título no índice secundário
    removeNoCodigo(noS, codigo); //remove a associação do código com o título no índice secundário

    //se não há mais filmes com esse título
    if (noS->head == NULL)
        removeNoS(indexS, titulo); //remove o título do índice secundário
}

