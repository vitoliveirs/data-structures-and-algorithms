#include <stdio.h>

void insertionSort(int *A, int n) {
    int i, j, chave, contador = 0;
    for (j = 1; j < n; j++) {
        chave = A[j];
        i = j - 1;
        while (i >= 0 && chave < A[i]) {
            contador++;
            A[i+1] = A[i];
            i--;
            for (int k = 0; k < n; k++) {
                printf("%d ", A[k]);
            }
            printf("\n");
        }
        A[i+1] = chave;

        for (int k = 0; k < n; k++) {
        printf("%d ", A[k]);
    }
    }


    printf("\nDeslocamentos: %d\n", contador);
}

int main(){
  int N;
  scanf("%d", &N);

  int vetor[N];

  for(int i = 0; i < N; i++){
    scanf("%d", &vetor[i]);
  }

  insertionSort(vetor, N);
  return 0;
}