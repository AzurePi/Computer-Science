#include <stdio.h>
#include <time.h>

#define n 200000

typedef struct biggo {
	int high;
	int low;
} BigInt;

void ler(BigInt *vet);
void imprimir(BigInt *vet);
int maior_que(BigInt *vet, int i, int j);
void troca(BigInt *v, int i, int j);
void insertion(BigInt *vet);

int main(){
	BigInt vet[n];
	time_t begin, end;
	double t;
	
	ler(vet); //lê dados de bigint.dat e armazena num vetor
	
	begin = clock(); //marca o instante em que o sorting começa
	insertion(vet);
	end = clock(); //marca o instante em que o sorting termina
	
	t = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%lf", t); //imprime na tela o tempo tomado pela ordenação
	
	imprimir(vet); //imprime o vetor ordenado no arquivo quick.dat
	
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

//verifica se vet[i] é maior ou igual a vet[j]
int maior_que(BigInt *vet, int i, int j){
	if(vet[i].high != vet[j].high)
	{
		if(vet[i].high >= vet[j].high)
			return 1;
		//do contrário
		return 0;
	}else //if vet[i].high == vet[j].high
	{
		//se ambos são positivos,
		if(vet[i].high >= 0 && vet[j].high >= 0)
		{
			//comparamos o componente low
			if(vet[i].low >= vet[j].low)
				return 1;

			return 0;
		}
		//se ambos são negativos,
		//invertemos a lógica de ser maior ou menor para low
		if(vet[i].low <= vet[j].low)
			return 1;

		return 0;
	}
}

//em um vetor v de BigInt, coloca v[i] na posição j, e v[j] na posição i
void troca(BigInt *v, int i, int j){
	BigInt aux;
	
	aux.high = v[j].high;
	aux.low = v[j].low;
	v[j].high = v[i].high;
	v[j].low = v[i].low;
	v[i].high = aux.high;
	v[i].low = aux.low;
}

void insertion(BigInt *vet){
	int i, j;
	
	//começando a partir do segundo elemento do vetor, e passando por todos
	for(i = 1; i<n; i++)
	{
		//começa a análise pela posição imediatamente anterior
		j = i - 1;
		
		//enquanto vet[j] é maior do que o número que estamos inserindo, e não 
		while(maior_que(vet, j, i) && j >= 0)
		{
			//colocamos o número em j na posição j+1
			troca(vet, j, j+1);
			j--; //vai para a posição anterior
		}
	}
}
