#include <stdio.h>

int main() {
  int M = 0, F = 0, S = 0, N = 0, FS = 0, MN = 0; 
  int i;
  float Mporcent, Fporcent;
  char sexo, resp;

  for(i = 0; i<10; i++)
    {
      scanf(" %c", &sexo);
      if(sexo == 'm')
        M++;
      else if(sexo == 'f')
        F++;

      scanf(" %c", &resp);
      if(resp == 's')
        S++;
      else if(resp == 'n')
        N++;

      if(sexo == 'm' && resp == 'n')
        MN++;

      if(sexo == 'f' && resp == 's')
        FS++;
    }
  printf("\n");
  printf("SIM: %d\n", S);
  printf("NÃO: %d\n", N);
  
  if(M != 0)
  	Mporcent = ((float)MN/M)*100;
  else
  	Mporcent = 0;

  if(F != 0)
  	Fporcent = ((float)FS/F)*100;
  else
  	Fporcent = 0;
  
  printf("Homens que responderam não: %.2f%%\n", Mporcent);
  printf("Mulheres que responderam sim: %.2f%%\n", Fporcent);
  
    return 0;
}
  
