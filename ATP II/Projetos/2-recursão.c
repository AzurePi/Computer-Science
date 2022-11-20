#include <stdio.h>

void decompor(int K, int *conjunto, int M, int curr, int quant, int *maior){
	//K é o número a ser decomposto
	//"conjunto" é o vetor de tamanho M que contém os número que decomporão
	//curr é índice de "conjunto" sendo utilizado agora
	//quant é a quantidade de decomposições possíveis
	//"maior" armazena a maior combinação dentro de "conjunto" que decopõe K
	
	int i = 0;

	
		//impressão da quantidade de decomposições
		printf("%d ", quant);
	
		//impressão da maior combinação que decompõe K
		while(maior[i] != 0)
		{
			printf("%d ", maior[i]);
			i++;
		}		

}



int main(){
	int N, M;
	int *conjunto; //endereço do vetor dos números que serão usados na combinação
	int *inteiros; //endereço do vetor dos números que serão decompostos 
	int i;
	
	scanf("%d %d", &N, &M);
	
	//alocação dinâmica dos vetores de acordo com a entrada
	conjunto = malloc(M*sizeof(int));
	inteiros = malloc(N*sizeof(int));
	
	//leitura dos valores usados na combinação
	for(i = 0; i<M; i++)
		scanf("%d", conjunto[i]);
	
	//leitura dos valores a serem descompostos
	for(i = 0; i<N; i++)
		scanf("%d", inteiros[i]);
	
	
	//decomposição de cada valor de "inteiros"
	for(i = 0; i<N; i++)
	{
		int maior[M] = {0}; //vetor que armazenará a maior combinaçao possível
		decompor(inteiros[i], conjunto, M, 0, 0, maior);
		printf("\n");
	}
		

	//liberação da memória alocada
	free(conjunto);
	free(inteiros);
	
	return 0;
}
