#include <stdio.h>
#include <math.h>

int main(){
	int N, M;
	int op;
	float dist;
	int i, j = 0;
	char nom[21], p1[21], p2[21];
	int x1, x2, y1, y2, z1, z2;

	scanf("%d%d", &N, &M);

	struct p{
		char nome[21];
		float peso;
		int x, y, z;
	}planetas[N];
	
	for(i=0; i<N; i++)
		scanf("%s %f %d %d %d", planetas[i].nome, &planetas[i].peso, &planetas[i].x, &planetas[i].y, &planetas[i].z);
	
	for(i=0; i<M; i++)
	{	scanf("%d", &op);
		
		switch(op)
		{	case 1:	scanf("%s %s", p1, p2);
				do{
					if(planetas[j].nome == p1)
					{	x1 = planetas[j].x;
						y1 = planetas[j].y;
						z1 = planetas[j].z;
					}
					j++;
				}while();
				j = 0;
				do{
					if(planetas[j].nome == p2)
					{	x2 = planetas[j].x;
						y2 = planetas[j].y;
						z2 = planetas[j].z;
					}
				}while();
				j = 0;
				dist = sqrt();
				break;
			case 2:	scanf("%s", nom);
				do{
					if(planetas[j].nome == nome)
						printf("%d %d %d\n", planetas[j].x, planetas[j].y, planetas[j].z);
					j++;
				}while(planetas[j].nome != nom);
				j = 0; break;
			case 3: scanf("%s", nom);
				do{
					if(planetas[j].nome == nom)
						printf("%f\n", planetas[j].peso);
					j++;
				}while(planetas[j].nome != nom);
				j = 0; break;
		}
	}



	return 0;
}
