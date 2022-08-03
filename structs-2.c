#include <stdio.h>

#define n 2

typedef struct pessoa{
	char nome[100];
	float altura, peso;
} pessoa;


int main(){
	pessoa grupo[n];
	float altura, peso;
	
	for(int i=0; i<n; i++){
		printf("Nome da pessoa %d: ", i+1);
		scanf(" %[^\n]s", grupo[i].nome);
		printf("Altura da pessoa %d: ", i+1);
		scanf("%f", &grupo[i].altura);
		printf("Peso da pessoa %d: ", i+1);
		scanf("%f", &grupo[i].peso);
    printf("\n");
	}
	
	printf("\nDigite uma altura: ");
	scanf("%f", &altura);
	printf("Digite um peso: ");
	scanf("%f", &peso);
	
	printf("\n");
	
	//checagem da altura
	for(int i=0; i<n; i++){
		if(grupo[i].altura >= altura){
			printf("%s tem mais do que %.2fm\n", grupo[i].nome, altura);
		}
	}

  printf("\n");
	
	//checagem do peso
	for(int i=0; i<n; i++){
		if(grupo[i].peso >= peso){
			printf("%s tem mais do que %.2fkg\n", grupo[i].nome, peso);
		}
	}
	
	return 0;
}
