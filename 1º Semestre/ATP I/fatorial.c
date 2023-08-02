#include <stdio.h>

int main()
{
	int num, fact=1;

	printf("Digite um número inteiro: ");
	scanf("%d", &num);

	if(num!=0) {
		while(num>0){
			fact *= num;
			num--;
			}
		}
	printf("\nO fatorial desse número é %d", fact);

	return 0;
}

