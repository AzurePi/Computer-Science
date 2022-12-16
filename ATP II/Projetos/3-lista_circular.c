#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int I, K, O;
    struct lista *prox; //endereço do próximo elemento
}Lista;

Lista *l = NULL; //endereço do elemento "inicial" da lista
Lista *remov; //id da última pessoa removida

int ler();
void reinserir();
void josephus();

int main(){
    int N = ler(); //realiza a leitura das entradas e preenche a lista, cujo endereço é global
 
	josephus(N);

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

        scanf("%d %d", &new->K, &new->O);

        if(i == 1) //começo da lista
        {
        	l = new; //é o que acabou de ser lido
        	l->K--; //para contar o próprio primeiro elemento
		}
        if(i == N) //último elemento
            new->prox = l; //aponta para o primeiro
        if(prev != NULL) //para os demais elementos
            prev->prox = new; //o elemento anterior passa a apontar para esse elemento
        
        prev = new;
    }

    return N;
}

void reinserir(){
	Lista *aux = l, *prev = NULL;
	
	remov->O = 0;
	
	while(aux->I < remov->I && aux->prox != l)
	{
		prev = aux;
		aux = aux->prox;
	}
	
	//se chegamos ao "fim" da lista
	if(aux->prox == l)
	{
		aux->prox = remov;
		remov->prox = l;
		return;
	}
	
	//se estamos em um ponto qualquer da lista
	prev->prox = remov;
	remov->prox = aux;
	
	return;
}

void josephus(int N){
	Lista *aux = l, *prev = NULL;
	int k = l->K, o = l->O;
	int i;
	
	//anda até encontrar a pessoa a ser eliminada
	while(k > 0)
	{
		printf("%d -> ", aux->I); //imprime o "caminho"
		prev = aux;
		aux = aux->prox;
		
		k--;
	}
	
	printf("%d\n", aux->I); //imprime o I a ser removido
		
	if(o == 1)
	{
		printf("Reinserindo\n");
		reinserir();
	}
	
	prev->prox = aux->prox; //pula aux na lista
	
	l = aux->prox; //a próxima iteração de josephus começa pelo próximo elemento da lista
	remov = aux; //salva o elemento removido

	printf("\n");
	
	if(N > 1) //se ainda há mais de uma pessoa
		josephus(N-1); //chama josephus para uma pessoa a menos

	return;
}
