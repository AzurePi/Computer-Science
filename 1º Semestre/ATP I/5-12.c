#include <stdio.h>

int main()
{
	int VIN[10], VAI[30], i, aux = 0;
	
	printf("Escreva dez numeros inteiros:\n");
	for(i=0; i<10; i++){
		scanf("%d", &VIN[i]);
		VAI[aux] = VIN[i]; aux++;
		VAI[aux] = VIN[i]; aux++;
		VAI[aux] = VIN[i]; aux++;
	}
	
	printf("\n\n");
	
	for(i=0; i<30; i++){
		printf("%d\n", VAI[i]);
	}
	
	return 0;
}