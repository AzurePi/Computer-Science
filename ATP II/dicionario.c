#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct lista{
	char palavra[50];
	struct lista *prox;
}Lista;

Lista *h = NULL;

void inserir();

void remover();

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

void inserir(){
	Lista *new, *aux = h, *prev = NULL;
	new = malloc(sizeof(Lista));
	
	scanf(" %s", new->palavra);
	
	if(h == NULL)
	{
		h = new;
		h->prox = NULL;
		return;
	}
	
	while(strcmp(aux->palavra, new->palavra) < 0 && aux->prox != NULL && strcmp((aux->prox)->palavra, new->palavra) > 0)
	{
		prev = aux;
		aux = aux->prox;
	}
	
	if(aux->prox == NULL)
	{
		aux->prox = new;
		new->prox = NULL;
		return;
	}
	
	if(strcmp(aux->palavra, new->palavra) > 0 && strcmp((aux->prox)->palavra, new->palavra) < 0)
	{
		prev->prox = new;
		new->prox = aux;
		return;
	}
	
	return;
}

void remover(){


	return;
}
