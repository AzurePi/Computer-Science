#include <stdio.h>

int main() {
	int cod;
	char cond;
	
	while (cond == "s") {
		printf("Qual o c�digo do produto?\n");
		scanf("%d", &cod);
		
		switch(cod) {
			case 1: printf("Alimento n�o perec�vel"); break;
			case 2:
			case 3:
			case 4: printf("Alimento perec�vel"); break;
			case 5:
			case 6: printf("Vestu�rio"); break;
			case 7: prntf("Higiene pessoal"); break;
			case 8:
			case 9:
			case 10:
			case 11:
			case 12:
			case 13: printf("Limpeza e utens�lios dom�sticos"); break;
			default: printf("Inv�lido"); break;
		}
		
		printf("Deseja cinserir outro c�digo? s/n\n");
		scanf("%c", &cond);
	}	
	
	return 0;
}
