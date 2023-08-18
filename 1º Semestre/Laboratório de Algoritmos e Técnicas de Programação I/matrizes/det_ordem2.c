#include <stdio.h>
#include <locale.h>

int main() {
  int A[2][2], i, j, det=0, diagP[2], diagS[2];
  
  setlocale(LC_ALL, "Portuguese");

  for(i=0; i<2; i++){
    for(j=0; j<2; j++){
      printf("Elemento %dx%d: ", i, j);
      scanf("%d", &A[i][j]);

      if(i==j){ 
      diagP[i] = A[i][j];
      } else{ 
      diagS[i] = A[i][j];
      }
    }
  }

    det += diagP[0] * diagP[1];
    det -= diagS[0] * diagS[1];

	printf("\n\nDiagonal principal: %d  %d", diagP[0], diagP[1]);
	printf("\nDiagonal secudária: %d  %d", diagS[0], diagS[1]);
    printf("\nDeterminante da matriz:  %d", det);

  return 0;
}
  
