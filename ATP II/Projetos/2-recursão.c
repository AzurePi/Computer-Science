#include <stdio.h>
#include <stdlib.h>

int **comb; //endereço da matriz de todas as combinacoes possíveis de "conjunto"

//determina recursivamente as combinações com m elementos de "conjunto" de tamanho M, com m variando de 1 até M
void combinar(int *conjunto, int M, int m, int linha);

void decompor(int K, int M, int curr, int quant, int *maior);

int main(){
	int N, M;
	int *conjunto; //endereço do vetor dos números que serão usados na combinação
	int *inteiros; //endereço do vetor dos números que serão decompostos 
	int i, j;
	
	scanf("%d %d", &N, &M);
	
	//alocação dinâmica dos vetores e matriz de acordo com a entrada
	conjunto = malloc(M*sizeof(int));
	inteiros = malloc(N*sizeof(int));
	
	//leitura dos valores usados na combinação
	for(i = 0; i<M; i++)
		scanf("%d ", &conjunto[i]);
	
	//leitura dos valores a serem descompostos
	for(i = 0; i<N; i++)
		scanf("%d ", &inteiros[i]);
	
	
	//aloca espaço de memória para a matriz "comb"
	comb = malloc(M*sizeof(int));
	for(i = 0; i<M; i++)
		comb[i] = malloc(M*sizeof(int));
	
	//inicializa a matriz "comb" com 0
	for(i = 0; i<M; i++)
		for(j = 0; j<M; j++)
			comb[i][j] = 0;
		
	combinar(conjunto, M, 1, 0); //determina todas as combinações possíveis para "conjunto"
	
	//verificando se "combinar" funciona
	for(i = 0; i<M; i++){
		for(j = 0; j<M; j++){
			printf("%d ", comb[i][j]);
		}
		printf("\n");
	}
		
	/*
	int *maior;
	//decomposição de cada valor de "inteiros" de acordo com "comb"
	for(i = 0; i<N; i++)
	{
		decompor(inteiros[i], M, 0, maior);
		printf("\n");
	}
	*/	

	//liberação da memória alocada
	free(conjunto);
	free(inteiros);
	
	return 0;
}

//determina recursivamente as combinações m a m dos M elementos de "conjunto", com m variando de 1 até M
void combinar(int *conjunto, int M, int m, int linha){
	int i, j, aux;
	
	if(m > M)
	{
		free(conjunto); //libera o espaço previamente alocado para "conjunto"
		return; //não faz sentido tomar M elementos m a m, então saí da função
	}else
	{	
		for(j = 1; j<=m; j++){
			//altera a posição dos números em "conjunto"
			for(i = 0; i<M-1; i++)
			{	
				aux = conjunto[i];
				conjunto[i] = conjunto[i+1];
				conjunto[i+1] = aux;	
			}
			//guarda a nova posição dos números em "comb"
			for(i = 0; i<M; i++)
				comb[linha][i] = conjunto[i];
			linha++;
		}
		
		combinar(conjunto, M, m+1, linha);
	}
}

void decompor(int K, int M, int quant, int *maior){
	//K é o número a ser decomposto
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
