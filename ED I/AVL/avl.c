// Implementa��o: �rvore bin�ria de busca balanceada (AVL)
#include "avl.h"
#include <stdlib.h>

// Opera��es ---------------------------------------------
void inserir(no *raiz, no x){
	if(raiz == null)
		raiz = x;
	
	//se � menor, vamos para a esquerda
	if(x < raiz->dado){
		if(raiz->esq == NULL) raiz->esq = x;
		else inserir(raiz->esq, x);	
	}else{ //se � maior ou igual, vamos para a direita
		if(raiz->dir == NULL) raiz->dir = x;
		else inserir(raiz->dir, x);
	}
	
	rebalancear(raiz);
}


void remover(no *raiz, tipo_chave x){

}


int calcularFator(no *raiz){
	
	
}


void rebalancear(no *raiz){
	
}
