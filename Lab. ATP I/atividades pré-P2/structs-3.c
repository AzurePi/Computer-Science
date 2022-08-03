#include <stdio.h>

typedef struct data{
	int dia, mes, ano;
} data;

int main() {
	data D;
	char meses[12][20] = {{"janeiro"},{"fevereiro"},{"março"},{"abril"},{"maio"},{"junho"},{"julho"},{"agosto"},{"setembro"},{"outubro"},{"novembro"}, {"dezembro"}};
	
	do{
	printf("Dia: ");
	scanf("%d", &D.dia);
	printf("Mês: ");
	scanf("%d", &D.mes);
	printf("Ano: ");
	scanf("%d", &D.ano);
	
	if(D.dia<0 || D.dia>31 || D.mes<0 || D.mes>12 || D.ano<0){
		printf("Data inválida, repita o procedimento\n\n");
	}
	
	}while(D.dia<0 || D.dia>31 || D.mes<0 || D.mes>12 || D.ano<0);
	
	printf("\n%d/%s/%d", D.dia, meses[D.mes-1], D.ano);

	return 0;
}
