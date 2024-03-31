#include <stdio.h>

int main() {
    char SM;
    int x = 0, z = 1, N, A[100][100];

    scanf("%c", &SM);
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    if (SM == 'S') {
        for (int i = 1; i < N; i++) { 
            for (int j = 0; j < z; j++) { 
                x += A[i][j];
            }
            z++;
        }
        printf("%d", x); 
    }

    if (SM == 'M') {
        int contador = 0;
        float media = 0.0; 
        for (int i = 1; i < N; i++) { 
            for (int j = 0; j < z; j++) { 
                contador++;
                x += A[i][j];
            }
            z++;
        }
        media = (float)x / contador; 
        printf("%.1f", media); 
    }

    return 0;
}