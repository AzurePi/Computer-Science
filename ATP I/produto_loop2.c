#include <stdio.h>

int main() {
	int cod;
	char cond;
	
	while (cond == "s") {
		printf("Qual o código do produto?\n");
		scanf("%d", &cod);
		
		switch(cod) {
			case 1: printf("Alimento não perecível"); break;
			case 2:
			case 3:
			case 4: printf("Alimento perecível"); break;
			case 5:
			case 6: printf("Vestuário"); break;
			case 7: prntf("Higiene pessoal"); break;
			case 8:
			case 9:
			case 10:
			case 11:
			case 12:
			case 13: printf("Limpeza e utensílios domésticos"); break;
			default: printf("Inválido"); break;
		}
		
		printf("Deseja cinserir outro código? s/n\n");
		scanf("%c", &cond);
	}	
	
	return 0;
}
