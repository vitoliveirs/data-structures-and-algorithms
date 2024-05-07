#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    int q1, q2, i;
    scanf("%d %d", &q1, &q2);

    char *v1 = malloc(sizeof(char) * q1);
    char *v2 = malloc(sizeof(char) * q2);

    for (i = 0; i < q1; i++) {
        scanf(" %c", &v1[i]);  // um espaco em branco antes de %c
    }

    for (i = 0; i < q2; i++) {
        scanf(" %c", &v2[i]);  // um espaco em branco antes de %c
    }

    char intercalados[q1 + q2 + 1]; 

    int k = 0;
    int j = 0;

    for (int l = 0; l < q1 + q2; l++) {
        if (k < q1 && v1[k] < v2[j]) {
            intercalados[l] = v1[k++];
        } else if (j < q2) {
            intercalados[l] = v2[j++];
        } else {
            intercalados[l] = v1[k++];
        }
    }
    intercalados[q1 + q2] = '\0'; 
    printf("%s", intercalados);

    free(v1);
    free(v2);
    return 0;
}