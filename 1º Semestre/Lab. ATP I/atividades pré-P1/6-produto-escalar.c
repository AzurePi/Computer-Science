#include <stdio.h>

int main(){
	float u[3], v[3], alpha, soma[3], resul[3], escalar = 0;
	
	for(int i = 0; i<3; i++){
		printf("u[%d] = ", i);
		scanf("%f", &u[i]);
	}
	
	printf("\n");
	
	for(int i = 0; i<3; i++){
		printf("v[%d] = ", i);
		scanf("%f", &v[i]);
	}
	
	printf("\n");
	printf("alpha = ");
	scanf("%f", &alpha);
	
	//a
	printf("\nsoma = [");
	for(int i = 0; i<3; i++){
		soma[i] = u[i] + v[i];
		printf(" %f", soma[i]);
	}
	printf("]\n");
	
	//b
	printf("\nalpha * soma = [");
	for(int i = 0; i<3; i++){
		resul[i] = alpha * soma[i];
		printf(" %f", resul[i]);
	}
	printf("]\n");
	
	//c
	for(int i = 0; i<3; i++){
		escalar  += u[i]*v[i];
	}
	printf("produto escalar = %f", escalar);
	
	return 0;
}
