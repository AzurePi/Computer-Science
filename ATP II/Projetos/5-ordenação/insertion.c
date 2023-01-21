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
	
	ler(vet); //lê dados de um arquivo bigint.dat e armazena num vetor
	
	begin = clock(); //marcamos o instante em que o sorting começa
	insertion(vet);
	end = clock(); //marcamos o instante em que o sorting termina
	
	imprimir(vet); //imprime o vetor já ordenado no arquivo quick.dat
	
	printf("%lf" , end - begin); //imprime na tela o tempo tomado pela ordneação
	
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
			while(x.high < vet[j].high)
			{
				vet[i].high = vet[j].high;
				vet[i].low = vet[j].low;
				vet[j].high = x.high;
				vet[j].low = x.low;
				j--; //vai para a posição anterior
			}
		}else //ordena por low
		{
			/* Casos em que "andamos" na ordenação:
				Se x.high e vet[j].high são negativos, a lógica da comparação se inverte para os componentes low
				Se x.high é negativo, e vet[j].high é positivo, x é menor que vet[j]
				Se x.high é positivo, e vet[j].high é negativo, x é maior que vet[j]
			*/
			while((x.high < 0 && vet[j].high < 0 && x.low > vet[j].low) || (x.high < 0 && vet[j].high > 0) || (x.high > 0 && vet[j].high < 0))
			{
				vet[i].high = vet[j].high;
				vet[i].low = vet[j].low;
				vet[j].high = x.high;
				vet[j].low = x.low;
				j--; //vai para a posição anterior
			}
		}
	}
}
