#include <stdio.h>
#include <stdlib.h>

int momento = 0; //variável para a linha do tempo

typedef struct processo{
	int instante;
	int carga;
	struct processo *prox;
}P;

P *h = NULL;

void inserir();
void processar();

int main(){
	int N;
	int i;
	
	scanf("%d", &N);
	
	for(i = 0; i<N; i++)
		inserir();
	
	processar();
	
	return 0;
}

void inserir(){
	P *novo, *aux = h, *prev = NULL;
	novo = malloc(sizeof(P));
	
	scanf("%d %d", novo->instante, novo->carga);
	
	if(h == NULL) //se a lista está vazia
	{
		h = novo;
		h->prox = NULL;
		return;
	}
	
	while(novo->instante < aux->instante && aux->prox != NULL)
	{
		prev = aux;
		aux = aux->prox;
	}
	
	//se chegou ao fim da lista
	if(aux->prox == NULL) 
	{
		novo->prox = NULL; //garante que o fim é o fim
		aux->prox = novo; //insere no fim da lista
		return;
	}
	
	//se ainda está no começo da lista
	if(aux == h)
	{
		novo->prox = h; //o novo tem como próximo o atual começo
		h = novo; //o começo passa a ser o novo
		return;
	}
	
	//se encontrou o lugar certo
	if(novo->instante > aux->instante)
	{
		prev->prox = novo; //a anterior aponta para a nova
		novo->prox = aux; //a nova aponta para a atual
		return;
	}
	
	return;
}

void processar(){
	P *cur, *aux = h, *prev = NULL;
	cur = malloc(sizeof(P));

	do{
		
		
	}while()
	
	
	
	
	return;
}
