#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(){
	//variáveis
	char str1[101], str2[101], c;
	int i, vog=0;
	
	//define a lingua como portugês
	setlocale(LC_ALL, "Portuguese");
	
	//recebe duas frase do usuário
	printf("Digite duas frases:\n");
	gets(str1); fflush(stdin);
	gets(str2); fflush(stdin);
	
	printf("\n--------------------\n");
	
	//item a) define oi tamanho das strings
	printf("Tamanho da frase 1: %d", strlen(str1));
	printf("\nTamanho da frase 2: %d", strlen(str2));
	
	printf("\n\n");
	
	//item b) concatena as strings
	strcat(str1, str2);
	printf("Essas frases concatenadas são: %s", str1);
	
	//item c) calcula o número de vogais na string concatenada
	for(i=0; i<strlen(str1); i++){
		c = str1[i];
		c = tolower(c); //converte a letra para sua versão minúscula
		if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
			vog++;
		}
	}
	printf("\nVogais na frase concatenada: %d", vog);
	
	return 0;
}
