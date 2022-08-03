#include <stdio.h>

int main(){
  int A[3][3];
  int b[3], x[3];
  int detX = 0, detA = 0;

  for(int i = 0; i<3; i++){
    for(int j = 0; j<3; j++){
      printf("A[%d][%d]: ", i, j);
      scanf("%d", &A[i][j]);
    }
  }

  printf("\n");

  for(int i = 0; i<3; i++){
    printf("b[%d]: ", i);
    scanf("%d", &b[i]);
  }
  
  printf("\nResolução do Sistema Linear:\n");
  
  detA += A[0][0] * A[1][1] * A[2][2];
  detA += A[0][1] * A[1][2] * A[2][0];
  detA += A[0][2] * A[1][0] * A[2][1];
  
  detA -= A[2][2] * A[1][2] * A[0][2];
  detA -= A[1][1] * A[0][1] * A[2][1];
  detA -= A[0][0] * A[2][0] * A[1][0];

  
	return 0;
}
  
