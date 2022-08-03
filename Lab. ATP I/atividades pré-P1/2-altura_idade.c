#include <stdio.h>
#define n 50

int main(){
	int idade[n], qmenor = 0, qvelho = 0, Imax, Imin;
	float altura[n], Imedia = 0, Amedia = 0;

	for(int i = 0; i<n; i++){
		printf("Idade %d: ", i);
		scanf("%d", &idade[i]);
		printf("Altura %d: ", i);
		scanf("%f", &altura[i]);
		printf("\n");
		
		//a
		if(altura[i]<1.7){
			Imedia += idade[i];
		}
		//b
		if(idade[i]>20){
			Amedia += altura[i];
		}
		
		if(i==0){
			Imax = 0;
			Imin = 0;
		}else {
			//c
			if(idade[i]>Imax){
			Imax = idade[i];
			}
			//d
			if(idade[i]<Imin){
			Imin = idade[i];
			}
		}
	}
	
	Imedia /= n;
	Amedia /= n;
	
	printf("Idade média dos alunos com menos de 1.70m de altura: %.2f anos\n", Imedia);
	printf("Altura média dos alunos com mais de 20 anos: %.2fm\n", Amedia);
	printf("Idade do aluno mais velho: %d\n", Imax);
	printf("Idade do aluno mais novo: %d", Imin);

	return 0;
}
