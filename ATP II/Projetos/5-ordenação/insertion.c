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
	
	time(&begin); //marcamos o instante em que o sorting começa
	insertion(vet);
	time(&end); //marcamos o instante em que o sorting termina
	
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
		
		if(x.high != vet[j].high)
		{
			//procura, nas posições anteriores, onde inserir com base em high
			while(x.high < vet[j].high)
			{
				vet[i].high = vet[j].high;
				vet[i].low = vet[j].low;
				vet[j].high = x.high;
				vet[j].low = x.low;
				j--; //vai para a posição anterior
			}
		}else //x.high == vet[j].high
		{
			if(x.high < 0)
				x.low = x.low * -1; //marcamos, na variável auxiliar, que x é negativo

				//procura, nas posições anteriores, onde inserir com base em low
				while(x.low < vet[j].low)
				{
					vet[i].high = vet[j].high;
					vet[i].low = vet[j].low;
					vet[j].high = x.high;
					vet[j].low = x.low;
					j--; //vai para a posição anterior
				}
			}else if (x.high > 0 && vet[j].high < 0) //se x é positivo, mas vet[j] é negativo
			{
				//procura, nas posições anteriores, onde inserir com base em low
				while(x.low < vet[j].low)
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
}
