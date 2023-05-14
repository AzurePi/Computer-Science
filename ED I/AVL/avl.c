////Pedro Benedicto de Melo Cardana

// Implementa��o: �rvore bin�ria de busca balanceada (AVL)
#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

// Opera��es ---------------------------------------------

// Aloca um No com valor x na mem�ria e retorna seu endere�o
No *novoNo(int x) {
  No *novo = malloc(sizeof(No));
  novo->valor = x;
  novo->altura = 1; // todo n� � inserido como folha, e toda folha tem altura 1
  novo->esq = NULL;
  novo->dir = NULL;
  return novo;
}

// Retorna a altura do No no endere�o raiz
// Retorna 0 se raiz � NULL
int alturaNo(No *raiz) {
  if (raiz == NULL)
    return 0;
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
  No *auxEsq = r->esq;
  No *aux = auxEsq->esq;

  // rota��o
  auxEsq->esq = r;
  r->dir = aux;

  // recalculamos a altura de quem foi movimentado
  r->altura = maior(alturaNo(r->esq), alturaNo(r->dir)) + 1;
  auxEsq->altura = maior(alturaNo(auxEsq->esq), alturaNo(auxEsq->dir)) + 1;

  return auxEsq; // retorna a nova raiz
}

// Opera��o de rota��o � esquerda a partir do No em r
No *rotacaoDireita(No *r) {
  No *auxEsq = r->esq;
  No *aux = auxEsq->dir;

  // rota��o
  auxEsq->dir = r;
  r->esq = aux;

  // recalculamos a altura de quem foi movimentado
  r->altura = maior(alturaNo(r->esq), alturaNo(r->dir)) + 1;
  auxEsq->altura = maior(alturaNo(auxEsq->esq), alturaNo(auxEsq->dir)) + 1;

  return auxEsq; // retorna a nova raiz
}

// Composi��o de uma rota��o � direita centrada no filho � direita, com de uma �
// esquerda centrada em r
No *rotacaoDuplaEsquerda(No *r) {
  r->dir = rotacaoDireita(r->dir);
  return rotacaoEsquerda(r);
}

// Composi��o de uma rota��o � esquerda centrada no filho � esquerda com de uma
// � direita dentrada em r
No *rotacaoDuplaDireita(No *r) {
  r->esq = rotacaoEsquerda(r->esq);
  return rotacaoDireita(r);
}

// realiza o balanceamento do No em raiz
No *balancear(No *raiz) {
  int fator = calcularFator(raiz);
  int fatorEsq = calcularFator(raiz->esq);
  int fatorDir = calcularFator(raiz->dir);

  // rota��o � esquerda
  if (fator < -1 && fatorDir <= 0)
    raiz = rotacaoEsquerda(raiz);
  // rota��o � direita
  else if (fator > 1 && fatorEsq >= 0)
    raiz = rotacaoDireita(raiz);
  // rota��o dupla esquerda-direita
  else if (fator > 1 && fatorEsq < 0)
    raiz = rotacaoDuplaDireita(raiz);
  // rota��o dupla direita-esquerda
  else if (fator < -1 && fatorDir > 0)
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
  // se j� existe
  else
    return raiz;

  // atualiza a altura do n�
  raiz->altura = maior(alturaNo(raiz->esq), alturaNo(raiz->dir)) + 1;

  return balancear(raiz); // rebalanceaia a �rvore e retorna
}

// Busca o No de valor x e o remove da �rvore
// O valor de retorno existe para permitir a recurs�o
No *remover(No *raiz, int x) {
  // se chegamos ao fim da �rvore
  if (raiz == NULL)
    return NULL;

  if (x < raiz->valor)
    raiz->esq = remover(raiz->esq, x);
  else if (x > raiz->valor)
    raiz->dir = remover(raiz->dir, x);
  else {

    // se h� uma ou nenhuma sub�rvore
    if (raiz->esq == NULL || raiz->dir == NULL) {
      // se h� sub�rvore � esquerda, salva-a, do contr�rio, salva a � direita
      No *aux = raiz->esq ? raiz->esq : raiz->dir;

      // se n�o h� sub�rvores
      if (aux == NULL) {
        aux = raiz;
        raiz = NULL;

        // se h� sub�rvores
      } else
        raiz = aux;

      free(aux);

      // se h� duas sub�rvores
    } else
      substituiMenorDireita(raiz, raiz->dir);
  }

  // atualiza a altura do n�
  raiz->altura = maior(alturaNo(raiz->esq), alturaNo(raiz->dir)) + 1;

  return balancear(raiz); // rebalanceaia a �rvore e retorna
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
  } else // continuamos procurando o menor
    substituiMenorDireita(raiz, dir->esq);
}

// Impress�es --------------------------------------------

// Imprime a �rvore em pr�-ordem
void imprimirPreOrdem(No *raiz) {
  if (raiz != NULL) {
    printf("%d ", raiz->valor);
    imprimirPreOrdem(raiz->esq);
    imprimirPreOrdem(raiz->dir);
  }
}

// Imprime a �rvore em in-ordem
void imprimirInOrdem(No *raiz) {
  if (raiz != NULL) {
    imprimirInOrdem(raiz->esq);
    printf("%d ", raiz->valor);
    imprimirInOrdem(raiz->dir);
  }
}

// Imprime a �rvore em p�s-ordem
void imprimirPosOrdem(No *raiz) {
  if (raiz != NULL) {
    imprimirPosOrdem(raiz->esq);
    imprimirPosOrdem(raiz->dir);
    printf("%d ", raiz->valor);
  }
}
