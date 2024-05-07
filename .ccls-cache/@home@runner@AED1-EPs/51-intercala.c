#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recebe dois vetores ordenados, v1 e v2, e os seus respectivos tamanhos, q1 e q2.
// Devolve um novo vetor ordenado com a intercalacao de v1 e v2.
int * intercala (int *v1, int *v2, int q1, int q2){
  int intercala1[q1];
  int intercala2[q2];

    for(int i = 0; i < q1; i++){
        intercala1[i] = v1[i];
    }

    for(int j = 0; j < q2; j++){
        intercala2[j] = v2[j];
    }

    int intercalados[q1+q2];

    int k = 0;
    int i = 0;
    int j = 0;

    while (i < q1 && j < q2) {
        if (intercala1[i] < intercala2[j]) {
            intercalados[k++] = intercala1[i++];
        } else {
            intercalados[k++] = intercala2[j++];
        }
    }

    while (i < q1) {
        intercalados[k++] = intercala1[i++];
    }

    while (j < q2) {
        intercalados[k++] = intercala2[j++];
    }

    for (int l = 0; l < q1 + q2; l++) {
        printf("%d\n", intercalados[l]);
    }

    return 0;
}

int main () {
    int q1, q2, i;
    scanf ("%d", &q1);
    scanf ("%d", &q2);
    int *v1 = malloc (sizeof (int) * q1);
    int *v2 = malloc (sizeof (int) * q2);

    for (i = 0; i < q1; i++) {
        scanf ("%d", &v1[i]);
    }
    for (i = 0; i < q2; i++) {
        scanf ("%d", &v2[i]);
    }

    intercala(v1, v2, q1, q2);

    free (v1);
    free (v2);
    return 0;
}