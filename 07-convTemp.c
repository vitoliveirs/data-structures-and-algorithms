#include <stdio.h>

int main(){
    int entrada, horas, minutos, segundos;

    scanf("%d", &entrada);

    if (entrada >= 60){

    horas = entrada/3600;
    minutos = (entrada - (horas*3600)) / 60;
    segundos = entrada%60;

    } else {
        horas = 0;
        minutos = 0;
        segundos = entrada;
    }

    printf("%d:%d:%d", horas, minutos, segundos);
    return 0;
}