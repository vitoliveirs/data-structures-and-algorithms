#include <stdio.h>
#include <stdlib.h>

typedef struct tFila {
  int *itens;      // ponteiro (vetor) de inteiros
  int inicio, fim; // fila: acesso sempre pelo inicio e fim
  int tamanho;    // tamanho maximo alocado
} Fila;

// Recebe o tamanho alocado para o vetor.
// Devolve um ponteiro para Fila.
Fila *criaFilaVazia(int tamanho) {
  Fila *fila = (Fila *)malloc(sizeof(Fila));
  fila->itens = (int *)malloc(tamanho * sizeof(int));
  fila->inicio = 0;
  fila->fim = 0;
  fila->tamanho = tamanho;
  return fila;
}

// Libera memoria: liberar fila->itens primeiro, depois a fila.
void liberaFila(Fila *fila) {
  free(fila->itens);
  free(fila);
}

// Devolve 1 se Fila cheia, 0 caso contrario.
int cheia(Fila *fila) { return (fila->fim == fila->tamanho); }

// Devolve 1 se Fila vazia, 0 caso contrario.
int vazia(Fila *fila) { return (fila->inicio == fila->fim); }

// Insere uma chave x no fim da Fila, caso nao esteja cheia.
void enfileirar(Fila *fila, int x) {
  if (!cheia(fila)) {
    fila->itens[fila->fim] = x;
    fila->fim++;
  }
}

// Remove uma chave do inicio da Fila, caso nao esteja vazia.
// Devolve a chave removida, ou -1 caso contrario.
int desenfileirar(Fila *fila) {
  if (!vazia(fila)) {
    int x = fila->itens[fila->inicio];
    fila->inicio++;

    // Se a fila estiver vazia após a remoção, zere os ponteiros
    if (fila->inicio == fila->tamanho) {
      fila->inicio = 0;
      fila->fim = 0;
    }

    return x;
  }
  return -1;
}

int main() {
  char op;
  int x, n, resultado;
  scanf("%d", &n);
  Fila *fila = criaFilaVazia(n);
  while (scanf(" %c", &op) != EOF) {
    switch (op) {
    case 'E':
      scanf("%d", &x);
      enfileirar(fila, x);
      break;
    case 'D':
      resultado = desenfileirar(fila);
      if (resultado >= 0){
          printf("%d\n", resultado);
      }
      break;
    }
  }
  liberaFila(fila);
  return 0;
}
