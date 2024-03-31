#include <stdio.h>

int main() {
    int N[10], chave;

    for (int i = 0; i < 10; i++) {
        scanf("%d", &N[i]);
    }

    if (N[0] < 0) {
        printf("nenhum numero informado");
        return 0;
    }

    chave = N[0];

    for (int i = 1; i < 10; i++) {
        if (N[i] < 0) break;
        if (N[i] < chave) {
            chave = N[i];
        }
    }

    printf("%d", chave);

    return 0;
}