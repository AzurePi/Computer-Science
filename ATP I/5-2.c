#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define max 1000

int main()
{
	unsigned long int num[max], i, qntP=0, qntI=0, medP, medI, P=0, I=0;
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	for(i=0; i<max; i++){
		num[i] = rand();
	}
	
	for(i=0; i<max; i++){
		if (num[i] % 2 == 0){
			qntP++;
			P+= num[i];
		} else{
			qntI++;
			I+= num[i];
		}
	}
	
	medP = P / qntP;
	medI = I / qntI;
	
	printf("A média dos números pares é %d", medP);
	printf("\nHá %d números pares", qntP);
	printf("\nA média dos números ímpares é %d", medI);
	printf("\nHá %d números ímpares", qntI);
	
	
	return 0;
}