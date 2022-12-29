#include <stdio.h>
#include <stdlib.h>

int passo = 625;
int **labirinto, **marcas;

void ler_labirinto(int N);
void zera_marcas(int N);
void caminhar(int N, int I, int C, int x, int y);

int main(){
	int N, I, C;
	int passos;
	
	scanf("%d %d %d", &N, &I, &C);

	ler_labirinto(N);
	zera_marcas(N);
	
	caminhar(N, I, C, 0, I);
	printf("%d", passos);

	return 0;
}

void ler_labirinto(int N){
	int i, j;
	
	labirinto = malloc(N * sizeof(int *));
	
	for(i = 0; i<N; i++)
		labirinto[i] = malloc(sizeof(int));
		
	for(i = 0; i<N; i++)
	{
		for(j = 0; j<N; j++)
			scanf("%d", &labirinto[i][j]);
	}
	
	return;
}

void zera_marcas(int N){
	int i, j;

	marcas = malloc(N * sizeof(int *));
	
	for(i = 0; i< N; i++)
		marcas[i] = malloc(sizeof(int));
		
	for(i = 0; i<N; i++)
	{
		for(j = 0; j<N; j++)
			marcas[i][j] = 0;
	}

	return;
}

/*
	-Procura uma nova posição
	-Marca essa posição como visitada
		-Chama a função novamente
	-Marca essa posição como não visitada
	-Quando cehgar ao final, retorna
*/
void caminhar(int N, int I, int C, int x, int y){
	
	
	
	
	
	
	
	
	return;
}







