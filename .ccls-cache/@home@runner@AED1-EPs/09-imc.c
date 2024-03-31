#include <stdio.h>

int main(){

    float A;
    float M;

    scanf("%f", &A);
    scanf("%f", &M);

    float IMC = M / (A * A);

    if (IMC < 16){
        printf("Magreza grave");
    } else if (IMC >= 16 && IMC < 17){
        printf("Magreza moderada");
    } else if (IMC >= 17 && IMC < 18.5){
        printf("Magreza leve");
    } else if (IMC >= 18.5 && IMC < 25){
        printf("Saudavel");
    } else if (IMC >= 25 && IMC < 30){
        printf("Sobrepeso");
    } else if (IMC >= 30 && IMC < 35){
        printf("Obesidade Grau I");
    } else if (IMC >= 35 && IMC < 40){
        printf("Obesidade Grau II (severa)");
    } else if (IMC >= 40){
        printf("Obesidade Grau III (morbida)");
    }

    return 0;
}