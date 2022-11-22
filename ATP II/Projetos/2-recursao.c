#include <stdio.h>
#include <stdlib.h>

//começando do índice m para trás, imprime quantas (count) combinações de "num" somam K
void decompor(int *comb, int K, int m, int *count);

int main(){
	int N, M;
	int i, j;
	int *num; //endereço do vetor dos números que serão usados na combinação
	int *inteiros; //endereço do vetor dos números que serão decompostos 
	int *maior; //endereço do vetor que armazenará a maior combinação possível que decompõe K
	int *count; //contador que armazena quantas decomposições há para cada K
	
	scanf("%d %d", &N, &M);
	
	//alocação dinâmica dos vetores de acordo com a entrada
	num = malloc(M*sizeof(int));
	inteiros = malloc(N*sizeof(int));
	maior = malloc(M*sizeof(int));
	
	//leitura dos números usados na combinação
	for(i = 0; i<M; i++)
		scanf("%d ", &num[i]);
	
	//leitura dos inteiros a serem descompostos
	for(i = 0; i<N; i++)
		scanf("%d ", &inteiros[i]);
	
	
	for(i = 0; i<N; i++)
	{
		*count = 0; //zera o valor armazenado em count para cada K
		decompor(num, inteiros[i], M-1, count); //começando do índice M-1 para trás, imprime quantas (count) combinações de "num" somam K
	}
	

	//liberação da memória alocada
	free(num);
	free(inteiros);
	free(maior);
	
	return 0;
}

//começando do índice m para trás, imprime quantas (count) combinações de "num" somam K
void decompor(int *num, int K, int m, int *count){
	int sum = 0, i = m;
	
	while(sum < K && i >= 0) //enquanto houver números para ler e não se obteve a soma
	{
		sum += comb[i]; //soma o número atual
		if(sum > K) //se a soma já tiver passado
			sum -= comb[i]; //remove o número que fez o valor "estourar"
		i--; //passa para o número anterior
	}

	if(sum == K) //se a soma funcionou
		*count++;
	
	if(i > 0) //se tiverem sobrado valores em "num"
	{
		sum -= comb[i]; //remove o número que igualou o valor
		
		//repete o processo anterior
		while(sum < K && i >= 0) //enquanto houver números para ler e não se obteve a soma
		{
			sum += comb[i]; //soma o número atual
			if(sum > K) //se a soma já tiver passado
				sum -= comb[i]; //remove o número que fez o valor "estourar"
			i--; //passa para o número anterior
		}
		
	}
	
	
	if(m > 0) //se ainda houver combinações a serem feitas
		decompor(comb, K, m-1, count); //chama a função novamente, considerando um número a menos de "comb"
	else
	{
		printf("%d ", *count); //imprime a quantidade de combinações
	}

	return;
}
