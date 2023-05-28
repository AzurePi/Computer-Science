#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define tam_fila 100  //tamanho max. fila
#define N 5       //Tamanho da matriz de conex�es e vetor de dist�ncias

//ED para fila ---------------------------------------------

//Tipo fila
typedef struct{
	int A[tam_fila];    //Simplifica��o p/ aplica��o
	int inicio, fim;
} fila;
//----------------------------------------------------------

//Opera��es da fila ----------------------------------------

//Cria uma fila vazia
void Definir(fila *q) {
	q->fim = 0;
	q->inicio = 0;
	//Obs: ponteiro de in�cio atrasado: aponta para uma posi��o anterior ao in�cio
}

//Retorna true se fila n�o cont�m elementos, false caso contr�rio
bool Vazia(fila *q) {
	if (q->inicio == q->fim)
		return true;
	return false;
}

//Retorna true se fila cheia, false caso contr�rio
bool Cheia(fila *q) {
	if (q->inicio == ((q->fim + 1) % tam_fila))
		return true;
	return false;
	//Obs: os dois ponteiros diferem de uma posi��o
}

//Adiciona um elemento no fim da fila q (retorna true se sucesso, false c.c.) 
//Note que uma posi��o da fila nunca ser� preenchida
bool Inserir(fila *q, int elem) {	
	if (Cheia(q))
		return false;
	q->fim = (q->fim + 1) % tam_fila;
	q->A[q->fim] = elem;
	return true;
}

//Remove um elemento do in�cio da fila q (retorna true se sucesso, false c.c.)
bool Remover(fila *q, int *elem) {
	if (Vazia(q))
		return false;
	q->inicio = (q->inicio + 1) % tam_fila;
	*elem = q->A[q->inicio];
	return true;
}
//----------------------------------------------------------

//ED para um grafo representado por matriz de adjac�ncia ---
struct no {
	int id;
	int val;
	struct no *prox; //o endere�o do pr�ximo n� na coluna da matriz
	struct no *adj; //uma array que guarda as rela��es de adjac�ncia desse n� (uma linha da matriz)
};

typedef struct no *No;

struct grafo {
	int nNo;     //n�mero de n�s
	No vertices; //array de v�rtices
};

typedef struct grafo *Grafo;

//Implementa��o das fun��es/opera��es de grafo -------------

//Cria um n� do grafo
No criaNo (int id, int val) {
	No n = (No) malloc(sizeof(struct no));
	n->id = id;
	n->adj = NULL;
	n->val = val;
	return n;
}

//Adiciona um n� no grafo
void addNo (Grafo G, int id, int val) {
	No novo = criaNo(id, val);
	if(G == NULL)
		return;

	//Encontra a �tima posi��o na lista de n�s
	while(G->vertices- != NULL)
		n = n->prox;

	n->prox = novo;
}

//Imprime a lista de todos os n�s adjacentes ao n� corrente n
void imprimeNo(No n){
	while(n != NULL){
		printf("-> (%d, val: %d)", n->id, n->val);
		n = n->prox;
	}
}

//Define um grafo vazio
Grafo criaGrafo(){
	Grafo G = (Grafo) malloc(sizeof(struct grafo));
	G->vertices = NULL;
	G->nNo = 0;
	return G;
}


//----------------------------------------------------------
//Main: implementa��o do algoritmo de Dijkstra
//vetor 'dist': dist[i] � a dist�ncia da cidade fixada 'c' at� cada cidade 'i'
int main() {
	Grafo G = criaGrafo();
	int *dist; //array declarada dinamicamente para armazenar as dist�ncias
	int i, j, c;
	fila F;
	
	//l� o grafo a partir de um arquivo
	
	
	//inicia todas as dist�ncias como m�ximas, "infinitas"
	for (j=0; j<N; j++)  
		dist[j] = INT_MAX;
	
	do{
		printf("N� do qual partir: ");		
		scanf("%d", &c);
	}while(!noGrafo(G, c));

    
	dist[c] = 0; //dist�ncia de c at� si mesmo
	Definir(&F); 	//Cria fila
	Inserir(&F, c);  //Insere como primeiro elemento a cidade fixada c

	//Roda at� que todos os n�s tenham sido checados pelo crit�rio abaixo: 
	//tira da fila uma cidade i, e coloca na fila as cidades vizinhas j com dist�ncias computadas
	while (!Vazia(&F)) {
		Remover(&F, &i);  //Remove da fila (i � o elemento corrente a partir daqui)
		for (j=0; j<N; j++)
			//Se i tem conex�o com j E j ainda n�o foi checado
			if (A[i][j] > 0 && dist[j] == INT_MAX){
				dist[j] = dist[i] + A[i][j];
				Inserir(&F, j);
			}
	}
	
	//Imprime vetor de dist�ncias de 'c' para as demais cidades 'i'
	for (i=0; i<N; i++)
		printf("dist[%d]: %d\n", i, dist[i]);	
	
	return 0;
}

void lerGrafo(Grafo G, const char *filename){
	FILE *fp;
	int bsize = 20;
	int i, o, d, val_peso;
	char buffer[bsize];

	fp = fopen(filename, "r");

	//primeira linha do arquivo indica n�mero de n�s
	fgets(buffer, bsize, fp);
	sscanf(buffer, "%d", &G->n);
	G->vertices = malloc(G->n * sizeof(int));
	
	for(i=0; i < G->n; i++)
		G->vertices[i] = malloc(G->n * sizeof(int));
	

	for(i=0; i < G->nNo; i++){
		(G->vertices + i)->id = i;
		(G->vertices + i)->val = -1;
		(G->vertices + i)->prox = NULL;
	}

	//percorre o arquivo
	while(!feof(fp)){
		fgets(buffer, bsize, fp);
		sscanf(buffer, "%d %d %d", &o, &d, &val_peso);
		printf("%d %d %d\n", o, d, val_peso);
		addNo((G->vertices + o), d, val_peso);
	}

	fclose(fp);
	return;
}
