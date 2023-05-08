//TAD: �rvore bin�ria de busca balanceada (AVL)

// Estruturas e tipos empregados -------------------------
typedef int tipo_chave; //tipo chave dos n�s

typedef struct {
	tipo_chave chave;
	//... eventuais outros dados
} tipo_dado;


typedef struct node{
	tipo_dado dado;
	int fb; //fator de balanceamento do n�
	node *esq, *dir;
} no;
// -------------------------------------------------------

// Opera��es ---------------------------------------------
void inserir(no *raiz, no x);
void remover(no *raiz, no x);
int calcularFator(no *raiz);
void rebalancear(no *raiz);
// -------------------------------------------------------

