#ifndef INDICES
#define INDICES

typedef struct {
    int flag;

} IPrimario;

typedef struct {
    int flag;


} ISecundario;

IPrimario *newPrimario() {
    IPrimario *novo = malloc(sizeof(IPrimario));

    ///////////////////////////////

    return novo;
}

ISecundario *newSecundario() {
    ISecundario *novo = malloc(sizeof(ISecundario));

    ///////////////////////////////

    return novo;
}

IPrimario *readPrimario(FILE *iPrimario) {

}

ISecundario readSecundario(FILE *iSecundario) {

}


#endif