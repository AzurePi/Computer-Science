#include <stdio.h>
#include <stdlib.h>

int quant; //variável global para controlar a quantidade de decomposições

int size(int *vet, int i);
//determina o tamanho de um vetor terminado em 0

void pop(int *vet);
//transforma o último número de um vetor em seu novo final (ou seja, 0)

void zerar(int *vet, int i);
//zera os valores armazenados num vetor

void intcpy(int *target, int *origin);
//faz o que stcpy faria, agora com uma array de int


void decompor(int K, int *num, int *comb, int m, int M, int *maior);
//decompõe um inteiro K usando os números no vetor "num", com o endereço de um vetor "comb" que armazenará as combinações
//recebe também o índice m por onde começar a analisar "num" e o tamanho M de "num", e o endereço do vetor "maior" que armazena a maior combinação já encontrada


int main(){
	int N, M, i, j, k;
	int *num; //endereço do vetor dos números que serão usados na combinação
	int *inteiros; //endereço do vetor dos números que serão decompostos
	int *comb; //endereço do vetor que armazenará uma combinação de "num"
	int *maior; //endereço do vetor que armazenará a maior combinaçao possível que decompõe K
	
	scanf("%d %d", &N, &M);
	
	//alocação dinâmica dos vetores de acordo com a entrada
	num = malloc((M+1)*sizeof(int));
	inteiros = malloc(N*sizeof(int));
	comb = malloc((M+1)*sizeof(int));
	maior = malloc((M+1)*sizeof(int));
	
	//leitura dos números usados na combinação
	for(i = 0; i<M; i++)
		scanf("%d", &num[i]);
	//com i = M
	num[i] = 0; //define o final do vetor "num"
	
	
	//leitura dos inteiros a serem descompostos
	for(i = 0; i<N; i++)
		scanf("%d", &inteiros[i]);
		
	zerar(comb, 0);
	zerar(maior, 0);
		
	//decomposição de cada K em "inteiros"
	for(i = 0; i<N; i++)
	{
		quant = 0; //zera a quantidade de combinações
		decompor(inteiros[i], num, comb, 0, M+1, maior);
		
		printf("%d ", quant);
		if(quant) //se houver decomposições
		{
			k = size(maior, 0);
			for(j = 0; j<k; j++)
				printf("%d ", maior[j]);
		}
		printf("\n");
	}
	

	//liberação da memória alocada
	free(num);
	free(inteiros);
	free(comb);
	free(maior);
	
	return 0;
}

//determina o último índice de um vetor terminado em 0
int size(int *vet, int i){
	
	if(vet[i] == 0) //se chegamos ao final do vetor
		return i;
	//do contrário
	return size(vet, i+1);
}

//transforma o último número de um vetor em seu novo final (ou seja, 0)
void pop(int *vet){
	int i = size(vet, 0);
	
	if(vet[i] != 0) //se há algo antes do final do vetor
		vet[i-1] = 0; //esse algo é o novo final
	
	return;
}

//zera os valores armazenados num vetor
void zerar(int *vet, int i){
	
	if(vet[i] == 0) //se já chegou ao final do vetor
		return;
	//do contrário
	vet[i] = 0;
	zerar(vet, i+1);
	return;
}

//faz o que stcpy faria, agora com uma array de int
void intcpy(int *target, int *origin){
	int i = size(target, 0);
	int j = size(origin, 0);
	int k;
	
	for(k = 0; k<=i; k++)
		target[i] = origin[j];
	
	return;
}


//decompõe um inteiro K usando os números no vetor "num", com o endereço de um vetor "comb" que armazenará as combinações
//recebe também o índice m por onde começar a analisar "num" e o tamanho M de "num", e o endereço do vetor "maior" que armazena a maior combinação já encontrada
void decompor(int K, int *num, int *comb, int m, int M, int *maior){
	int i = m;
	int c = size(comb, 0) - 1, o = size(maior, 0) - 1; //-1 para desconsiderar a posição em que armazena-se o 0 e evitar problemas de acesso de memória
	
	//final da função recursiva ----------------------------------------
	if(K == 0) //se estamos decompondo o zero
	{
		quant++; //a decomposição funcionou
		
		if(c >= o && comb[c] > maior[o]) //se comb tiver >= número de elementos de "maior", e o maior/último elemento de "comb" for maior que o de "maior"
			copy(maior, comb); //"comb" passa a ser "maior"
	}else if(K <= 0) //se estamos decompondo um número negativo
		return; //sai da função, pois a combinação testada não funcionou
		
	//meio da função recursiva ------------------------------------------
	while(i != M) //enquanto não estivermos no fim da análise de "num"
	{
		if(num[i] > maior[o]) //se o número analisado agora for maior do que o maior/último número em "maior"
			maior[o+1] = num[i]; //adiciona o número analisado ao final de "maior"
		
		comb[c+1] = num[i]; //armazena o número analisado ao final "comb"; é assim que "comb" é preenchida
		
		//para garantir que se verificam todas as combinações
		decompor(K - num[i], num, comb, m+1, M, maior); //decompomos o novo K, decrescido do número analisado, e passamos a analisar "num" da posição m+1
		pop(comb); //retiramos o último número de comb
		
		
		i++;
	}
	
	return;
}
