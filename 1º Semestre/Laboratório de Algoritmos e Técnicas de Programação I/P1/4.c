#include <stdio.h>

int main(){
	int val, quant[5];
	
	printf("Valor a ser impresso: ");
	scanf("%d", &val);
	
	printf("\nSão precisas:\n");
	
	//quantidade de notas de 500
	quant[0] = val / 500;
	val -= quant[0]*500;
	printf("%d nota(s) de 500 euros\n", quant[0]);
	
	//quantidade de notas de 200
	quant[1] = val / 200;
	val -= quant[1]*200;
	printf("%d nota(s) de 200 euros\n", quant[1]);
	
	//quantidade de notas de 50
	quant[2] = val / 50;
	val -= quant[2]*50;
	printf("%d nota(s) de 50 euros\n", quant[2]);
	
	//quantidade de notas de 10
	quant[3] = val / 10;
	val -= quant[3]*10;
	printf("%d nota(s) de 10 euros\n", quant[3]);
	
	//quantidade de moedas de 1
	quant[4] = val / 1;
	printf("%d moeda(s) de 1 euros\n", quant[4]);
	
	return 0;
}
