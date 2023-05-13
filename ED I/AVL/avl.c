// Implementa��o: �rvore bin�ria de busca balanceada (AVL)
#include "avl.h"
#include <stdio.h>
#include <stdlib.h>


// Opera��es ---------------------------------------------

// Aloca um No com valor x na mem�ria e retorna seu endere�o
No *novoNo(int x) {
	No *novo = malloc(sizeof(No));
	novo->valor = x;
	novo->esq = NULL;
	novo->dir = NULL;
	novo->altura = 0; // todo n� � inserido como folha, e toda folha tem altura 0
	return novo;
}

// Retorna a altura do No no endere�o raiz
// Retorna -1 se raiz � NULL
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

// Retorna o fator de balanceamento do No no endere�o raiz
// Retorna 0 se raiz � NULL
int calcularFator(No *raiz) {
	if (raiz == NULL)
		return 0;
	return alturaNo(raiz->esq) - alturaNo(raiz->dir);
}

// Opera��o de rota��o � esquerda a partir do No em r
No *rotacaoEsquerda(No *r) {
	No *auxEsq, *auxDir;

	// armazenamos as sub�rvores
	auxEsq = r->esq;
	auxDir = r->dir;

	// rota��o
	auxDir->esq = r; // o filho esquerdo da sub�rvore direita passa a ser r
	r->dir = auxEsq; // o filho direito de r passa a ser o filho esquerdo

	// recalculamos a altura de quem foi movimentado
	r->altura = maior(alturaNo(r->esq), alturaNo(r->dir));
	auxEsq->altura = maior(alturaNo(auxEsq->esq), alturaNo(auxEsq->dir));

	return auxEsq; // que passou a ser a nova raiz
}

// Opera��o de rota�o � esquerda a partir do No em r
No *rotacaoDireita(No *r) {
	No *auxEsq, *auxDir;

	// armazenamos as sub�rvores
	auxEsq = r->esq;
	auxDir = r->dir;

	// rota��o
	auxEsq->dir = r; // o filho direito da sub�rvore esquerda passa a ser r
	r->esq = auxDir; // o filho esquerdo de r passa a ser o filho direito

	// recalculamos a altura de quem foi movimentado
	r->altura = maior(alturaNo(r->esq), alturaNo(r->dir));
	auxEsq->altura = maior(alturaNo(auxEsq->esq), alturaNo(auxEsq->dir));

	return auxEsq; // que passou a ser a nova raiz
}

// Composi��o de uma rota��o � direita centrada no filho � direita, com de uma � esquerda centrada em r
No *rotacaoDuplaEsquerda(No *r) {
	r->dir = rotacaoDireita(r->dir);
	return rotacaoEsquerda(r);
}

// Composi��o de uma rota��o � esquerda centrada no filho � esquerda com de uma � direita dentrada em r
No *rotacaoDuplaDireita(No *r) {
	r->esq = rotacaoEsquerda(r->esq);
	return rotacaoDireita(r);
}

// realiza o balanceamento do No em raiz
No *balancear(No *raiz) {
	int fator = calcularFator(raiz);

	// rota��o � esquerda
	if (fator < -1 && calcularFator(raiz->dir) <= 0)
		raiz = rotacaoEsquerda(raiz);
	// rota��o � direita
	else if (fator > 1 && calcularFator(raiz->esq) >= 0)
		raiz = rotacaoDireita(raiz);
	// rota��o dupla esquerda-direita
	else if (fator > 1 && calcularFator(raiz->esq) < 0)
		raiz = rotacaoDuplaDireita(raiz);
	// rota��o dupla direita-esquerda
	else if (fator < -1 && calcularFator(raiz->dir) > 0)
		raiz = rotacaoDuplaEsquerda(raiz);

	return raiz;
}

// Insere um No com valor x na �rvore, a partir do endere�o raiz
No *inserir(No *raiz, int x) {
	// se achamos um espa�o vazio, inserimos
	if (raiz == NULL)
		return novoNo(x);

	// se � menor, vamos para a esquerda
	if (x < raiz->valor)
		raiz->esq = inserir(raiz->esq, x);
	// se � maior, vamos para a direita
	else if (x > raiz->valor)
		raiz->dir = inserir(raiz->dir, x);

	// na recurs�o, atualiza a altura de todos os n�s entre a ra�z e o novo n� e os balanceia de acordo
	raiz->altura = maior(alturaNo(raiz->esq), alturaNo(raiz->dir)) + 1;
	raiz = balancear(raiz);

	return raiz;
}

// Busca o No de valor x e o remove da �rvore
// O valor de retorno existe para permitir a recurs�o
No *remover(No *raiz, int x) {
	//se chegamos ao fim da �rvore
	if (raiz == NULL)
		return NULL;

	// se encontramos o n� a ser removido
	if (raiz->valor == x) {
		// se � n� folha
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
			// filho � esquerda
			if (raiz->esq != NULL)
				aux = raiz->esq;
			// filho � direita
			else
				aux = raiz->dir;

			free(raiz);
			return aux;
		}
	// se n�o encontramos ainda quem queremos removes
	} else {
		// se x � menor que o atual, est� � esquerda
		if (x < raiz->valor)
			raiz->esq = remover(raiz->esq, x);
		// se x � maior que o atual, est� � direita
		else
			raiz->dir = remover(raiz->dir, x);
	}

	// na recurs�o, atualiza a altura de todos os n�s entre a ra�z e o novo n� e os balanceia de acordo
	raiz->altura = maior(alturaNo(raiz->esq), alturaNo(raiz->dir)) + 1;
	raiz = balancear(raiz);

	return raiz;
}

void substituiMenorDireita(No *raiz, No *dir) {
	// se n�o h� elemento � esquerda (elemento menor)
	if (dir->esq == NULL) {
		No *aux;
		raiz->valor = dir->valor; // substitui��o

		// removemos quem estava � direita
		aux = dir;
		dir = dir->dir;
		free(aux);
	} else //continuamos procurando o menor
		substituiMenorDireita(raiz, dir->esq);
}

// Impress�es --------------------------------------------

// Imprime a �rvore em pr�-ordem
void imprimirPreOrdem(No *raiz){
	if(raiz != NULL){
		printf("%d ", raiz->valor);
		imprimirPreOrdem(raiz->esq);
		imprimirPreOrdem(raiz->dir);
	}
}

// Imprime a �rvore em in-ordem
void imprimirInOrdem(No *raiz){
	if(raiz != NULL){
		imprimirPreOrdem(raiz->esq);
		printf("%d ", raiz->valor);
		imprimirPreOrdem(raiz->dir);
	}
}

// Imprime a �rvore em p�s-ordem
void imprimirPosOrdem(No *raiz){
	if(raiz != NULL){
		imprimirPreOrdem(raiz->esq);
		imprimirPreOrdem(raiz->dir);
		printf("%d ", raiz->valor);
	}	
}


