#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int f, f1, f2, f3, f4, f5, f6, i;
	srand(time(NULL));
	
	for(i=0; i<6000; i++){
		f = 1 + rand() % 6;
		
		switch(f){
			case 1: f1++; break;
			case 2: f2++; break;
			case 3: f3++; break;
			case 4: f4++; break;
			case 5: f5++; break;
			case 6: f6++; break;
			default: f = f; break;
		}
	}
	
	printf("A face 1 apareceu %d vezes\n", f1);
	printf("A face 2 apareceu %d vezes\n", f2);
	printf("A face 3 apareceu %d vezes\n", f3);
	printf("A face 4 apareceu %d vezes\n", f4);
	printf("A face 5 apareceu %d vezes\n", f5);
	printf("A face 6 apareceu %d vezes\n", f6);
	
	return 0;
}
