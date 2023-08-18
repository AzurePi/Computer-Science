#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char nome[81], nomemaiusculo[81];
	
	printf("Nome: ");
	scanf("%[^\n]s", nome);
	
	for(int i = 0; i<80; i++){
		nomemaiusculo[i] = toupper(nome[i]);
	}
	
	printf("Nome Maiúsculo: %s", nomemaiusculo);
	
	return 0;
}
