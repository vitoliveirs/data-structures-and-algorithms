#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

  int n, x = 0, sum = 0;
  int *vetor = malloc(sizeof(int) * n);

   scanf("%d", &n);

  for (int i = 1; i < n; i++) {
    if (n % i == 0) {
      vetor[i] = i;

      sum += vetor[i];
    }
  }
  if (sum == n) {
    printf("%s", "SIM");
  } else {
    printf("%s", "NAO");
  }

  free(vetor);

  return 0;
}
