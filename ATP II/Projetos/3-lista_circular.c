#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int I, K, O;
    struct lista *prox; //endereço do próximo elemento
}Lista;

Lista *l; //endereço inicial da lista circular (I = 1)
Lista *remov; //endereço da última pessoa removida

int ler();
void reinserir();
void josephus();

int main(){
    int N = ler(); //realiza a leitura das entradas e preenche a lista, cujo endereço é global
 
	josephus(N);
	
	printf("de volta à main\n");
	printf("%d", l->I);

    return 0;
}

int ler(){
    int N, i;
    Lista *new, *prev = NULL;

    scanf("%d", &N);

    //preenchimento da lista circular
    for(i = 1; i<N+1; i++)
    {
    	new = malloc(sizeof(Lista)); //a cada iteração, new aponta para um endereço novo
        new->I = i;
        //printf("%d %d\n", i, new->I);
        scanf("%d %d", &new->K, &new->O);
        //printf("%d %d", new->K, new->O);

        if(i == 1) //começo da lista
            l = new; //é o que acabou de ser lido
        else if(i == N) //último elemento
            new->prox = l; //aponta para o primeiro
        else //demais elementos
            prev->prox = new; //o elemento anterior passa a apontar para esse elemento
        
        prev = new;
        
        //printf("\n");
    }
    
    printf("lido\n");

    return N;
}

void reinserir(){
	Lista *aux = l;
	int num = remov->I;
	
	while(num > aux->I && aux->prox != l)
		aux = aux->prox;
	
	remov->prox = aux->prox;
	aux->prox = remov;
	
	if(aux == l) //se remov foi inserido logo no "início" da lista
		l = remov; //remov passa a ser o novo "início"
	
	return;
}

void josephus(int N){
	Lista *aux = l, *prev = NULL;
	int k, o;
	int i;
	
	k = l->K - 1;
	o = l->O;
	
	//anda até encontrar a pessoa a ser eliminada
	while(k > 0)
	{
		prev = aux;
		aux = aux->prox;
		
		k--;
	}
	
	printf("%d\n", aux->I); //imprime o I a ser removido
		
	if(o == 1)
		reinserir();
	
	prev->prox = aux->prox; //prev->prox deixa de apontar para aux e passa a pontar para aux->prox
	l = aux->prox; //aux->prox é o novo "começo" da lista para a proxima iteração de josephus();
	remov = aux; //o último a ser removido foi o aux

	if(N > 0)
		josephus(N-1);

	return;
}
