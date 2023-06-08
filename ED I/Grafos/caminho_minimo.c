#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

#define tam_fila 100  //tamanho máximo estimado para a fila

//ED para fila ---------------------------------------------------------------

//Tipo fila
typedef struct{
	int A[tam_fila];    //Simplificação para aplicação
	int inicio, fim;
} fila;
//----------------------------------------------------------------------------

//Operações da fila ----------------------------------------------------------

//Cria uma fila vazia
void Definir(fila *q) {
	q->fim = 0;
	q->inicio = 0;
}

//Retorna true se fila não contém elementos, false caso contrário
bool Vazia(fila *q) {
	if (q->inicio == q->fim)
		return true;
	return false;
}

//Retorna true se fila está cheia, false caso contrário
bool Cheia(fila *q) {
	if (q->inicio == ((q->fim + 1) % tam_fila))
		return true;
	return false;
	//Obs: os dois ponteiros diferem de uma posição
}

//Adiciona um elemento no fim da fila q (retorna true se sucesso, false caso contrário) 
//Note que uma posição da fila nunca será preenchida
bool Inserir(fila *q, int elem) {	
	if (Cheia(q))
		return false;
	q->fim = (q->fim + 1) % tam_fila;
	q->A[q->fim] = elem;
	return true;
}

//Remove um elemento do início da fila q (retorna true se sucesso, false caso contrário)
bool Remover(fila *q, int *elem) {
	if (Vazia(q))
		return false;
	q->inicio = (q->inicio + 1) % tam_fila;
	*elem = q->A[q->inicio];
	return true;
}
//----------------------------------------------------------------------------

//ED para um grafo representado por matriz de adjacência ---------------------
struct no {
	int id;
//	struct no *prox; //endereço do próximo nó na lista (usávamos em lista de adjacência)
};

typedef struct no *No;

struct grafo {
	int nNo; //número de nós
//	No vertices; //lista de vértices (implementação de lista de adjacência)
	int **adjacencias; //matriz de adjacências
};

typedef struct grafo *Grafo;

//Implementação das funções/operações de grafo -------------------------------
//Define um grafo vazio
Grafo criaGrafo(){
	Grafo G = (Grafo) malloc(sizeof(struct grafo));
	//G->vertices = NULL;	(implementação de lista de adjacência)
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
	int num; //número de nós
	int o, d, val_peso; //informações dos vértices

	fp = fopen(filename, "r"); //abre o arquivo para leitura

	//primeira linha do arquivo indica número de nós
	fgets(buffer, bsize, fp);
	sscanf(buffer, "%d", &num);
	G->nNo = num;
	
	//alocando e zerando a matriz de adjacências
	G->adjacencias = (int**)calloc(num, sizeof(int*));
	for(i=0; i<num; i++)
		G->adjacencias[i] = (int*)calloc(num, sizeof(int));
	
	/*	implementação de lista de adjacências
	//inicializando os nós
	for(i=0; i < num; i++){
		(G->vertices + i)->id = i;
		(G->vertices + i)->prox = NULL;
	}
	*/

	//percorre o arquivo lendo informações dos vértices
	while(!feof(fp)){
		fgets(buffer, bsize, fp);
		sscanf(buffer, "%d %d %d", &o, &d, &val_peso);
		//printf("%d %d %d\n", o, d, val_peso);		(implementação de lista de adjacência)
		//addNo(G, (G->vertices + o), d, val_peso);	(implementação de lista de adjacência)
		G->adjacencias[o][d] = val_peso;
	}

	fclose(fp);
	return;
}

//Imprime o grafo como uma matriz de adjacência
void printGraph(Grafo G) {
	int i, j;
	printf("\nGrafo - Matriz de Adjacência\n\n");
	for(i = 0; i < G->nNo; i++){
		for(j = 0; i < G->nNo; j++){
			printf("%d ", G->adjacencias[i][j]);	
		}
		printf("\n");
	}
}


//----------------------------------------------------------------------------
//Main: implementação do algoritmo de Dijkstra
//vetor 'dist': dist[i] é a distância da cidade fixada 'c' até cada cidade 'i'
int main() {
	Grafo G = criaGrafo();
	int *dist; //array declarada dinamicamente para armazenar as distâncias
	int i, j; //contadores
	int c; //nó a partir do qual as distâncias são calculadas
	fila F;
	
	setlocale(LC_ALL, "PORTUGUESE");
	
	readGraph(G, "digrafo.txt");
	
	//inicia todas as distâncias como máximas, "infinitas"
	dist = malloc(G->nNo * sizeof(int));
	for (i=0; i<G->nNo; i++)  
		dist[i] = INT_MAX;
	
	//recebe do usuário a partir de qual nó calcular as distâncias
	do{
		printf("Nó do qual partir (há %d nós no grafo): ", G->nNo);		
		scanf("%d", &c);
		
		if(c > G->nNo || c < 0) //se o nó informado não está dentro da quantidade de nós no grafo
			printf("Nó não encontrado. Tente novamente\n\n");
	}while(c > G->nNo || c < 0);

    
	dist[c] = 0; //distância de c até si mesmo
	Definir(&F); 	//Cria fila
	Inserir(&F, c);  //Insere como primeiro elemento a cidade fixada c

	//Roda até que todos os nós tenham sido checados pelo critério abaixo: 
	//tira da fila uma cidade i, e coloca na fila as cidades vizinhas j com distâncias computadas
	while (!Vazia(&F)) {
		Remover(&F, &i);  //Remove da fila (i é o elemento corrente a partir daqui)
		for (j=0; j<G->nNo; j++){
			//Se i tem conexão com j e j ainda não foi checado
			if (G->adjacencias[i][j] != 0 && dist[j] == INT_MAX){
				dist[j] = dist[i] + G->adjacencias[i][j];
				Inserir(&F, j);
			}
		}		
	}
	
	//Imprime vetor de distâncias de 'c' para as demais cidades 'i'
	for (i=0; i<G->nNo; i++)
		printf("dist[%d]: %d\n", i, dist[i]);	
	
	desalocaGrafo(G);
	
	return 0;
}
