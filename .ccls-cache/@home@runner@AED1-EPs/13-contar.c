#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, vetor[1000], maior, x=0;

    scanf("%d", &n);
    scanf("%d", vetor);
    scanf("%d", &maior);


    for (int i = 0; i <= n; i++){
        if (vetor[i] >= maior){
            x++;
        }
    }

    printf("%d", x);

    return 0;
}