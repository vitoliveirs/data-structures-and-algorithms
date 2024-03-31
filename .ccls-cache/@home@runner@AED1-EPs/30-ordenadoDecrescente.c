#include <stdio.h>

char insertion(int vetor[], int N) {

  for (int i = 1; i < N; i++) {
    if (vetor[i] > vetor[i - 1]) {
      return 'N';
    }
  }
  return 'S';
}

int main() {

  int N;

  while (scanf("%d", &N) != EOF) {

    // N = 10
    // VETOR = 9 8 7 6 5 4 3 2 1 0

    int vetor[N];

    for (int i = 0; i < N; i++) {
      scanf("%d", &vetor[i]);
    }
    if (N != 0) {
      char Resultado = insertion(vetor, N);
      printf("%c\n", Resultado);
    } else {
      printf("S\n");
    }
  }

  return 0;
}