#include "indices.h"

NoP *newNoP(string chave, int conteudo) {
    NoP *novo = malloc(sizeof(NoP));
    strcpy(novo->codigo, chave);
    novo->i = conteudo;
    novo->prox = NULL;
    return novo;
}

NoCodigo *newNoCodigo(string codigo) {
    NoCodigo *novo = malloc(sizeof(NoCodigo));
    strcpy(novo->codigo, codigo);
    novo->prox = NULL;
    return novo;
}

void insereCodigo(NoCodigo *head, NoCodigo *no) {
    //se estamos inserindo no começo
    if (head == NULL) {
        head = no;
        return;
    }

    NoCodigo *aux = head;
    NoCodigo *prev = NULL;

    //procuramos a posição certa
    while (aux != NULL && strcmp(no->codigo, aux->codigo) > 0) {
        prev = aux;
        aux = aux->prox;
    }

    //se estamos na posição certa, inserimos
    if (strcmp(no->codigo, aux->codigo) < 0) {
        prev->prox = no;
        no->prox = aux;
        return;
    }

    //senão, estamos no final, e inserimos
    aux->prox = no;
}

NoS *newNoS(string chave) {
    NoS *novo = malloc(sizeof(NoS));
    strcpy(novo->titulo, chave);
    novo->head = NULL;
    novo->prox = NULL;
    return novo;
}

IndiceP *newIndiceP() {
    IndiceP *novo = malloc(sizeof(IndiceP));
    novo->head = NULL;
    return novo;
}

IndiceS *newIndiceS() {
    IndiceS *novo = malloc(sizeof(IndiceS));
    novo->head = NULL;
    return novo;
}

void insereNoP(NoP *no, IndiceP *index) {
    //se estamos inserindo no começo
    if (index->head == NULL) {
        index->head = no;
        return;
    }

    //não estamos no começo
    NoP *aux = index->head;
    NoP *prev = NULL;

    //procuramos a posição certa; sai do while quando no é menor ou igual que aux, ou se chegamos ao final da index
    while (aux != NULL && strcmp(no->codigo, aux->codigo) > 0) {
        prev = aux;
        aux = aux->prox;
    }

    //se estamos na posição certa, inserimos
    if (strcmp(no->codigo, aux->codigo) < 0) {
        prev->prox = no;
        no->prox = aux;
        return;
    }

    //senão, estamos no final, e inserimos
    aux->prox = no;
}

void insereNoS(IndiceS *lista, NoS *no) {
    //se estamos inserindo no começo
    if (lista->head == NULL) {
        lista->head = no;
        return;
    }

    //não estamos no começo
    NoS *aux = lista->head;
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
        return;
    }

    //senão, estamos no final, e inserimos
    aux->prox = no;
}

NoS *localizaTitulo(IndiceS *lista, char *titulo) {
    int count = 0; //número de nós na lista
    NoS *current = lista->head;

    while (current != NULL) {
        count++;
        current = current->prox;
    }

    int left = 0;
    int right = count - 1;
    int middle;

    while (left <= right) {
        printf("136indices\n");
        middle = left + (right - left) / 2;

        current = lista->head;
        for (int i = 0; i < middle; i++)
            current = current->prox;

        if (strcmp(current->titulo, titulo) == 0)
            return current;
        else if (strcmp(current->titulo, titulo) < 0)
            left = middle + 1;
        else
            right = middle - 1;
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
    while (fscanf(iprimary, "%s@%d@", codigo, &rnn) != 0) {
        printf("161");
        current = newNoP(codigo, rnn);
        insereNoP(current, novo);
    }
    free(codigo);
    return novo;
}

IndiceS *lerS(FILE *ititle) {
    IndiceS *novo = newIndiceS(); //aloca na memória e inicializa
    NoS *current; //nó do filme sendo lido

    string codigo = malloc(TAM_TIT_PT + 1);
    string conteudo = malloc((TAM_COD + 1) * 100);
    string token;

    NoCodigo *head; //começo da lista de códigos
    NoCodigo *aux;  //nó de código que será adicionado

    //enquanto há linhas para ler, lê a linha e armazena as informações
    fseek(ititle, 1, SEEK_SET);
    while (fscanf(ititle, "%s@%s@", codigo, conteudo) != 0) {
        current = newNoS(codigo); //cria um novo NoS, com a codigo lida

        //nesse NoS, colocaremos uma lista de códigos
        head = NULL;
        aux = NULL;
        //quebramos a string "conteudo" lida do arquivo em tokens: os códigos separados por vírgula
        token = strtok(conteudo, ",");

        //enquanto houverem tokens, adicionamos à lista
        while (token != NULL) {
            aux = newNoCodigo(token);
            insereCodigo(head, aux);
            token = strtok(NULL, ","); //pega o próximo token
        }

        insereNoS(novo, current); //inserimos o nó criado no índice
    }
    free(codigo);
    free(conteudo);
    return novo;
}

IndiceP *refazerP(FILE *movies) {
    IndiceP *novo = newIndiceP(); //aloca e inicializa um IndiceP

    int rnn = 0; //RNN do filme sendo lido

    string filme = malloc(TAM_FILME + 1);
    string token;

    NoP *current;

    //enquanto há filmes para ler, lê o filme
    fseek(movies, 0, SEEK_CUR);
    while (1) {
        if (fgets(filme, TAM_FILME, movies) == NULL)
            break;

        if (filme[0] != '*' && filme[1] != '|') {
            token = strtok(filme, "@");

            current = newNoP(token, rnn);
            insereNoP(current, novo);
        }
        rnn++; //passamos para o próximo filme
    }
    free(filme);
    return novo;
}

IndiceS *refazerS(FILE *movies) {
    IndiceS *novo = newIndiceS();

    string filme = malloc(TAM_FILME + 1);
    string codigo;
    string titulo;

    NoS *currentS;
    NoCodigo *currentC;

    //enquanto há filmes para ler, lê o filme
    fseek(movies, 0, SEEK_SET);
    while (1) {
        if (fgets(filme, TAM_FILME, movies) == NULL)
            break;

        if (filme[0] != '*' && filme[1] != '|') {
            codigo = strtok(filme, "@"); //primeiro campo
            titulo = strtok(NULL, "@"); //segundo campo

            currentS = localizaTitulo(novo, titulo); //verifica se o título já tem um NoS correspondente em IndiceS
            currentC = newNoCodigo(codigo);
            printf("257\n");
            if (currentS)
                insereCodigo(currentS->head,
                             currentC); //insere um novo NoCodigo, para esse titulo, na lista do NoS currentS
            else { //se não há um NoS para esse título
                printf("262\n");
                currentS = newNoS(titulo); //cria um novo NoS para esse título
                insereCodigo(currentS->head, currentC);
                printf("265\n");
                insereNoS(novo, currentS); //insere ele no IndiceS
                printf("267\n");
            }
        }
    }
    free(filme);
    return novo;
}

void saveIndiceP(IndiceP *index) {
    FILE *iprimary = fopen("data/iprimary.idx", "w");

    fputc('1', iprimary);

    NoP *printHead = index->head;
    while (printHead) {
        fprintf(iprimary, "%s@%d@", printHead->codigo, printHead->i);
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

int rnnFromCodigo(IndiceP *index, char *codigo) {
    int count = 0; //número de nós na lista
    NoP *current = index->head;

    while (current != NULL) {
        count++;
        current = current->prox;
    }

    int left = 0;
    int right = count - 1;
    int middle;

    while (left <= right) {
        middle = left + (right - left) / 2;

        current = index->head;
        for (int i = 0; i < middle; i++)
            current = current->prox;

        if (strcmp(current->codigo, codigo) == 0)
            return current->i;
        else if (strcmp(current->codigo, codigo) < 0)
            left = middle + 1;
        else
            right = middle - 1;
    }

    return -1;
}
