#include <stdio.h>
#include <stdlib.h>

int quant; //vari�vel global para controlar a quantidade de decomposi��es

int size(int *vet, int i);
//determina o tamanho de um vetor terminado em 0

void pop(int *vet);
//transforma o �ltimo n�mero de um vetor em seu novo final (ou seja, 0)

void zerar(int *vet, int i);
//zera os valores armazenados num vetor

void copy(int *target, int *origin);
//faz o que stcpy faria, agora com uma array de int


void decompor(int K, int *num, int *comb, int m, int M, int *maior);
//decomp�e um inteiro K usando os n�meros no vetor "num", com o endere�o de um vetor "comb" que armazenar� as combina��es
//recebe tamb�m o �ndice m por onde come�ar a analisar "num" e o tamanho M de "num", e o endere�o do vetor "maior" que armazena a maior combina��o j� encontrada


int main(){
	int N, M, i, j, k;
	int *num; //endere�o do vetor dos n�meros que ser�o usados na combina��o
	int *inteiros; //endere�o do vetor dos n�meros que ser�o decompostos
	int *comb; //endere�p do vetor que armazenar� uma combina��o de "num"
	int *maior; //endere�o do vetor que armazenar� a maior combina��o poss�vel que decomp�e K
	
	scanf("%d %d", &N, &M);
	
	//aloca��o din�mica dos vetores de acordo com a entrada
	num = malloc((M+1)*sizeof(int));
	inteiros = malloc(N*sizeof(int));
	comb = malloc((M+1)*sizeof(int));
	maior = malloc((M+1)*sizeof(int));
	
	//leitura dos n�meros usados na combina��o
	for(i = 0; i<M; i++)
		scanf("%d", &num[i]);
	//com i = M
	num[i] = 0; //define o final do vetor "num"
	
	
	//leitura dos inteiros a serem descompostos
	for(i = 0; i<N; i++)
		scanf("%d", &inteiros[i]);
		
	zerar(comb, 0);
	zerar(maior, 0);
		
	//decomposi��o de cada K em "inteiros"
	for(i = 0; i<N; i++)
	{
		quant = 0; //zera a quantidade de combina��es
		decompor(inteiros[i], num, comb, 0, M+1, maior);
		
		printf("%d ", quant);
        if(quant) //se houver decomposições
        {
            k = size(maior, 0);
            for(j = 0; j<k; j++)
            {
                printf("%d ", maior[j]);
            }
        }
		printf("\n");
	}
	

	//libera��o da mem�ria alocada
	free(num);
	free(inteiros);
	free(comb);
	free(maior);
	
	return 0;
}

//determina o �mtimo �ndice de um vetor terminado em 0
int size(int *vet, int i){
	
	if(vet[i] == 0) //se chegamos ao final do vetor
		return i;
	//do contr�rio
	return size(vet, i+1);
}

//transforma o �ltimo n�mero de um vetor em seu novo final (ou seja, 0)
void pop(int *vet){
	int i = size(vet, 0);
	
	if(vet[i] != 0) //se h� algo antes do final do vetor
		vet[i-1] = 0; //esse algo � o novo final
	
	return;
}

//zera os valores armazenados num vetor
void zerar(int *vet, int i){
	
	if(vet[i] == 0) //se j� chegou ao final do vetor
		return;
	//do contr�rio
	vet[i] = 0;
	zerar(vet, i+1);
	return;
}

//faz o que stcpy faria, agora com uma array de int
void copy(int *target, int *origin){
	int i = size(target, 0);
	int j = size(origin, 0);
	int k;
	
	for(k = 0; k<=i; k++)
		target[i] = origin[j];
	
	return;
}



//decomp�e um inteiro K usando os n�meros no vetor "num", com o endere�o de um vetor "comb" que armazenar� as combina��es
//recebe tamb�m o �ndice m por onde come�ar a analisar "num" e o tamanho M de "num", e o endere�o do vetor "maior" que armazena a maior combina��o j� encontrada
void decompor(int K, int *num, int *comb, int m, int M, int *maior){
	int i = m;
	int c = size(comb, 0) - 1, o = size(maior, 0) - 1; //-1 para desconsiderar a posi��o em que armazena-se o 0 e evitar problemas de acesso de mem�ria
	
	//final da fun��o recursiva ----------------------------------------
	if(K == 0) //se estamos decompondo o zero
	{
		quant++; //a decomposi��o funcionou
		
		if(c >= o && comb[c] > maior[o]) //se comb tiver >= n�mero de elementos de "maior", e o maior/�ltimo elemento de "comb" for maior que o de "maior"
			copy(maior, comb); //"comb" passa a ser "maior"
	}else if(K <= 0) //se estamos decompondo um n�mero negativo
	{
		return; //sai da fun��o, pois a combina��o testada n�o funcionou
	}
		
	//meio da fun��o recursiva ------------------------------------------
	while(i != M) //enquanto n�o estivermos no fim da an�lise de "num"
	{
		if(num[i] > maior[o]) //se o n�mero analisado agora for maior do que o maior/�ltimo n�mero em "maior"
		{
			maior[o+1] = num[i]; //adiciona o n�mero analisado ao final de "maior"
		}
		
		comb[c+1] = num[i]; //armazena o n�mero analisado ao final "comb"; � assim que "comb" � preenchida
		
		//para garantir que se verificam todas as combina��es
		decompor(K - num[i], num, comb, m+1, M, maior); //decompomos o novo K, decrescido do n�mero analisado, e passamos a analisar "num" da posi��o m+1
		pop(comb); //retiramos o �ltimo n�mero de comb
		
		
		i++;
	}
	
	return;
}
