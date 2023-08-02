#include <stdio.h>

int main()
{
	char str[100], c;
	int indice, i = 0, j, p;

	printf("Digite uma palavra: ");
	scanf("%s", &str);

	while (c != "\0")
	{
		c = str[i];
		i++;
	}
	indice = i - 1;

	for (j = 0; j <= indice; j++)
	{
		if (str[j] == str[indice - j])
		{
			p = 1;
		}
		else
		{
			p = 0;
			j = indice;
		}
	}

	if (p == 1)
	{
		printf("\nEssa palavra é um palíndromo!");
	}
	else
	{
		printf("\nEssa palavra não é um palíndromo");
	}

	return 0;
}