#include <stdio.h>

int main(){
	int A[3][3], B[3][3], C[3][3], i, j;
	
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("Valor de A[%d][%d]: ", i, j);
			scanf(" %d", &A[i][j]);
			printf("Valor de B[%d][%d]: ", i, j);
			scanf(" %d", &B[i][j]);
		}
	}
	
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			C[i][j] = A[i][j] + B[i][j];
		}
	}

	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("\nC[%d][%d]: %d", i, j, C[i][j]);
		}
	}


	return 0;
}
  
