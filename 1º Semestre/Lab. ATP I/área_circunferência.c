#include <stdio.h>

int main() {
	float radius, area, pi;
	pi = 3.14159265359;
	
	printf("Qual é o raio da circunferência?\n");
	scanf("%f", &radius);
	area = 2*radius*pi;
	printf("A área da circunferência é %f", area);
	
	return 0;
}
