#include <stdio.h>
#include <locale.h>

int main(){
	int dia = 0, mes = 0, ano;
	setlocale(LC_ALL, "Portuguese");
		
	do{
	printf("Digite uma data no formato DD/MM/AAAA\n");
	scanf("%d/%d/%d", &dia, &mes, &ano);
	}while(dia>31 || dia<=0 || mes>12 || mes<=0);
	
	switch(mes){
		case 1: printf("\n%d de janeiro de %d", dia, ano); break;
		case 2: printf("\n%d de fevereiro de %d", dia, ano); break;
		case 3: printf("\n%d de março de %d", dia, ano); break;
		case 4: printf("\n%d de abril de %d", dia, ano); break;
		case 5: printf("\n%d de maio de %d", dia, ano); break;
		case 6: printf("\n%d de junho de %d", dia, ano); break;
		case 7: printf("\n%d de julho de %d", dia, ano); break;
		case 8: printf("\n%d de agosto de %d", dia, ano); break;
		case 9: printf("\n%d de setembro de %d", dia, ano); break;
		case 10: printf("\n%d de outubro de %d", dia, ano); break;
		case 11: printf("\n%d de novembro de %d", dia, ano); break;
		case 12: printf("\n%d de dezembro de %d", dia, ano); break;
	}	
	
	return 0;
}
