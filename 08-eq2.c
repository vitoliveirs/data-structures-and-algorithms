#include <stdio.h>
#include <math.h>

int main(){

    int A, B, C;

    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);

    int x = (B*B) - (4*A*C);
    double resultadoPositivo = (-B + sqrt(x))/2*A;
    double resultadoNegativo = (-B - sqrt(x))/2*A;

    printf("%.4lf %.4lf", resultadoPositivo, resultadoNegativo);

    return 0;
}