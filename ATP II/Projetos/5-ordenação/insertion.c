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

void insertion(BigInt *vet){
	int i, j;
	BigInt x;
	
	//começando a partir do segundo elemento do vetor, e passando por todos
	for(i = 1; i<n; i++)
	{
		//armazena o número sendo inserido
		x.high = vet[i].high;
		x.low = vet[i].low;
		
		//começa a análise pela posição imediatamente anterior
		j = i - 1;
		
		//tenta ordenar pelo componente high
		if(x.high != vet[j].high)
		{
			//procura, nas posições anteriores, onde inserir x
			while(x.high < vet[j].high && j >= 0)
			{
				vet[j+1].high = vet[j].high;
				vet[j+1].low = vet[j].low;
				vet[j].high = x.high;
				vet[j].low = x.low;
				j--; //vai para a posição anterior
			}
		}else //ordena por low
		{
			/*
				Se x.high e vet[j].high são negativos, a comparação da ordenação se inverte para os componentes low
				Se x.hig e vet[j].high são positivos, a comparação da ordenação ocorre normalmente
			*/
			while(((x.high < 0 && vet[j].high < 0 && x.low > vet[j].low) || (x.high > 0 && vet[j].high > 0 && x.low < vet[j].low)) && j >= 0)
			{
				vet[j+1].high = vet[j].high;
				vet[j+1].low = vet[j].low;
				vet[j].high = x.high;
				vet[j].low = x.low;
				j--; //vai para a posição anterior
			}
		}
	}
}
