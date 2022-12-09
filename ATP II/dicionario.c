#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct lista{
	char palavra[50];
	struct lista *prox;
}Lista;

Lista *h = NULL; //endereço do começo da lista

void inserir(); //insere a palavra lida em ordem alfabética
void remover(); //remove a palavra lida

int main(){
	int N, M;
	int i, op;
	
	scanf("%d %d", &N, &M);
	
	for (i = 0; i<N; i++)
		inserir();
	
	for(i = 0; i<M; i++)
	{
		scanf("%d", &op);
		
		if(op == 0)
			remover();
		else
			inserir();
	}

	return 0;
}

//insere a palavra lida em ordem alfabética
void inserir(){
	Lista *novo, *aux = h, *prev = NULL;
	
	novo = malloc(sizeof(Lista));
	
	scanf(" %s", novo->palavra);
	
	if(h == NULL) //se a lista está vazia
	{
		h = novo;
		h->prox = NULL;
		return;
	}
	
	//anda até encontrar o ponto onde a palavra deve estar, ou até o fim da lista
	while(strcmp(aux->palavra, novo->palavra) < 0 && aux->prox != NULL)
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
	if(strcmp(aux->palavra, novo->palavra) > 0)
	{
		prev->prox = novo; //a anterior aponta para a nova
		novo->prox = aux; //a nova aponta para a atual
		return;
	}
	
	return;
}

//remove a palavra lida
void remover(){
	Lista *aux = h, *prev = NULL;
	char pal[50];
	
	scanf(" %s", pal);
	
	if(h == NULL) //se a lista está vazia
	{
		printf("NULL\n");
		return;
	}
	
	//procura a palavra na lista
	while(strcmp(aux->palavra, pal) != 0 && aux->prox != NULL)
	{
		prev = aux;
		aux = aux->prox;
	}

	if(strcmp(aux->palavra, pal) == 0) //se achou a palavra
	{
		if(aux->prox != NULL) //se está não está no fim da lista
			prev->prox = aux->prox; //o item anterior aponta para o próximo, pulando o item aux
		else
			h = NULL;
	}

	if(h != NULL)
	{
		aux = h; //volta ao começo
		do
		{
			printf("%s ", aux->palavra);
			aux = aux->prox;
		}while(aux->prox != NULL);
		printf("\n");
	}else
	{
		printf("NULL\n");
	}

	return;
}
