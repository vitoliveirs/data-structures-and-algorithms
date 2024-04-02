#include <stdio.h>

void BubbleSort(int *v, int n) {
  int i, j, aux, contadorexec = 0, contadorsats = 0;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - 1 - i; j++) {
      contadorexec++;
      if (v[j] > v[j + 1]) {
        contadorsats++;
        aux = v[j];
        v[j] = v[j + 1];
        v[j + 1] = aux;
        for (int k = 0; k < n; k++) {
          printf("%d ", v[k]);
        }
      }
      printf("\n");
    }
  }
  printf("Total de IFs executados: %d\n", contadorexec);
  printf("Total de IFs satisfeitos: %d\n", contadorsats);
}

int main() {
  int N;
  scanf("%d", &N);

  int vetor[N];

  for (int i = 0; i < N; i++) {
    scanf("%d", &vetor[i]);
  }

  BubbleSort(vetor, N);
  return 0;
}