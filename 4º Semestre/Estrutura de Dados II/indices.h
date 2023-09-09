#ifndef INDICES
#define INDICES

typedef struct noP {
    char *chave;     //iPrimário: código
    char *conteudo;  //iPrimário: byte offset
    struct noP *prox;
} NoP;

typedef struct noS {
    char *chave;     //iSecundário: título
    char **conteudo;  //iSecundário: chave primária
    struct noS *prox;
} NoS;

typedef struct {
    int flag;
    NoP *head;
} IndiceP;

typedef struct {
    int flag;
    NoS *head;
} IndiceS;


NoP *newNoP(char *chave, char *conteudo) {
    NoP *novo = malloc(sizeof(NoP));
    strcpy(novo->chave, chave);
    strcpy(novo->conteudo, conteudo);
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
    IndiceS *novo;

    return novo;
}

void insereNoP(NoP *no, IndiceP *lista) {
    NoP *head;
}

IndiceP *readIndiceP(FILE *index) {
    IndiceP *novo = newIndiceP();
    NoP *current;

    char *charactere;
    int field = 0;
    char *codigo = "", *endereco = "";

    while ((*charactere = fgetc(index) != EOF)) {
        if (*charactere == '@') {
            field++;
            if (field == 2) {
                current = newNoP(codigo, endereco);
                insereNoP(current, novo);
                field = 0;

                //apaga código
                //apaga endereço
            }
        } else {
            switch (field) {
                case 0: //estamos no código
                    strcat(codigo, charactere);
                    break;
                case 1: //estamos no endereço
                    strcat(endereco, charactere);
                    break;
                default:
                    break;
            }
        }
    }
    return novo;
}

IndiceS *readIndiceS(FILE *index) {
    IndiceS *novo = newIndiceS();


    return novo;
}


#endif