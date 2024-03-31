#include <stdio.h>

void OrdenaPorSelecao (int *v, int n) {
  int i, j, min, tmp, contador = 0;
  for (i = 0; i < n-1; i++) {
    min = i;
    for (j = i+1; j < n; j++) {
      contador++;
      if (v[j] < v[min]) { 
          min = j;
        }
    }
      tmp = v[i];
      v[i] = v[min];
      v[min] = tmp;
      for (int k = 0; k < n; k++) {
          printf("%d ", v[k]);
      }
      printf("\n");
  }
  printf("Total de IFs executados: %d\n", contador);
}

int main(){
  int N;
  scanf("%d", &N);

  int vetor[N];

  for(int i = 0; i < N; i++){
    scanf("%d", &vetor[i]);
  }

  OrdenaPorSelecao(vetor, N);
  return 0;
}