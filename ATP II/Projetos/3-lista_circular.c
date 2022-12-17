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
        	l = new; //é o que acabou de ser lido
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
	
	if(remov == NULL)
		return;
	
	remov->O = 0;
	
	//enquanto remov->I for maior do que a posição atual, ou até que aux->prox seja o começo da lista
	while(aux->I < remov->I || aux->prox != l)
	{
		prev = aux;
		aux = aux->prox;
	}
	
	//se chegamos ao "fim" da lista
	if(aux->prox == l)
	{
		aux->prox = remov;
		remov->prox = l;
		
		remov = NULL;
		return;
	}
	
	//se estamos em um ponto qualquer da lista
	prev->prox = remov;
	remov->prox = aux;
	
	remov = NULL;
	return;
}

void josephus(int N){
	Lista *aux = NULL, *prev;
	int k, o;
	
	//o = l->O  não funciona quando l->O é 1 por algum motivo; simplesmente fica o == 0
	
	k = l->K;
	o = l->O;
	
	if(o == 1)
		reinserir();

	//anda até encontrar a pessoa a ser eliminada (isso funciona se todos os k são iguais, mas não se são diferentes)
	while(k > 0)
	{
		if(aux == NULL)
			aux = l;
		else{
			prev = aux;
			aux = aux->prox;
		}
	
		k--;
	}
	
	prev->prox = aux->prox; //pula aux na lista
	remov = aux; //salva o elemento removido
	
	l = aux->prox; //a próxima iteração de josephus começaria pelo próximo elemento da lista
	
	if(N > 1) //se ainda há mais de uma pessoa
		josephus(N-1); //chama josephus para uma pessoa a menos

	return;
}
