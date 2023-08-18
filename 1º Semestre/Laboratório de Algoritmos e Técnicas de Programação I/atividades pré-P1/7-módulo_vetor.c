#include <stdio.h>
#include <math.h>

int main(){
	float u[2], v[2], modU, modV;
	
	for(int i = 0; i<2; i++){
		printf("u[%d] = ", i);
		scanf("%f", &u[i]);
	}
	
	printf("\n");
	
	for(int i = 0; i<2; i++){
		printf("v[%d] = ", i);
		scanf("%f", &v[i]);
	}
	
	modU = sqrt(u[0]*u[0] + u[1]*u[1]);
	modV = sqrt(v[0]*v[0] + v[1]*v[1]);

  	printf("\n\n");
  
	printf("|u| = %f\n", modU);
	printf("|v| = %f", modV);


	return 0;
}
