#include <stdio.h>

// funções
int fat(int n){
  int res = n;
  if(n>1){
    res*=fat(n-1);
  }
  if(n==0){
    res = 1;
  }
  return res;
}



int main() {
  int n, m, resultado;

  printf("Digite valores para m e n:\n");
  scanf("%d%d", &m, &n);

  resultado = fat(m)/(fat(m-n)*fat(n));

    printf("Combinação de %d, tomados %d a %d: %d", m, n, n, resultado);
  
  return 0;
}
  