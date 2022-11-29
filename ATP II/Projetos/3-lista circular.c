#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int I, K, O;
    struct lista *prox; //endereço od próximo elemento
}Lista;

Lista *l; //variável global do endereço inicial da lista circular

int ler();

int main(){
    int N = ler(); //realiza a leitura das entradas e preenche a lista, cujo endereço é global
 
    



    return 0;
}

int ler(){
    int N, i;

    scanf("%d", &N);
    l = malloc(N*sizeof(Lista));

    //preenchimento do vetor
    for(i = 0; i<N; i++)
    {
        l[i] = malloc(sizeof(Lista));
        l[i]->I = i+1;
        scanf("%d %d", l[i]->K, l[i]->O);

        if(i == 0) //primeiro elemento
            l[i]->prox = NULL; //começa apontando para o nada
        else if(i == N-1) //último elemento
            l[i]->prox = l[0]; //aponta para o primeiro
        else //demais elementos
            l[i-1]->prox = l[i]; //o elemento anterior passa a apontar para esse elemento
    }

    return N;
}
