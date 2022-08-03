#include <stdio.h>

int main(){
  int A[3][4], T[4][3];

  for(int i = 0; i<3; i++){
    for(int j = 0; j<4; j++){
      printf("A[%d][%d]: ", i, j);
      scanf("%d", &A[i][j]);
      T[j][i] = A[i][j];
    }
  }

  printf("\nTransposta:\n");
  
  for(int i = 0; i<4; i++){
    for(int j = 0; j<3; j++){
      printf("%d ", T[i][j]);
    }
    printf("\n");
  }

	return 0;
}
  
