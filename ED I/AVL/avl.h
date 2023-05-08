//TAD: árvore binária de busca balanceada (AVL)

// Estruturas e tipos empregados -------------------------
typedef int tipo_chave; //tipo chave dos nós

typedef struct {
	tipo_chave chave;
	//... eventuais outros dados
} tipo_dado;


typedef struct node{
	tipo_dado dado;
	int fb; //fator de balanceamento do nó
	node *esq, *dir;
} no;
// -------------------------------------------------------

// Operações ---------------------------------------------
void inserir(no *raiz, no x);
void remover(no *raiz, no x);
int calcularFator(no *raiz);
void rebalancear(no *raiz);
// -------------------------------------------------------

