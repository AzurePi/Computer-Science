#include <stdio.h>

void hanoi(int **torre, int mov, int org, int io, int aux, int ia, int dest, int id){
	if(mov != 0) //se há movimentos a fazer
	{
		if(torre[org][io] != 0 && torre[dest][id] = 0)
		{
			torre[aux][ia] = torre[org][ia];
			torre[org][io] =  0;
			mov--;
			or = aux;
			aux = 
			hanoi(torre, mov, );
		}
	}
}

int main(){
	int N, K;
	int **torre;
	int i;
	
	scanf("%d %d", &N, &K);

	//aloca dinamicamente o espaço da torre
	torre = malloc(sizeof(int)*3);
	for(i = 0; i<3; i++)
		torre[i] = malloc(sizeof(int)*N);

	//determina que os discos estão todos no primeiro pino
	for(i = 0; i<N; j++)
	{
		torre[0][i] = i+1;
		torre[1][i] = 0;
		torre[2][i] = 0;
	}

	hanoi(torre, K, 0, 0, 1, 0, 2, 0); //executa k movimentos na torre
	
	//imprimindo a torre
	for(i = 0; i<3; i++)
	{
		j = 0;
		do{
			printf("%d ", torre[i][j]);
			j++;
		}
		while(torre[i][j]); //se a torre está vazia, imprime 0 apenas uma vez
		printf("\n");
	}
		
	//libera o espaço alocado para a torre
	for(i = 0; i<3; i++)
		free(torre[i]);
	free(torre);

	return 0;
}
