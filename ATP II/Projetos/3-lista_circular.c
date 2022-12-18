#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
	int I, K, O;
	struct lista *prox;
} Lista;

Lista *l = NULL; //endereço do elemento "inicial" da lista, o de menor I
Lista *remov = NULL; //endereço da última pessoa removida

int ler(); //leitura das entradas e preenchimento da lista circular
void reinserir(); //eventual reinserção do último elemento removido
void josephus(int N, int K, Lista *start); //execução da lógica do problema

int main() {
	l = malloc(sizeof(Lista));
	int N = ler();
	
	josephus(N, l->K - 1, l); //já considerando o primeiro movimento para se "entrar" na lista
	printf("%d\n", l->I);

	return 0;
}

//leitura das entradas e preenchimento da lista circular
int ler() {
	int N, i;
	Lista *new, *prev = NULL;
	
	scanf("%d", &N);
	for(i = 1; i < N+1; i++) //preenchimento da lista circular
	{
		new = malloc(sizeof(Lista)); //a cada iteração, new aponta para um endereço novo
		new->I = i;	
		scanf("%d %d", &new->K, &new->O);
		
		if(i == 1) //se estamos no começo da lista
			l = new; //esté é o endereço da menor posição
		else if(i == N) //se estamos no final da lista
			new->prox = l; //ele aponta para o primeiro elemento
		else //para os demais elementos
			prev->prox = new; //o elemento anterior passa a apontar para esse elemento
		
		prev = new;
		free(new); //libera new para a próxima iteração
	}
	
	return N;
}

//reinserção do último elemento removido
void reinserir() {
	Lista *aux = l, *prev = NULL;
	int i = 0;
	
	if(remov == NULL) //se não há valor para reinserir
		return;
	
	remov->O = 0;
	
	/*condições de parada: 	aux->prox é l (já analisamos todas as posições)
							remov é maior que o número atual e menor do que o próximo número (encontramos o lugar certo)
	*/
	while(aux->prox != l && (remov->I < aux->I || remov->I > (aux->prox)->I))
	{
		prev = aux;
		aux = aux->prox;
		i++;
	}
	
	if(remov->I > aux->I && remov->I < (aux->prox)->I) //se encontramos o lugar certo
	{
		remov->prox = aux->prox;
		aux->prox = remov;
	
		remov = NULL; // descarta o valor reinserido
		return;
	}
	
	/*se demos uma volta completa no vetor, estamos na posição imediatamente
	  anterior a l e sabemos que remov não estava entre nenhum par de posições até
	  agora; portanto, remov deve ser ou maior ou menor do que todos os valores
	  ainda presentes na lista
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
	
	return;
}

//execução da lógica do problema
void josephus(int N, int K, Lista *start) {
	Lista *aux = start, *prev = NULL;
	
	//anda até encontrar a posição a ser eliminada
	while(K > 0)
	{
		prev = aux;
		aux = aux->prox;
		K--;
	}

	if(aux->O == 1) //verifica a operação que a posição a ser eliminada requer
		reinserir();
	
	if(aux == l) //se estamos removendo o menor número da lista
		l = aux->prox; //guardamos o próximo menor número
		
	prev->prox = aux->prox; //remove aux da lista
	remov = aux; //salva o elemento removido para eventual reinserção

	if(N > 1) //se ainda há mais de uma pessoa
		josephus(N-1, aux->K - 1, aux->prox);
		/*executa para uma pessoa a menos, com o K do elemento que acabou de ser eliminado (já considerando o movimento preciso
		  para passar para a próxima posição), começando pelo próximo elemento
		*/
		
	return;
}
