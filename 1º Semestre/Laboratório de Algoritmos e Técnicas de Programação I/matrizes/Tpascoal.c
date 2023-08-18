#include <stdio.h>
#include <locale.h>

int main(){
  int N, i, j;
  
  setlocale(LC_ALL, "Portuguese");
	
  
  printf("Até que linha construir o triângulo? ");
  scanf("%d", &N);

  int pas[N+1][N+1];

  for(i=0; i<=N; i++){
    for(j=0; j<=N; j++){
      if(j==i || j==0){
        pas[i][j] = 1;
      }else{
        pas[i][j] = pas[i-1][j] + pas[i-1][j-1];
      }
    }
  }

  printf("\n");

  for(i=0; i<=N; i++){
    for(j=0; j<=N; j++){
      if(j<=i){
        printf("%d ", pas[i][j]);
      }
    }
    printf("\n");
  }
    
  return 0;
}
