#include <stdio.h>
#include <stdlib.h>

void hanoi(int **torre, int mov, int org, int io, int aux, int ia, int dest, int id){
	if(mov != 0) //se há movimentos a fazer
	{
		torre[aux][ia] = torre[org][ia]; //move da origem para o auxiliar
		torre[org][io] =  0; //seta a origem como vazia
		mov--;
		org = aux; //o pino auxiliar é a nova origem
		aux = dest; //o pino destino é o novo auxiliar
		hanoi(torre, mov, org, io+1, aux, ia+1, dest, id+1);
	}
}

int main(){
	int N, K;
	int **torre;
	int i, j;
	
	scanf("%d %d", &N, &K);

	//aloca dinamicamente o espaço da torre
	torre = malloc(sizeof(int)*3);
	for(i = 0; i<3; i++)
		torre[i] = malloc(sizeof(int)*N);

	//determina que os discos estão todos no primeiro pino
	for(j = 0; j<N; j++)
	{
		torre[0][j] = j+1;
		torre[1][j] = 0;
		torre[2][j] = 0;
	}

	hanoi(torre, K, 0, 0, 1, 0, 2, 0); //executa k movimentos na torre
	
	//imprimindo a torre
	for(i = 0; i<3; i++)
	{
		for(j = 0; j<N; j++)
    {
        if(torre[i][j] != 0)
          printf("%d ", torre[i][j]);
    }
    if(torre[i][j] == 0)
        printf("0");
		printf("\n");
	}
		
	//libera o espaço alocado para a torre
	for(i = 0; i<3; i++)
		free(torre[i]);
	free(torre);

	return 0;
}
