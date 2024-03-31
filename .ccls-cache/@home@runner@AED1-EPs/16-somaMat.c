#include <stdio.h>

int main() {

  int N, x = 0, i, j;
  int A[100][100], B[100][100];

  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &B[i][j]);
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      x += A[i][j] + B[i][j];
      printf("%d", x);
      x = 0;
      printf("\n");
    }
  }

  return 0;
}