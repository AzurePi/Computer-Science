// Shared via Compiler App https://g633x.app.goo.gl/TPlw
#include <stdio.h>

int main()
{
	int h_A, h_F, anos;

	h_A = 150;
	h_F = 110;
	anos = 0;

	while(h_F<=h_A){
		h_A += 2;
		h_F += 3;
		anos++;
		}

	printf("%d", anos);

	return 0;
}

