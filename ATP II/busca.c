#include <stdio.h>

int flag;

void busca_crescente(int *vet, int in, int fin, int x){
	int	mid = (in+fin)/2;
	printf("%d ", mid);
	
	//se encontramos x no vetor
	if(vet[in] == x)
	{
		flag += 1;
		printf("%d ", in);
		return;
	}
	if(vet[mid] == x)
	{
		flag += 1;
		printf("%d ", mid);
		return;
	}
	if(vet[fin] == x)
	{
		flag += 1;
		printf("%d ", fin);
		return;
	}
	
	//se chegamos ao fim do vetor, e não encontramos x
	if(in == fin)
		return;
	
	//do contrário, ainda estamos procurando
	
	//se o número é menor do que a posição atual
	if(x < vet[mid])
	{
		//buscamos na metade anterior do vetor
		busca_crescente(vet, in, mid, x);
		return;
	}
	//se o número é maior do que aposição atual
	
	//buscamos na metade posteiror do vetor
	busca_crescente(vet, mid, fin, x);
	return;
}

void busca_decrescente(int *vet, int in, int fin, int x){
	int	mid = (in+fin)/2;
	printf("%d ", mid);
	
	//se encontramos x no vetor
	if(vet[in] == x)
	{
		flag += 1;
		printf("%d ", in);
		return;
	}
	if(vet[mid] == x)
	{
		flag += 1;
		printf("%d ", mid);
		return;
	}
	if(vet[fin] == x)
	{
		flag += 1;
		printf("%d ", fin);
		return;
	}
	
	//se chegamos ao fim do vetor, e não encontramos x
	if(in == fin)
		return;

	//do contrário, ainda estamos procurando

	//se o número é menor do que a posição atual
	if(x < vet[mid])
	{
		//buscamos na metade posterior do vetor
		busca_decrescente(vet, mid, fin, x);
		return;
	}
	//se o número é maior do que a piosição atual
	
	//buscamos na metade anterior do vetor
	busca_decrescente(vet, in, mid, x);
	return;
}

int main(){
	int N, M;
	int i, x;
	
	scanf("%d", &N);
	int vet[N];
	
	for(i = 0; i<N; i++)
		scanf("%d", &vet[i]);
	
	scanf("%d", &M);
	
	for(i = 0; i<M; i++)
	{
		scanf("%d", &x);
		flag = 0;
		busca_crescente(vet, 0, N/2, x);
		if(flag == 0)
			busca_decrescente(vet, (N/2)+1, N-1, x);
		if(flag == 0)
			printf("-1 ");
	}

	return 0;
}
