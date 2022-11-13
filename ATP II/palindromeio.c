#include <stdio.h>
#include <string.h>

int palindromo(char *pal, int inicio, int fim, int tam){
	if(inicio == fim)
		return tam;
	if(*pal[inicio] == *pal[fim]) //se o primeiro caractere é igual ao último
		tam++; //aumenta o tamanho do maior palíndromo
	palindromo(pal+1, inicio+1, fim-1, tam);
}




int main(){
	char ent[2001];
	int k, i;
	int res;
	
	scanf("%s", ent); //lê a palavra na linha
	k = strlen(ent);
	
	palindromo(ent, 0, k, 0);
	
	

	printf("%d", res);

	return 0;
}
