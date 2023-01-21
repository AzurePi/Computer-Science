#include <stdio.h>
#include <time.h>

#define n 200000

typedef struct biggo {
	int high;
	int low;
} BigInt;

void ler(BigInt *vet);
void imprimir(BigInt *vet);
void insertion(BigInt *vet);

int main(){
	BigInt vet[n];
	time_t begin, end;
	double t;
	
	ler(vet); //l� dados de bigint.dat e armazena num vetor
	
	begin = clock(); //marca o instante em que o sorting come�a
	insertion(vet);
	end = clock(); //marca o instante em que o sorting termina
	
	t = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%lf", t); //imprime na tela o tempo tomado pela ordena��o
	
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

void insertion(BigInt *vet){
	int i, j;
	BigInt x;
	
	//come�ando a partir do segundo elemento do vetor, e passando por todos
	for(i = 1; i<n; i++)
	{
		//armazena o n�mero sendo inserido
		x.high = vet[i].high;
		x.low = vet[i].low;
		
		//come�a a an�lise pela posi��o imediatamente anterior
		j = i - 1;
		
		//tenta ordenar pelo componente high
		if(x.high != vet[j].high)
		{
			//procura, nas posi��es anteriores, onde inserir x
			while(x.high < vet[j].high && j >= 0)
			{
				vet[j+1].high = vet[j].high;
				vet[j+1].low = vet[j].low;
				vet[j].high = x.high;
				vet[j].low = x.low;
				j--; //vai para a posi��o anterior
			}
		}else //ordena por low
		{
			/*
				Se x.high e vet[j].high s�o negativos, a compara��o da ordena��o se inverte para os componentes low
				Se x.hig e vet[j].high s�o positivos, a compara��o da ordena��o ocorre normalmente
			*/
			while(((x.high < 0 && vet[j].high < 0 && x.low > vet[j].low) || (x.high > 0 && vet[j].high > 0 && x.low < vet[j].low)) && j >= 0)
			{
				vet[j+1].high = vet[j].high;
				vet[j+1].low = vet[j].low;
				vet[j].high = x.high;
				vet[j].low = x.low;
				j--; //vai para a posi��o anterior
			}
		}
	}
}

