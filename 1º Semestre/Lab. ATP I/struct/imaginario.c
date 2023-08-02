#include <stdio.h>

#define n 2

// Criação da struct
struct complexo {
  float real, im;
};

int main() {
  struct complexo z, w, soma, produto;

  printf("Parte real do número z: ");
  scanf("%f", &z.real);
  printf("Parte imaginária do número z: ");
  scanf("%f", &z.im);

  printf("\n");
  
  printf("Parte real do número w: ");
  scanf("%f", &w.real);
  printf("Parte imaginária do número w: ");
  scanf("%f", &w.im);

  printf("\n");
  printf("z = %f + %fi\n", z.real, z.im);
  printf("w = %f + %fi\n\n\n", w.real, w.im);

  //soma de complexos
  soma.real = z.real + w.real;
  soma.im = z.im + w.im;
  printf("z + w = %f + %fi\n", soma.real, soma.im);

  //produto de complexos
  produto.real = z.real * w.real - z.im * w.im;
  produto.im = z.real * w.im + z.im * w.real;
  printf("z * w = %f + %fi", produto.real, produto.im);
  
  return 0;
}
  
