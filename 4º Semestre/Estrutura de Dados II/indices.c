
#include "indices.h"

NoP *newNoP(string chave, int conteudo) {
    NoP *novo = malloc(sizeof(NoP));
    strcpy(novo->chave, chave);
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
    strcpy(novo->chave, chave);
    novo->head = NULL;
    novo->prox = NULL;
    return novo;
}

IndiceP *newIndiceP() {
    IndiceP *novo = malloc(sizeof(IndiceP));
    novo->flag = 0;
    novo->head = NULL;
    return novo;
}

IndiceS *newIndiceS() {
    IndiceS *novo = malloc(sizeof(IndiceS));
    novo->flag = 0;
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
    while (aux != NULL && strcmp(no->chave, aux->chave) > 0) {
        prev = aux;
        aux = aux->prox;
    }

    //se estamos na posição certa, inserimos
    if (strcmp(no->chave, aux->chave) < 0) {
        prev->prox = no;
        no->prox = aux;
        return;
    }

    //senão, estamos no final, e inserimos
    aux->prox = no;
}

void insereNoS(NoS *no, IndiceS *lista) {
    //se estamos inserindo no começo
    if (lista->head == NULL) {
        lista->head = no;
        return;
    }

    //não estamos no começo
    NoS *aux = lista->head;
    NoS *prev = NULL;

    //procuramos a posição certa; sai do while quando no é menor ou igual que aux, ou se chegamos ao final da lista
    while (aux != NULL && strcmp(no->chave, aux->chave) > 0) {
        prev = aux;
        aux = aux->prox;
    }

    //se estamos na posição certa, inserimos
    if (strcmp(no->chave, aux->chave) < 0) {
        prev->prox = no;
        no->prox = aux;
        return;
    }

    //senão, estamos no final, e inserimos
    aux->prox = no;
}

NoS *localizaTitulo(char *titulo, IndiceS *lista) {
    NoS *left = lista->head;
    NoS *right = NULL;
    NoS *middle = NULL;
    int count; //número de nós na lista

    while (left != right) {
        middle = left;
        count = 0;

        while (middle != right) {
            middle = middle->prox;
            count++;
        }

        middle = lista->head;
        for (int i = 0; i < count / 2; i++)
            middle = middle->prox;

        if (strcmp(middle->chave, titulo) == 0)
            return middle;
        else if (strcmp(middle->chave, titulo) < 0)
            left = middle->prox;
        else
            right = middle;
    }

    return NULL;
}

IndiceP *lerP(FILE *index) {
    IndiceP *novo = newIndiceP(); //aloca na memória e inicializa
    NoP *current; //nó da entrada sendo lida

    string chave = NULL;
    int i;

    //enquanto há linhas para ler, armazena as informações, cria um novo nó, e o insere no índice
    while (fscanf(index, "%s@%d@", chave, &i) != 0) {
        current = newNoP(chave, i);
        insereNoP(current, novo);
    }
    rewind(index);
    return novo;
}

IndiceS *lerS(FILE *index) {
    IndiceS *novo = newIndiceS(); //aloca na memória e inicializa
    NoS *current; //nó da entrada sendo lida

    string chave = NULL;
    string conteudo = NULL;
    string token;

    NoCodigo *head; //começo da lista de códigos
    NoCodigo *aux;  //nó de código que será adicionado

    //enquanto há linhas para ler, lê a linha e armazena as informações
    while (fscanf(index, "%s@%s@", chave, conteudo) != 0) {
        current = newNoS(chave); //cria um novo NoS, com a chave lida

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

        insereNoS(current, novo); //inserimos o nó criado no índice
    }
    rewind(index);
    return novo;
}

IndiceP *refazerP(FILE *source) {
    IndiceP *novo = newIndiceP(); //aloca e inicializa um IndiceP

    int pos = 0; //RNN da entrada sendo lida

    string entrada = NULL;
    string token;

    NoP *current;

    //enquanto há entradas para ler, lê a entrada
    while (fgets(entrada, TAM_ENTRADA, source) != 0) {
        if (entrada[0] != '*' && entrada[1] != '|') {
            token = strtok(entrada, "@");

            current = newNoP(token, pos);
            insereNoP(current, novo);
        }
        pos++; //passamos para a próxima posição de entrada
    }

    rewind(source);
    return novo;
}

IndiceS *refazerS(FILE *source) {
    IndiceS *novo = newIndiceS();

    int pos = 0; //RNN da entrada sendo lida

    string entrada = NULL;
    string titulo;

    NoS *current;

    //enquanto há entradas para ler, lê a entrada
    while (fgets(entrada, TAM_ENTRADA, source) != 0) {
        if (entrada[0] != '*' && entrada[1] != '|') {
            strtok(entrada, "@"); //primeiro campo
            titulo = strtok(NULL, "@"); //segundo campo

            current = localizaTitulo(titulo, novo); //verifica se o título já tem um NoS correspondente em IndiceS
            if (current) {
                //insere um novo NoCodigo, para esse titulo, na lista do NoS current
                insereCodigo(current->head, newNoCodigo(titulo));
            } else { //se não há um NoS para esse título
                current = newNoS(titulo); //cria um novo NoS para esse título
                insereNoS(current, novo); //insere ele no IndiceS
            }
        }
        pos++; //passamos para a próxima posição de entrada
    }

    rewind(source);
    return novo;
}

void saveIndiceP(IndiceP *index, FILE *file) {
    fputc('0', file);

    NoP *printHead = index->head;
    while (printHead) {
        fprintf(file, "%s@%d@", printHead->chave, printHead->i);
        printHead = printHead->prox;
    }
    rewind(file);
}

void saveIndiceS(IndiceS *index, FILE *file) {
    fputc('0', file);

    NoS *printHeadS = index->head;
    NoCodigo *printHeadCod;

    while (printHeadS) {
        fprintf(file, "%s@", printHeadS->chave);

        printHeadCod = printHeadS->head;
        while (printHeadCod) {
            fprintf(file, "%s,", printHeadCod->codigo);
            printHeadCod = printHeadCod->prox;
        }
        fprintf(file, "@");

        printHeadS = printHeadS->prox;
    }
    rewind(file);
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
    NoP *left = index->head;
    NoP *right = NULL;
    NoP *middle = NULL;

    int count; //número de nós no índice

    while (left != right) {
        middle = left;
        count = 0;

        while (middle != right) {
            middle = middle->prox;
            count++;
        }

        middle = index->head;
        for (int i = 0; i < count / 2; i++)
            middle = middle->prox;

        if (strcmp(middle->chave, codigo) == 0)
            return middle->i;
        else if (strcmp(middle->chave, codigo) < 0)
            left = middle->prox;
        else
            right = middle;
    }

    return -1;
}
