#include <stdio.h>

void hanoi(){




}

int main(){
	int N, K;
	int **torre;
	int i;
	
	scanf("%d %d", &N, &K);

	torre = malloc(sizeof(int)*3);
	for(i = 0; i<3; i++)
		torre[i] = malloc(sizeof(int)*N);






	return 0;
}
