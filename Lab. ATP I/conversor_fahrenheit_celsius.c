#include <stdio.h>

int main() {
	float tempF, tempC;
	
	printf("Qual a temperatura em Fahrenheit?\n");
	scanf("%f", &tempF);
	
	tempC = (5*(tempF-32))/9;
	printf("A temperatura é de %f graus celsius\n", tempC);
	
	return 0;
}
