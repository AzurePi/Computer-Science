#include <stdio.h>

int main()
{
	int N, res[10];
	
	printf("Digite um número: ");
	scanf("%d", &N);
	
	for(int i=0; i<10; i++){
		res[i] = (i+1)*N;
		printf("\n%d X %d = %d", N, i+1, res[i]);
	}
	return 0;
}