#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(){
	int A[3][4], i, j, min = INFINITY, max = -INFINITY, S[3] = {0, 0, 0};

	setlocale(LC_ALL, "Portuguese");

	for(i=0; i<3; i++){
		for(j=0; j<4; j++){
    		printf("Elemento %dx%d: ", i, j);
    		scanf("%d", &A[i][j]);
      
    		S[i] += A[i][j];
       
    		if(A[i][j]>max){
    			max = A[i][j];
    		}
    		if(A[i][j]<min){
        	min = A[i][j];
      	}
    	}
    	printf("\n");
  	}
  	
  printf("--------------------\n");
  printf("Maior elemento: %d", max);
  printf("\nMenor elemento: %d", min);
  printf("\n\nSoma da linha 0: %d", S[0]);
  printf("\nSoma da linha 1: %d", S[1]);
  printf("\nSoma da linha 2: %d", S[2]);

  return 0;
}
