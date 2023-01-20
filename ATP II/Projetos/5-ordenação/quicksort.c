#include <stdio.h>
#include <time.h>

#define n 200000

typedef struct biggo {
	int high;
	int low;
} BigInt;

void ler(BigInt *vet);
void imprimir(BigInt *vet);

int main(){
	BigInt vet[n];
	time_t begin, end;
	
	ler(vet); //lê dados de um arquivo bigint.dat e armazena num vetor
	
	time(&begin); //marcamos o instante em que o sorting começa
	// sorting
	time(&end); //marcamos o instante em que o sorting termina
	
	imprimir(vet); //imprime o vetor já ordenado no arquivo quick.dat
	
	printf("%lf" , end - begin); //imprime na tela o tempo tomado pela ordneação
	
	return 0;
}

void ler(BigInt *vet){
	FILE *big;
	int i;
	
	big = fopen("bigint.dat", "r");
	
	for(i = 0; i < n; i++)
		fscanf(big, "%d %d", &vet[i].high, &vet[i].low);
	
	fclose(big);
}

void imprimir(BigInt *vet){
	FILE *quick;
	int i;
	
	quick = fopen("quick.dat", "w");
	
	for(i = 0; i < n; i++)
		fprintf(quick, "%d %d\n", vet[i].high, vet[i].low);
	
	fclose(quick);
}
