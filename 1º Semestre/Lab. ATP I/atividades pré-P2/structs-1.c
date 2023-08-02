#include <stdio.h>
#include <stdlib.h>

//definição da struct "horamin"
typedef struct horamin{
	int horas;
	int minutos;
} horamin;

//programa principal
int main(){
	int temp;
	horamin resp;
	
	printf("Escreva um intervalo de tempo em minutos: ");
	scanf("%d", &temp);
	
	resp.horas = temp / 60;
	temp -= (temp / 60)*60;
	resp.minutos = temp;
	
	printf("\nEsse intervalo equivale a %d horas e %d minutos", resp.horas, resp.minutos);
	
	return 0;
}
