#include <stdio.h>

int main() {
  int num1, num2, num3;

  printf("Digite três números inteiros distintos: ");
  scanf("%d %d %d", &num1, &num2, &num3);

  if(num1<num2 && num1<num3){
    if(num2<num3){
      printf("\nA ordem crescente é: %d %d %d", num1, num2, num3);
    } else {
      printf("\nA ordem crescente é: %d %d %d", num1, num3, num2);
    } 
  } else {
    if(num1<num2 && num1>num3){
      printf("\nA ordem crescente é: %d %d %d", num3, num1, num2);
    } else if(num1>num2 && num1<num3){
      printf("\nA ordem crescente é: %d %d %d", num2, num1, num3);
    } else if(num1>num2 && num1>num3){
      if(num2>num3){
      printf("\nA ordem crescente é: %d %d %d", num3, num2, num1);
        } else {
        printf("\nA ordem crescente é: %d %d %d", num2, num3, num1);
        }
    }
  }
  
    return 0;
}
  
