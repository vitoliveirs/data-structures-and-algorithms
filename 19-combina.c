#include <stdio.h>
#include <stdlib.h>

int *combina(int *v, int *w, int n, int m) {
    int *z = (int *)malloc(sizeof(int) * (n + m));
    int contador = 0;

    for (int i = 0; i < n; i++) {
        z[i] = v[i];
    }

    for (int i = m - 1; i >= 0; i--) {
        z[n + contador] = w[i];
        contador++;
    }

    return z;
}

int main() {
    int N, M;

    scanf("%d", &N);
    scanf("%d", &M);

    int V[N], W[M];

    for (int i = 0; i < N; i++) {
        scanf("%d", &V[i]);
    }

    for (int i = 0; i < M; i++) {
        scanf("%d", &W[i]);
    }

    int *resultado = combina(V, W, N, M);

    for (int i = 0; i < N + M; i++) {
        printf("%d ", resultado[i]);
    }

    free(resultado);

    return 0;
}
