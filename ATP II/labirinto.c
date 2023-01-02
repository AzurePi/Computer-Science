#include <stdio.h>
#include <stdlib.h>

int **labirinto;
int sol = 0; //assume que não há solução

void ler_labirinto(int N);
void caminhar(int N, int C, int x, int y, int p);

int main(){
	int N, I, C;
	
	scanf("%d %d %d", &N, &I, &C);
	
	ler_labirinto(N);
	caminhar(N, C, 0, I, 0);
	
	if(sol == 0)
		printf("-1\n");

	return 0;
}

void ler_labirinto(int N){
	int i, j;
	
	labirinto = malloc(N * sizeof(int *));
	
	for(i = 0; i<N; i++)
		labirinto[i] = malloc(sizeof(int));
		
	for(i = 0; i<N; i++)
	{
		for(j = 0; j<N; j++)
			scanf("%d", &labirinto[i][j]);
	}
	
	return;
}

void caminhar(int N, int C, int x, int y, int p){

	//se chegamos ao final
	if(x == N-1 && y == C && labirinto[x][y] == 0)
	{
		printf("%d\n", p);
		sol = 1; //indica que encontramos uma solução
		return;
	}
	
	//se não extrapolamos a borda
	if(x < N && y < N && x >= 0 && y >= 0 && sol == 0)
	{
		//e o caminho está livre
		if(labirinto[x][y] == 0)
		{
			labirinto[x][y] = 1;
			
			caminhar(N, C, x+1, y, p+1);
			caminhar(N, C, x, y+1, p+1);
			caminhar(N, C, x, y-1, p+1);
		}
	}

	return;
}
