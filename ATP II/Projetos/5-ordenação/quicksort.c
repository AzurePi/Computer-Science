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
int mediana(BigInt *v, int in, int mid, int fin);
void quicksort(BigInt *vet, int in, int fin);

int main(){
	BigInt vet[n];
	time_t begin, end;
	double t;
	
	ler(vet); //lê dados de bigint.dat e armazena num vetor
	
	begin = clock(); //marca o instante em que o sorting começa
	quicksort(vet, 0, n);
	end = clock(); //marca o instante em que o sorting termina
	
	t = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%lf" , t); //imprime na tela o tempo tomado pela ordneação
	
	imprimir(vet); //imprime o vetor no arquivo quick.dat
	
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
		//se ambos são positivos, comparamos o componente low
		if(vet[i].high >= 0 && vet[j].high >= 0)
		{
			if(vet[i].low >= vet[j].low)
				return 1;
			//do contrário
			return 0;
		}
		//se ambos são negativos
		//invertemos a lógica de ser maior ou menor para low
		if(vet[i].low < vet[j].low)
			return 1;
		//do contrário
		return 0;
	}
}

//retorna o índice da mediana entre três valores nas posições in, mid e fin de um vetor v
int mediana(BigInt *v, int in, int mid, int fin){
	
	if(maior_que(v, in, mid))
	{
		if(maior_que(v, mid, fin))
			return mid;
		if(maior_que(v, fin, in))
			return in;
	}else if(maior_que(v, mid, in))
	{
		if(maior_que(v, in, fin))
			return in;
		if(maior_que(v, fin, mid))
			return mid;
	}else
		return fin;
}

void quicksort(BigInt *vet, int in, int fin){
	int pivot, j; //indices do pivot e do número sendo analisado
	int i;
	BigInt aux;

	//se o inicio ainda está antes do fim
	if(in < fin)
	{
		//determina o índice do pivot pelo método da mediana de três
		pivot = mediana(vet, in, (in+fin)/2, fin);
		
		//colocamos o pivot na última posição do vetor
		aux.high = vet[fin].high;
		aux.low = vet[fin].low;
		vet[fin].high = vet[pivot].high;
		vet[fin].low = vet[pivot].low;
		vet[pivot].high = aux.high;
		vet[pivot].low = aux.low;
		
		//posição em que começaremos a ordenar os números
		j = in; 
		
		for(i = j; i < fin; i++)
		{
			//se o número sendo analisado é menor do que o pivot
			if(!maior_que(vet, i, fin))
			{
				//colocamos esse número na posição de ordenação
				aux.high = vet[j].high;
				aux.low = vet[j].low;
				vet[j].high = vet[i].high;
				vet[j].low = vet[i].low;
				vet[i].high = aux.high;
				vet[i].low = aux.low;
				
				j++; //passamos para a próxima posição na ordenação
			}
		}
	}

	/*
		Colocamos o pivot no "meio" do vetor de forma 
		que à sua esquerda estejam os valore menores, 
		e à direita of valores maiores
	*/
	aux.high = vet[j].high;
	aux.low = vet[j].low;
	vet[fin].high = vet[pivot].high;
	vet[fin].low = vet[pivot].low;
	vet[pivot].high = aux.high;
	vet[pivot].low = aux.low;

	//utilizamos quicksort para cada "metade" do vetor
	quicksort(vet, in, j-1);
	quicksort(vet, j+1, fin);
}
