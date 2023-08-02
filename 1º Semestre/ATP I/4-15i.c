#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, L1, L2, L3;
	
	for(i = 0; i<7; i++){
		L1 = 1 + rand() % 6;
		L2 = 1 + rand() % 6;
		L3 = 1 + rand() % 6;
		
		printf("%d, %d e %d, resultando em %d\n", L1, L2, L3, L1+L2+L3);
	}
	
	return 0;
}
