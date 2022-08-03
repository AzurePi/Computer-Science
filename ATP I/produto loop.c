#include <stdio.h>

int main()
{
	int cod, i;

for (i=0; i<10; i++) {
	printf("Qual o código do produto?\n");
	scanf("%d", &cod);
	
	switch(cod){
		case 1: printf("Esse produto procede do Sul"); break;
		case 2: printf("Esse produto procede do Norte"); break;
		case 3: printf("Esse produto procede do Leste"); break;
		case 4: printf("Esse produto procede do Oeste"); break;
		case 5:
		case 6:
		case 12:
		case 13:
		case 14:
		case 15: printf("Esse produto procede do Nordeste"); break;
		case 10:
		case 11: printf("Esse produto procede do Centro-Oeste"); break;
		default: printf("Esse produto é importado"); break;
	}
	printf("\n\n");
}

  return 0;
}
