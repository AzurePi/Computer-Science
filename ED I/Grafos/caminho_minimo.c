#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

#define tam_fila 100  //tamanho m�ximo estimado para a fila

//ED para fila ---------------------------------------------------------------

//Tipo fila
typedef struct{
	int A[tam_fila];    //Simplifica��o para aplica��o
	int inicio, fim;
} fila;
//----------------------------------------------------------------------------

//Opera��es da fila ----------------------------------------------------------

//Cria uma fila vazia
void Definir(fila *q) {
	q->fim = 0;
	q->inicio = 0;
}

//Retorna true se fila n�o cont�m elementos, false caso contr�rio
bool Vazia(fila *q) {
	if (q->inicio == q->fim)
		return true;
	return false;
}

//Retorna true se fila est� cheia, false caso contr�rio
bool Cheia(fila *q) {
	if (q->inicio == ((q->fim + 1) % tam_fila))
		return true;
	return false;
	//Obs: os dois ponteiros diferem de uma posi��o
}

//Adiciona um elemento no fim da fila q (retorna true se sucesso, false caso contr�rio) 
//Note que uma posi��o da fila nunca ser� preenchida
bool Inserir(fila *q, int elem) {	
	if (Cheia(q))
		return false;
	q->fim = (q->fim + 1) % tam_fila;
	q->A[q->fim] = elem;
	return true;
}

//Remove um elemento do in�cio da fila q (retorna true se sucesso, false caso contr�rio)
bool Remover(fila *q, int *elem) {
	if (Vazia(q))
		return false;
	q->inicio = (q->inicio + 1) % tam_fila;
	*elem = q->A[q->inicio];
	return true;
}
//----------------------------------------------------------------------------

//ED para um grafo representado por matriz de adjac�ncia ---------------------
struct no {
	int id;
//	struct no *prox; //endere�o do pr�ximo n� na lista (us�vamos em lista de adjac�ncia)
};

typedef struct no *No;

struct grafo {
	int nNo; //n�mero de n�s
//	No vertices; //lista de v�rtices (implementa��o de lista de adjac�ncia)
	int **adjacencias; //matriz de adjac�ncias
};

typedef struct grafo *Grafo;

//Implementa��o das fun��es/opera��es de grafo -------------------------------
//Define um grafo vazio
Grafo criaGrafo(){
	Grafo G = (Grafo) malloc(sizeof(struct grafo));
	//G->vertices = NULL;	(implementa��o de lista de adjac�ncia)
	G->nNo = 0;
	G->adjacencias = NULL;
	return G;
}

//Desaloca aquilo que foi alocado dinamicamente no grafo
void desalocaGrafo(Grafo g){
	int i;
	for(i = 0; i < g->nNo; i++)
		free(g->adjacencias[i]);
	free(g->adjacencias);
}

//Efetuar a leitura do grafo via arquivo
void readGraph(Grafo G, const char *filename){
	FILE *fp;
	int bsize = 20;
	char buffer[bsize];
	int i, j; //contadores
	int num; //n�mero de n�s
	int o, d, val_peso; //informa��es dos v�rtices

	fp = fopen(filename, "r"); //abre o arquivo para leitura

	//primeira linha do arquivo indica n�mero de n�s
	fgets(buffer, bsize, fp);
	sscanf(buffer, "%d", &num);
	G->nNo = num;
	
	//alocando e zerando a matriz de adjac�ncias
	G->adjacencias = (int**)calloc(num, sizeof(int*));
	for(i=0; i<num; i++)
		G->adjacencias[i] = (int*)calloc(num, sizeof(int));
	
	/*	implementa��o de lista de adjac�ncias
	//inicializando os n�s
	for(i=0; i < num; i++){
		(G->vertices + i)->id = i;
		(G->vertices + i)->prox = NULL;
	}
	*/

	//percorre o arquivo lendo informa��es dos v�rtices
	while(!feof(fp)){
		fgets(buffer, bsize, fp);
		sscanf(buffer, "%d %d %d", &o, &d, &val_peso);
		//printf("%d %d %d\n", o, d, val_peso);		(implementa��o de lista de adjac�ncia)
		//addNo(G, (G->vertices + o), d, val_peso);	(implementa��o de lista de adjac�ncia)
		G->adjacencias[o][d] = val_peso;
	}

	fclose(fp);
	return;
}

//Imprime o grafo como uma matriz de adjac�ncia
void printGraph(Grafo G) {
	int i, j;
	printf("\nGrafo - Matriz de Adjac�ncia\n\n");
	for(i = 0; i < G->nNo; i++){
		for(j = 0; i < G->nNo; j++){
			printf("%d ", G->adjacencias[i][j]);	
		}
		printf("\n");
	}
}


//----------------------------------------------------------------------------
//Main: implementa��o do algoritmo de Dijkstra
//vetor 'dist': dist[i] � a dist�ncia da cidade fixada 'c' at� cada cidade 'i'
int main() {
	Grafo G = criaGrafo();
	int *dist; //array declarada dinamicamente para armazenar as dist�ncias
	int i, j; //contadores
	int c; //n� a partir do qual as dist�ncias s�o calculadas
	fila F;
	
	setlocale(LC_ALL, "PORTUGUESE");
	
	readGraph(G, "digrafo.txt");
	
	//inicia todas as dist�ncias como m�ximas, "infinitas"
	dist = malloc(G->nNo * sizeof(int));
	for (i=0; i<G->nNo; i++)  
		dist[i] = INT_MAX;
	
	//recebe do usu�rio a partir de qual n� calcular as dist�ncias
	do{
		printf("N� do qual partir (h� %d n�s no grafo): ", G->nNo);		
		scanf("%d", &c);
		
		if(c > G->nNo || c < 0) //se o n� informado n�o est� dentro da quantidade de n�s no grafo
			printf("N� n�o encontrado. Tente novamente\n\n");
	}while(c > G->nNo || c < 0);

    
	dist[c] = 0; //dist�ncia de c at� si mesmo
	Definir(&F); 	//Cria fila
	Inserir(&F, c);  //Insere como primeiro elemento a cidade fixada c

	//Roda at� que todos os n�s tenham sido checados pelo crit�rio abaixo: 
	//tira da fila uma cidade i, e coloca na fila as cidades vizinhas j com dist�ncias computadas
	while (!Vazia(&F)) {
		Remover(&F, &i);  //Remove da fila (i � o elemento corrente a partir daqui)
		for (j=0; j<G->nNo; j++){
			//Se i tem conex�o com j e j ainda n�o foi checado
			if (G->adjacencias[i][j] != 0 && dist[j] == INT_MAX){
				dist[j] = dist[i] + G->adjacencias[i][j];
				Inserir(&F, j);
			}
		}		
	}
	
	//Imprime vetor de dist�ncias de 'c' para as demais cidades 'i'
	for (i=0; i<G->nNo; i++)
		printf("dist[%d]: %d\n", i, dist[i]);	
	
	desalocaGrafo(G);
	
	return 0;
}
