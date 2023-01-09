#include <stdio.h>
#include <stdlib.h>

int **ler(int N){
	int i, j, **mat;
	
	mat = malloc(sizeof(int *));
	for(i = 0; i<N; i++)
		mat[i] = malloc(sizeof(int));
	
	for(i = 0; i<N; i++)
		for(j = 0; j<N; j++)
			scanf("%d", &mat[i][j]);
	
	return mat;
}

void minimos(int **mat, int N, int M){
	int i, j, k;
	int a, b, min;
	
	for(i = 0; i<M; i++)
	{
		scanf("%d %d", &a, &b);
		
		min = (2*N*N);
		for(j = a - 1; j<b; j++)
			for(k = a - 1; k<b; k++)
				if(mat[j][k] < min)
					min = mat[j][k];
		
		printf("%d\n", min);
	}
}

int main(){
	int N, M;
	int **matriz;
	scanf("%d %d", &N, &M);
	
	matriz = ler(N);
	minimos(matriz, N, M);
	
	return 0;
}
