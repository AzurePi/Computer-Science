#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int I, K, O;
    struct lista *prox; //endereço od próximo elemento
}Lista;

Lista *l; //endereço inicial da lista circular (I = 1)
Lista *remov; //endereço da última pessoa removida
Lista *prevremov; //endereço da pessoa anterior a última removida

int ler();
void reinserir();
void josephus();

int main(){
    int N = ler(); //realiza a leitura das entradas e preenche a lista, cujo endereço é global
 
	josephus(N);

    return 0;
}

int ler(){
    int N, i;
    Lista *new, *prev;

    scanf("%d", &N);

    //preenchimento da lista circular
    for(i = 1; i<N+1; i++)
    {
    	new = malloc(sizeof(Lista)); //a cada iteração, new aponta para um endereço novo
        new->I = i;
        scanf("%d %d", &new->K, &new->O);

        if(i == 1) //começo da lista
            l = new; //é o que acabou de ser lido
        else if(i == N) //último elemento
            new->prox = l; //aponta para o primeiro
        else //demais elementos
            prev->prox = new; //o elemento anterior passa a apontar para esse elemento
        
        prev = new;
    }
    
    free(new); free(prev);

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
	Lista *aux, *prev;
	int k, o;
	int i;
	
	aux = l; //o primeiro a ser lido é o começo da lista
	
	for(i = 0; i<N; i++)
	{
		k = aux->K;
		o = aux->O;
		
		//anda até encontrar a pessoa a ser eliminada
		while(k > 0)
		{
			if(k == 1) //se for a pessoa imediatamente anterior àquela que será removida
				prevremov = aux;
			
			prev = aux;
			aux = aux->prox;
			
			k--;
		}
		
		if(aux == l) //se a pessoa a ser removida for o começo da lista
			l = aux->prox;
			
		if(o == 1)
			reinserir();
		
		prev->prox = aux->prox;
		remov = aux; //o último a ser removido foi o aux
	}

	return;
}
