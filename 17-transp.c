#include <stdio.h>

int main() {

  int N, M;
  int A[100][100];

  scanf("%d", &N);
  scanf("%d", &M);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      printf("%d ", A[j][i]);
    }
    printf("\n");
  }

  return 0;
}