#include <stdio.h>
#include "avl.h"

int main(){
	No *raiz = NULL;
  int i;

  raiz = inserir(raiz, 5);
  raiz = inserir(raiz, 2);
  raiz = inserir(raiz, 10);

  printf("Pré-ordem: ");
  imprimirPreOrdem(raiz);
  printf("\n");
  printf("In-ordem: ");
  imprimirInOrdem(raiz);
  printf("\n");
  printf("Pós-ordem: ");
  imprimirPosOrdem(raiz);
  printf("\n");

  printf("\n");
  raiz = remover(raiz, 5);
  imprimirPosOrdem(raiz);

  printf("\n");

  for(i = 0; i < 15; i+=2){
    raiz = inserir(raiz, i);
    imprimirPreOrdem(raiz);
    printf("\n");
  }

	return 0;
}

