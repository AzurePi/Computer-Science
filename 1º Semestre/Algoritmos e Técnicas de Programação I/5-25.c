#include <stdio.h>

int main()
{
	int fib[15] = {1, 1};

	for (int i = 2; i < 15; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	printf("Sequência de Fibonacci\n\n");
	for (int i = 0; i < 15; i++)
	{
		printf("%d\n", fib[i]);
	}
	printf("...");
	return 0;
}