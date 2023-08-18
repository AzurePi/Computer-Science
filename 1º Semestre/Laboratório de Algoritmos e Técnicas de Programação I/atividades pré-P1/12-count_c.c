#include <stdio.h>

int main(){
	char string[31], c;
	int q = 0;

	printf("Digite uma frase: ");
	scanf("%[^\n]s", string);
	
	printf("Escolha uma letra: ");
	scanf("%c", &c);
	
	for(int i = 0; i<30; i++){
		if(string[i] == c){
			q++;
		}
	}
	
	printf("\nA letra %c foi digitada %d vezes", c, q);
	
	return 0;
}
