// Implementação: árvore binária de busca balanceada (AVL)
#include "avl.h"
#include <stdio.h>
#include <stdlib.h>


// Operações ---------------------------------------------

// Aloca um No com valor x na memória e retorna seu endereço
No *novoNo(int x) {
	No *novo = malloc(sizeof(No));
	novo->valor = x;
	novo->esq = NULL;
	novo->dir = NULL;
	novo->altura = 0; // todo nó é inserido como folha, e toda folha tem altura 0
	return novo;
}

// Retorna a altura do No no endereço raiz
// Retorna -1 se raiz é NULL
int alturaNo(No *raiz) {
	if (raiz == NULL)
		return -1;
	return raiz->altura;
}

// Retorna o maior entre os dois valores
int maior(int a, int b) {
	if (a >= b)
		return a;
	return b;
}

// Retorna o fator de balanceamento do No no endereço raiz
// Retorna 0 se raiz é NULL
int calcularFator(No *raiz) {
	if (raiz == NULL)
		return 0;
	return alturaNo(raiz->esq) - alturaNo(raiz->dir);
}

// Operação de rotação à esquerda a partir do No em r
No *rotacaoEsquerda(No *r) {
	No *auxEsq, *auxDir;

	// armazenamos as subárvores
	auxEsq = r->esq;
	auxDir = r->dir;

	// rotação
	auxDir->esq = r; // o filho esquerdo da subárvore direita passa a ser r
	r->dir = auxEsq; // o filho direito de r passa a ser o filho esquerdo

	// recalculamos a altura de quem foi movimentado
	r->altura = maior(alturaNo(r->esq), alturaNo(r->dir));
	auxEsq->altura = maior(alturaNo(auxEsq->esq), alturaNo(auxEsq->dir));

	return auxEsq; // que passou a ser a nova raiz
}

// Operação de rotaão à esquerda a partir do No em r
No *rotacaoDireita(No *r) {
	No *auxEsq, *auxDir;

	// armazenamos as subárvores
	auxEsq = r->esq;
	auxDir = r->dir;

	// rotação
	auxEsq->dir = r; // o filho direito da subárvore esquerda passa a ser r
	r->esq = auxDir; // o filho esquerdo de r passa a ser o filho direito

	// recalculamos a altura de quem foi movimentado
	r->altura = maior(alturaNo(r->esq), alturaNo(r->dir));
	auxEsq->altura = maior(alturaNo(auxEsq->esq), alturaNo(auxEsq->dir));

	return auxEsq; // que passou a ser a nova raiz
}

// Composição de uma rotação à direita centrada no filho à direita, com de uma à esquerda centrada em r
No *rotacaoDuplaEsquerda(No *r) {
	r->dir = rotacaoDireita(r->dir);
	return rotacaoEsquerda(r);
}

// Composição de uma rotação à esquerda centrada no filho à esquerda com de uma à direita dentrada em r
No *rotacaoDuplaDireita(No *r) {
	r->esq = rotacaoEsquerda(r->esq);
	return rotacaoDireita(r);
}

// realiza o balanceamento do No em raiz
No *balancear(No *raiz) {
	int fator = calcularFator(raiz);

	// rotação à esquerda
	if (fator < -1 && calcularFator(raiz->dir) <= 0)
		raiz = rotacaoEsquerda(raiz);
	// rotação à direita
	else if (fator > 1 && calcularFator(raiz->esq) >= 0)
		raiz = rotacaoDireita(raiz);
	// rotação dupla esquerda-direita
	else if (fator > 1 && calcularFator(raiz->esq) < 0)
		raiz = rotacaoDuplaDireita(raiz);
	// rotação dupla direita-esquerda
	else if (fator < -1 && calcularFator(raiz->dir) > 0)
		raiz = rotacaoDuplaEsquerda(raiz);

	return raiz;
}

// Insere um No com valor x na árvore, a partir do endereço raiz
No *inserir(No *raiz, int x) {
	// se achamos um espaço vazio, inserimos
	if (raiz == NULL)
		return novoNo(x);

	// se é menor, vamos para a esquerda
	if (x < raiz->valor)
		raiz->esq = inserir(raiz->esq, x);
	// se é maior, vamos para a direita
	else if (x > raiz->valor)
		raiz->dir = inserir(raiz->dir, x);

	// na recursão, atualiza a altura de todos os nós entre a raíz e o novo nó e os balanceia de acordo
	raiz->altura = maior(alturaNo(raiz->esq), alturaNo(raiz->dir)) + 1;
	raiz = balancear(raiz);

	return raiz;
}

// Busca o No de valor x e o remove da árvore
// O valor de retorno existe para permitir a recursão
No *remover(No *raiz, int x) {
	//se chegamos ao fim da árvore
	if (raiz == NULL)
		return NULL;

	// se encontramos o nó a ser removido
	if (raiz->valor == x) {
		// se é nó folha
		if (raiz->esq == NULL && raiz->dir == NULL) {
			free(raiz);
			return NULL;
		}

		// se tem dois filhos
		if (raiz->esq != NULL && raiz->dir != NULL) {
			substituiMenorDireita(raiz, raiz->dir);

			raiz->esq = remover(raiz->esq, x);
			return raiz;
		// se tem apenas um filho
		} else {
			No *aux;
			// filho à esquerda
			if (raiz->esq != NULL)
				aux = raiz->esq;
			// filho à direita
			else
				aux = raiz->dir;

			free(raiz);
			return aux;
		}
	// se não encontramos ainda quem queremos removes
	} else {
		// se x é menor que o atual, está à esquerda
		if (x < raiz->valor)
			raiz->esq = remover(raiz->esq, x);
		// se x é maior que o atual, está à direita
		else
			raiz->dir = remover(raiz->dir, x);
	}

	// na recursão, atualiza a altura de todos os nós entre a raíz e o novo nó e os balanceia de acordo
	raiz->altura = maior(alturaNo(raiz->esq), alturaNo(raiz->dir)) + 1;
	raiz = balancear(raiz);

	return raiz;
}

void substituiMenorDireita(No *raiz, No *dir) {
	// se não há elemento à esquerda (elemento menor)
	if (dir->esq == NULL) {
		No *aux;
		raiz->valor = dir->valor; // substituição

		// removemos quem estava à direita
		aux = dir;
		dir = dir->dir;
		free(aux);
	} else //continuamos procurando o menor
		substituiMenorDireita(raiz, dir->esq);
}

// Impressões --------------------------------------------

// Imprime a árvore em pré-ordem
void imprimirPreOrdem(No *raiz){
	if(raiz != NULL){
		printf("%d ", raiz->valor);
		imprimirPreOrdem(raiz->esq);
		imprimirPreOrdem(raiz->dir);
	}
}

// Imprime a árvore em in-ordem
void imprimirInOrdem(No *raiz){
	if(raiz != NULL){
		imprimirPreOrdem(raiz->esq);
		printf("%d ", raiz->valor);
		imprimirPreOrdem(raiz->dir);
	}
}

// Imprime a árvore em pós-ordem
void imprimirPosOrdem(No *raiz){
	if(raiz != NULL){
		imprimirPreOrdem(raiz->esq);
		imprimirPreOrdem(raiz->dir);
		printf("%d ", raiz->valor);
	}	
}


