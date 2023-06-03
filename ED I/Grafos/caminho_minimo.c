#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define tam_fila 100  //tamanho max. fila
#define N 5       //Tamanho da matriz de conexões e vetor de distâncias

//ED para fila -------------------------------------------------

//Tipo fila
typedef struct{
	int A[tam_fila];    //Simplificação p/ aplicação
	int inicio, fim;
} fila;
//--------------------------------------------------------------

//Operações da fila --------------------------------------------

//Cria uma fila vazia
void Definir(fila *q) {
	q->fim = 0;
	q->inicio = 0;
	//Obs: ponteiro de início atrasado: aponta para uma posição anterior ao início
}

//Retorna true se fila não contém elementos, false caso contrário
bool Vazia(fila *q) {
	if (q->inicio == q->fim)
		return true;
	return false;
}

//Retorna true se fila cheia, false caso contrário
bool Cheia(fila *q) {
	if (q->inicio == ((q->fim + 1) % tam_fila))
		return true;
	return false;
	//Obs: os dois ponteiros diferem de uma posição
}

//Adiciona um elemento no fim da fila q (retorna true se sucesso, false c.c.) 
//Note que uma posição da fila nunca será preenchida
bool Inserir(fila *q, int elem) {	
	if (Cheia(q))
		return false;
	q->fim = (q->fim + 1) % tam_fila;
	q->A[q->fim] = elem;
	return true;
}

//Remove um elemento do início da fila q (retorna true se sucesso, false c.c.)
bool Remover(fila *q, int *elem) {
	if (Vazia(q))
		return false;
	q->inicio = (q->inicio + 1) % tam_fila;
	*elem = q->A[q->inicio];
	return true;
}
//--------------------------------------------------------------

//ED para um grafo representado por matriz de adjacência -------
struct no {
	int id;
	
	struct no *prox; //endereço do próximo No na lista
};

typedef struct no *No;

struct grafo {
	int nNo;     //número de nós
	No vertices; //lista de vértices
	int **adjacencias; //matriz de adjacências
};

typedef struct grafo *Grafo;

//Implementação das funções/operações de grafo -----------------
//Cria um nó do grafo
No criaNo (int id) {
	No n = (No) malloc(sizeof(struct no));
	n->id = id;
	n->prox = NULL;
	return n;
}

//Adiciona uma conexão a um No n de um nó id com peso val
void addNo (Grafo g, No n, int id, int val) {
	No novo = criaNo(id);
	if(n == NULL || g == NULL)
		return;

	//Encontra a útima posição na lista de adjacências do nó n
	while(n->prox != NULL)
		n = n->prox;
	
	n->prox = novo;
	g->adjacencias[n->id][id] = val;
}

//Imprime a lista de todos os nós adjacentes ao nó corrente n
void imprimeNo(No n){
	while(n != NULL){
		printf("-> (%d, val: %d)", n->id);
		n = n->prox;
	}
}

//Define um grafo vazio
Grafo criaGrafo(){
	Grafo G = (Grafo) malloc(sizeof(struct grafo));
	G->vertices = NULL;
	G->nNo = 0;
	G->adjacencias = NULL;
	return G;
}

//Efetuar a leitura do grafo via arquivo
void readGraph(Grafo G, const char *filename){
	FILE *fp;
	int bsize = 20;
	int i, j; //contadores
	int o, d, val_peso;
	char buffer[bsize];

	fp = fopen(filename, "r");

	//primeira linha do arquivo indica número de nós
	fgets(buffer, bsize, fp);
	sscanf(buffer, "%d", &G->nNo);
	G->vertices = (No) malloc(G->nNo * sizeof(struct no));
	
	//alocando e zerando a matriz de adjacências
	G->adjacencias = malloc(G->nNo * sizeof(int*));
	for(i=0; i<G->nNo; i++)
		G->adjacencias[i] = malloc(G->nNo * sizeof(int));
	
	for(i=0; i<G->nNo; i++)
		for(j=0; j<G->nNo; j++)
			G->adjacencias[i][j] = 0;
	
	
	//inicializando os nós
	for(i=0; i < G->nNo; i++){
		(G->vertices + i)->id = i;
		(G->vertices + i)->prox = NULL;
	}

	//percorre o arquivo
	while(!feof(fp)){
		fgets(buffer, bsize, fp);
		sscanf(buffer, "%d %d %d", &o, &d, &val_peso);
		printf("%d %d %d\n", o, d, val_peso);
		addNo(G, (G->vertices + o), d, val_peso);
	}

	fclose(fp);
	return;
}

//Imprime o grafo a partir das listas de adjacência
void printGraph(Grafo G) {
	int i;
	printf("\nGrafo - Lista de Adjacencia\n\n");
	for(i = 0; i < G->nNo; i++){
		printf("(%d)", (G->vertices + i)->id);
		imprimeNo((G->vertices + i));
		printf("\n");	
	}
}

//busca um No com id no Grafo g
int noGrafo(Grafo g, int id){
	No aux = g->vertices; //começamos pelo primeiro No no Grafo
	
	//procuramos pelo Np que queremos
	while(aux->id != id && aux->prox != NULL)
		aux = aux->prox;
	
	if(aux->id == id) //se encontramos id no Grafo
		return 1;
	//se não encontramos id no grafo
	return 0;
}


//--------------------------------------------------------------
//Main: implementação do algoritmo de Dijkstra
//vetor 'dist': dist[i] é a distância da cidade fixada 'c' até cada cidade 'i'
int main() {
	Grafo G = criaGrafo();
	int *dist; //array declarada dinamicamente para armazenar as distâncias
	int i, j, c;
	fila F;
	
	//lê o grafo a partir de um arquivo
	readGraph(G, "digrafo.txt");
	
	//inicia todas as distâncias como máximas, "infinitas"
	dist = malloc(G->nNo * sizeof(int));
	for (i=0; i<N; i++)  
		dist[i] = INT_MAX;
	
	do{
		printf("Nó do qual partir: ");		
		scanf("%d", &c);
	}while(!noGrafo(G, c));

    
	dist[c] = 0; //distância de c até si mesmo
	Definir(&F); 	//Cria fila
	Inserir(&F, c);  //Insere como primeiro elemento a cidade fixada c

	//Roda até que todos os nós tenham sido checados pelo critério abaixo: 
	//tira da fila uma cidade i, e coloca na fila as cidades vizinhas j com distâncias computadas
	while (!Vazia(&F)) {
		Remover(&F, &i);  //Remove da fila (i é o elemento corrente a partir daqui)
		for (j=0; j<N; j++){
			//Se i tem conexão com j E j ainda não foi checado
			if (G->adjacencias[i][j] > 0 && dist[j] == INT_MAX){
				dist[j] = dist[i] + G->adjacencias[i][j];
				Inserir(&F, j);
			}
		}		
	}
	
	//Imprime vetor de distâncias de 'c' para as demais cidades 'i'
	for (i=0; i<N; i++)
		printf("dist[%d]: %d\n", i, dist[i]);	
	
	return 0;
}
