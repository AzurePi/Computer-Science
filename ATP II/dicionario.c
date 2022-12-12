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
	while(strcmp(novo->palavra, aux->palavra) < 0 && aux->prox != NULL)
	{
		prev = aux;
		aux = aux->prox;
	}
	
	//se a palavra já está na lista
	if(strcmp(novo->palavra, aux->palavra) == 0) 
		return;
	
	//novo a esquerda de aux
	if(strcmp(novo->palavra, aux->palavra) < 0) 
	{
		if(aux == h) //se estamos no começo da lista
		{
			novo->prox = h;
			h = novo;
			return;
		}
		if(aux->prox == NULL) //se estamos no final da lista
		{
			prev->prox = novo;
			novo->prox = aux;
			return;
		}
		//se estamos no meio da lista
		prev->prox = novo;
		novo->prox = aux;
		return;
	}
	
	//novo à direita de aux
	if(strcmp(novo->palavra, aux->palavra) > 0) 
	{
		if(aux == h) //se estamos no começo da lista
		{
			novo->prox = h->prox;
			h->prox = novo;
			return;
		}
		if(aux->prox == NULL) //se estamos no final da lista
		{
			novo->prox = NULL;
			aux->prox = novo;
			return;
		}
		//se estamos no meio da lista
		
		prev->prox = novo;
		novo->prox = aux;
		return;
	}
	return;
}

//remove a palavra lida
void remover(){
	Lista *aux = h, *prev = NULL;
	char pal[50];
	
	if(h == NULL) //se a lista está vazia
	{
		printf("NULL\n");
		return;
	}
	//do contrário
	scanf(" %s", pal);
	
	//procura a palavra na lista
	while(strcmp(aux->palavra, pal) != 0 && aux->prox != NULL)
	{
		prev = aux;
		aux = aux->prox;
	}

	if(strcmp(aux->palavra, pal) == 0) //se achou a palavra
	{
		if(aux == h) //se estamos no começo da lista
		{
			if(aux->prox == NULL) //e no fim da lista
				h = NULL; //a lista agora está vazia
			else //mas há elementos depois
				h = aux->prox;
		}else //se não está no começo
		{
			if(aux->prox == NULL) //e está no final
				prev->prox = NULL;
			else //estamos no meio da lista
				prev->prox = aux->prox;
		}		
	}

	if(h != NULL) //se a lista não está vazia
	{
		aux = h; //volta ao começo
		do //imprime as palavras
		{
			printf("%s ", aux->palavra);
			aux = aux->prox;
		}while(aux != NULL);
		printf("\n");
	}else //se h == NULL
		printf("NULL\n");	

	return;
}
