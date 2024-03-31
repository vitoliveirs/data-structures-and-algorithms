#include <stdio.h>

int main() {
  int N, x;

  scanf("%d", &N);

  int vetor[N];

  for(int i = 0; i < N; i++){
    scanf("%d", &vetor[i]);
  }

  while(scanf("%d", &x) != EOF){
    int z = 0;
    for(int i = 0; i < N; i++){
        if (x == vetor[i]){
            printf("SIM\n");
            z = 1;
            break;
        } 
    }
    if (!z) {
        printf("CHAVE NAO ENCONTRADA\n");
    }
  }

  return 0;
}