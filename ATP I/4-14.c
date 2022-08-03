#include <stdio.h>
#include <locale.h>



int main(){
	int v, T1 = 0, T2 = 0, T3 = 0, T4 = 0, Tn = 0, Tb = 0, T = 0;
	float percent;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Votação iniciada\n\n");
	printf("<1> Candidato 1\n");
	printf("<2> Candidato 2\n");
	printf("<3> Candidato 3\n");
	printf("<4> Candidato 5\n");
	printf("<5> Voto Nulo\n");
	printf("<6> Voto em Branco\n");
	printf("\n<0> Encerrar Votação\n\n");
	
	do{
		scanf("%d", &v);
		switch(v){
			case 1: T1++; break;
			case 2: T2++; break;
			case 3: T3++; break;
			case 4: T4++; break;
			case 5: Tn++; break;
			case 6: Tb++; break;
			default: T = T; break;
		}
		
	} while(v!=0);
	
	T = T1 + T2 + T3 + T4 + Tn + Tb;
	if(T!=0){
		percent = 100.0 * (Tn + Tb)/T;
	} else {
		percent = 0;
	}
	
	
	printf("------------------\n");
	printf("Candidado 1: %d votos\n", T1);
	printf("Candidado 2: %d votos\n", T2);
	printf("Candidado 3: %d votos\n", T3);
	printf("Candidado 4: %d votos\n", T4);
	printf("%d votos nulos\n", Tn);
	printf("%d votos em branco\n", Tb);
	printf("%.2f%% dos votos foram brancos ou nulos\n", percent);


	return 0;
}
