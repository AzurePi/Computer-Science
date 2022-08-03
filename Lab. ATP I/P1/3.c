#include <stdio.h>

int main(){
	//Declaração das variáveis
	int i, j, n = 3;
	float A[n][n], B[n][n];
	
	//Programa principal
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
		{
			printf("Digite o elemento A[%d][%d]: ", i+1, j+1);
			scanf("%f", &A[i][j]);	
		}
	
	int s = 1; //assume que toda matriz é simétrica

 	//faz a transposição
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			B[i][j] = A[j][i];
		}
	}
	
	//verifica a simetria de fato
	for(i = 0; i<n; i++){
		for(j=0; j<n; j++){
			if(A[i][j] != A[j][i]){
				s = 0;
				break;
			}
		}
	}
	
	if(s == 1){
		printf("Essa matriz É simétrica");	
	}else{
		printf("Essa matriz NÃO É simétrica");
	}
	
	return 0;
}
