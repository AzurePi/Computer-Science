#include <stdio.h>
#include <string.h>


//verifica se pal de tamanho k é ou não palíndromo
int palindromo(char *pal, int k){
	int i;
	
	for(i = 0; i<k/2; i++) //verifica cada par inicio-fim de letras
	{
		if(pal[i] != pal[k-1-i])
			return 0; //se em algum momento as letras divergirem, retorna que não é palíndromo
	}
	
	return 1; //é palíndromo
}

//determina o tamanho do maior pelindromeio em ent de tamanho k
int palindromeio(char *ent, int k){
	
	
	

}


int main(){
	char ent[2001];
	int k, i;
	int res;
	
	scanf("%s", ent); //lê a palavra na linha
	k = strlen(ent);
	
	printf("%d", palindromeio());

	return 0;
}
