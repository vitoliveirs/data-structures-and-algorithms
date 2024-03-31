#include <stdio.h>

char sort(int vetor[], int N) {
    char result = 'S';

    for (int i = 1; i < N; i++) {
        if (vetor[i] < vetor[i - 1]) {
            result = 'N';
            break;
        }
    }

    if (result == 'S') {
        return result;
    }

    result = 'S';

    for (int i = 1; i < N; i++) {
        if (vetor[i] > vetor[i - 1]) {
            result = 'N';
            break;
        }
    }

    return result;
}


int main(){

  int N;

  while(scanf("%d", &N) != EOF){
    int vetor[N];

    for (int i = 0; i < N; i++){
        scanf("%d", &vetor[i]);    
    }

    if (N != 0){
        char resultado = sort(vetor, N);
        printf("%c\n", resultado);
    } else { printf("S\n"); }
  }

  return 0;
}