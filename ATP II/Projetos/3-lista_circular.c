#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int I, K, O;
    struct lista *prox; //endereço do próximo elemento
}Lista;

Lista *l = NULL; //endereço do elemento "inicial" da lista
Lista *remov = NULL; //endereço da última pessoa removida

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
	
	printf("\n\tReinserindo\n");
	
	if(remov == NULL) //se não há valor para reinserir
		return;
	
	remov->O = 0;
	
	//"anda" enquanto remov for maior do que a posição atual e maior do que a próxima posição, e ainda não tivermos dado uma volta completa
	//ou enquanto remov for menor do que a posição atual e do que a próxima posição
	while((remov->I > aux->I && remov->I > aux->prox->I && aux->prox != l) || (remov->I < aux->I && remov->I < aux->prox->I))
	{
		prev = aux;
		aux = aux->prox;
	}
	
	//se chegamos ao "fim" da lista (volta completa)
	if(aux->prox == l)
	{
		aux->prox = remov;
		remov->prox = l;
		
		remov = NULL;
		return;
	}
	
	//se estamos em um ponto qualquer da lista, em que remov é maior do que a posição autual mas menor do que a próxima
	prev->prox = remov;
	remov->prox = aux;
	
	remov = NULL; //descarta o valor reinserido
	return;
}

void josephus(int N){
	Lista *aux = l, *prev;
	int k, o;
	
	k = l->K - 1; //salva o K da posição atual, e remove 1 para contar a própria posição
	o = l->O; //salva o O da posição atual
	
	if(o == 1)
		reinserir();
	
	/*
	Por algum motivo, ele só entende que O é 1 nos casos em que os K são diferentes; do contrário, ele nunca entra em reinserir()
	Deve ter alguma coisa a ver com o jeito que está andando na lista e computando os K?
	*/

	//anda até encontrar a posição a ser eliminada (isso funciona se todos os k são iguais, mas não se são diferentes)
	while(k > 0)
	{
		prev = aux;
		aux = aux->prox;
		k--;
	}
	
	prev->prox = aux->prox; //pula aux na lista
	remov = aux; //salva o elemento removido
	
	l = aux->prox; //a próxima iteração de josephus começaria pelo próximo elemento da lista
	
	if(N > 1) //se ainda há mais de uma pessoa
		josephus(N-1); //chama josephus para uma pessoa a menos

	return;
}
