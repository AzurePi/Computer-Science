#include <stdio.h>

int main(){
	char cpf[21], cpfformatado[21];
	
	printf("Digite um CPF (apenas números): ");
	scanf("%s", cpf);
	
	for(int i = 0; i<21; i++){
		if(i == 3 || i == 7){
			cpfformatado[i] = '.';
		}else if(i == 11){
			cpfformatado[i]  = '-';
		}else{
			if(i<3){
				cpfformatado[i] = cpf [i];
			}
			if(i>3 && i<7){
				cpfformatado[i] = cpf[i-1];
			}
			if(i>7 && i<11){
				cpfformatado[i] = cpf[i-2];
			}
			if(i>11){
				cpfformatado[i] = cpf[i-3];
			}
		}
	}

	printf("CPF formatado: %s", cpfformatado);

	return 0;
}
