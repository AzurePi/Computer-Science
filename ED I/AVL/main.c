#include <stdio.h>
#include "avl.h"


int main(){
	No *raiz = NULL;
  int i;
  
  for(i = 0; i < 10; i++){
    inserir(raiz, i);
    imprimirPreOrdem(raiz);
    printf("\n");
  }
  
	return 0;
}

