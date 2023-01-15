#include <stdio.h>

void ordenar(float*, int, int); //ordenação através do algoritmo de inserção

int main(){
	int N, k;
	int i;
	
	scanf("%d %d", &N, &k);
	float vet[N];
	
	for(i = 0; i<N; i++)
		scanf("%f", &vet[i]);
	
	ordenar(vet, N, k);
	
	for(i = 0; i<N; i++)
		printf("%.3f ", vet[i]);
	
	return 0;
}

void ordenar(float *vet, int N, int k){
	int i, j;
	float x;
	
	for(i = 2; i<N; i++)
	{
		x = vet[i]; //armazena o número sendo inserido
		j = i-1; //a inserção começará por aqui
		
		//se estamos antes de ou em k, ordenamos de forma crescente
		if(i <= k)
		{
			//encontramos a posição, dentre as anteriores,
			//em que x deveria estar
			while(j >= 0 && vet[j] > x)
			{
				vet[j+1] = vet[j]; //move o próximo número para essa posição
				j--; //analisa o índice anterior
			}
			vet[j+1] = x; //insere x na posição adequada
		}else //se estamos em ou depois de k, ordenamos de forma decrescente
		{
			//encontramos a posição, dentre as anteriores,
			//em que x deveria estar
			while(j >= 0 && vet[j] < x)
			{
				vet[j+1] = vet[j]; //move o próximo número para essa posição
				j--; //analisa o índice anterior
			}
			vet[j+1] = x; //insere x na posição adequada
		}
	}
	return;
}
