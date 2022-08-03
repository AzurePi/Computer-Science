#include <stdio.h>
#include <math.h>

int main() {
    //declaração de variáveis
    float a, b, c, x1, x2, delta;

    //atribuição de valores pelo usuário
    printf("Quais os parâmetros a, b e c?\n");
    scanf("%f %f %f", &a, &b, &c);

    //cálculo de delta
    delta = b*b - 4*a*c;

    //fórmula de bhaskara
    if (delta > 0) {
        x1 = (-b + sqrt(delta))/(2*a);
        x2 = (-b - sqrt(delta))/(2*a);
        printf("As raízes reais dessa equação são %f e %f", x1, x2);
    } else if (delta == 0) {
        x1 = -b / (2*a);
        printf("A raíz real única dessa equação é %f", x1);
    } else {
        printf("A equação não possui raízes reais");
    }

    return 0;
}