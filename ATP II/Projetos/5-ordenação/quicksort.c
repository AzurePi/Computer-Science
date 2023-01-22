#include <stdio.h>
#include <time.h>

#define n 200000

typedef struct biggo {
	int high;
	int low;
} BigInt;

void ler(BigInt *vet);
void imprimir(BigInt *vet);
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

//retorna o índice da mediana entre três valores nas posições in, mid e fin de um vetor v
int mediana(int *v, int in, int mid, int fin){
	
	if(v[in] < v[mid])
	{
		if(v[mid] < v[fin])
			return mid;
		if(v[fin] < v[mid])
			return fin;
	}else if(v[mid] < v[in])
	{
		if(v[in] < v[fin])
			return in;
		if(v[fin] < v[in])
			return fin;
	}else //if(v[fin] < v[mid]
	{
		if(v[mid] < v[in])
			return mid;
		if(v[in] < v[mid])
			return in;
	}
}

void quicksort(BigInt *vet, int in, int fin){
	int pivot, j; //indices do pivot e do número sendo analisado
	int i
	BigInt aux;

	//se o inicio ainda está antes do fim
	if(in < fin)
	{
		//determina o índice do pivot pelo método da mediana de três
		pivot = mediana(vet, in, (in+fin)/2, fin);
		
		//colocamos o pivot na última posição do vetor
		aux.high = vet[fin].high;
		aux.low = vet.[fin].low;
		vet[fin].high = vet[pivot].high;
		vet[fin].low = vet[pivot].low;
		vet[pivot].high = aux.high;
		vet[pivot].low = aux.low;
		
		//posição em que começaremos a ordenar os números
		j = in; 
		
		for(i = j; i < fin; i++)
		{
			//se o número sendo analisado é menor do que o pivot
			if(vet[i] < vet[fin])
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
