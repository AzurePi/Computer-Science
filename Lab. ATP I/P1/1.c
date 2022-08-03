#include <stdio.h>
#define n 1

int main(){
	float IMC[n], alt[n], pes[n];
	int sex[n];
	char cond[n][15];
	
	for (int i = 0; i<n; i++){
		printf("Sexo (1 - masculino, 0 - feminino): ");
		scanf("%d", &sex[i]);
		printf("Altura: ");
		scanf("%f", &alt[i]);
		printf("Peso: ");
		scanf("%f", &pes[i]);
		printf("\n");
		
		IMC[i] = pes[i]/(alt[i]*alt[i]);
	}
	
	printf("\n");
	
	for(int i = 0; i<n; i++){
		printf("Condição da pessoa %d: ", i);
		if(sex[i] == 0){
			if(IMC[i] < 19.0){
				printf("Abaixo do peso");
			}else if(IMC[i]<=23.9){
				printf("Peso normal");
			}else{
				printf("Acima do peso");
			}
		}else{
			if(IMC[i] < 20.0){
				printf("Abaixo do peso");
			}else if(IMC[i]<=24.9){
				printf("Peso normal");
			}else{
				printf("Acima do peso");
			}
		}
		printf("\n");
	}
	
	return 0;
}
