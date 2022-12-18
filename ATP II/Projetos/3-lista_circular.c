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
void josephus(int N, int K);

int main(){
	int N = ler(); //realiza a leitura das entradas e preenche a lista, cujo endereço é global

	josephus(N, l->K);
	printf("%d", l->I);

   	return 0;
}

int ler(){
    	int N, i;
    	Lista *new, *prev = malloc(sizeof(Lista));
  
    	scanf("%d", &N);
	for(i = 1; i<N+1; i++) //preenchimento da lista circular
	{
		new = malloc(sizeof(Lista)); //a cada iteração, new aponta para um endereço novo
		new->I = i;

		scanf("%d %d", &new->K, &new->O);

		if(i == 1) //começo da lista
			l = new; //é o que acabou de ser lido
		else if(i == N) //último elemento
			new->prox = l; //aponta para o primeiro
		else //para os demais elementos
		    prev->prox = new; //o elemento anterior passa a apontar para esse elemento

		prev = new;
		free(new);
	}
	return N;
}

void reinserir(){
	Lista *aux = l, *prev = NULL;
	int i = 0;
	
	if(remov == NULL) //se não há valor para reinserir
		return;
	
	remov->O = 0;
	
	/*condições de parada: 	aux->prox é l (já analisamos todas as posições)
				remov é maior que o número atual e menor do que o próximo número (encontramos o lugar certo)
	*/
	while(!(aux->prox == l || (remov->I > aux->I && remov->I < (aux->prox)->I)))
	{
		prev = aux;
		aux = aux->prox;
		i++;
	}
	
	if(remov->I > aux->I && remov->I < (aux->prox)->I) //se encontramos o lugar certo
	{
		remov->prox = aux->prox;
		aux->prox = remov;
		
		remov = NULL; //descarta o valor reinserido
		return;
	}
	
	/*se demos uma volta completa no vetor, estamos na posição imediatamente anterior a l
	  e sabemos que remov não estava entre nenhum par de posições até agora;
	  portanto, remov deve ser ou maior ou menor do que todos os valores ainda presentes na lista
	*/
	if(remov->I > aux->I) //se remov é maior do que a posição atual, então é maior do que todos
	{
		remov->prox = aux->prox;
		aux->prox = remov;
			
		remov = NULL;
		return;
	}
	
	if(remov->I < aux->I) //se remov é menor do que a posição atual, então é menor do que todos
	{
		prev->prox = remov;
		remov->prox = aux;
	
		remov = NULL;
		return;
	}

	//se remov é igual a algum valor
	return;
}

void josephus(int N, int K){
	Lista *aux = l, *prev = NULL;
	int i = K, o;

	//anda até encontrar a posição a ser eliminada
	while(i > 0)
	{
		prev = aux;
		aux = aux->prox;
		i--;
	}
	
	o = aux->O;
	
	if(o == 1)
		reinserir();
	
	prev->prox = aux->prox; //remove aux da lista
	free(prev);
	
	remov = aux; //salva o elemento removido para eventual reinserção
	
	l = aux->prox; //a próxima iteração de josephus começaria pelo próximo elemento da lista
	if(N > 1) //se ainda há mais de uma pessoa
		josephus(N-1, aux->K); //chama josephus para uma pessoa a menos, com o K do elemento que acabou de ser eliminado

	free(aux);
	return;
}
