#include <stdio.h>

int main(){
    //declaração de variáveis
    float P1, P2, T, MF;
    int F;

    //atribuição de valor às variáveis pelo usuário
    printf("Qual a nota na P1?\n");
    scanf("%f", &P1);

    printf("Qual a nota na P2?\n");
    scanf("%f", &P2);

    printf("Qual a nota T?\n");
    scanf("%f", &T);

    printf("Qual o total de faltas?\n");
    scanf("%d", &F);

    //cálculo da média
    MF = (P1 + P2 + T)/3;

    //checagem da condição do aluno
    if (MF >= 5 && F <=9){
        printf("\nO aluno está aprovado com média %.2f e %d faltas\n", MF, F);
    } else {
        printf("\nO aluno está reprovado\n");
    }

    return 0;
}