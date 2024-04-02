#include <stdio.h>
#include <stdlib.h>

typedef struct tFilaCircular {
  int *itens;      // ponteiro (vetor) de inteiros
  int inicio, fim; // fila: acesso sempre pelo inicio e fim
  int tamanho;    // tamanho maximo alocado
} FilaCircular;

// Recebe o tamanho alocado para o vetor.
// Devolve um ponteiro para Fila.
FilaCircular *criaFilaCircularVazia (int tamanho) {
  FilaCircular *filaCircular = (FilaCircular *)malloc(sizeof(FilaCircular));
    filaCircular->itens = (int *)malloc(tamanho * sizeof(int));
    filaCircular->inicio = 0;
    filaCircular->fim = 0;
    filaCircular->tamanho = tamanho;
  return filaCircular;
}

// Libera memoria: liberar fila->itens primeiro, depois a fila.
void liberaFilaCircular (FilaCircular *filaCircular) {
  free(filaCircular->itens);
  free(filaCircular);
}

// Devolve 1 se Fila cheia, 0 caso contrario.
int cheia(FilaCircular *filaCircular) { return (filaCircular->fim == filaCircular->tamanho); }

// Devolve 1 se Fila vazia, 0 caso contrario.
int vazia(FilaCircular *filaCircular) { return (filaCircular->inicio == filaCircular->fim); }

// Insere uma chave x no fim da Fila, caso nao esteja cheia.
void enfileirar(FilaCircular *filaCircular, int x) {
  if (!cheia(filaCircular)) {
    filaCircular->itens[filaCircular->fim] = x;
    filaCircular->fim++;
  }
}

// Remove uma chave do inicio da Fila, caso nao esteja vazia.
// Devolve a chave removida, ou -1 caso contrario.
int desenfileirar(FilaCircular *filaCircular) {
  if (!vazia(filaCircular)) {
    int x = filaCircular->itens[filaCircular->inicio];
      filaCircular->inicio++;

    // Se a fila estiver vazia após a remoção, zere os ponteiros
    if (filaCircular->inicio == filaCircular->tamanho) {
      filaCircular->inicio = 0;
      filaCircular->fim = 0;
    }

    return x;
  }
  return -1;
}

int main() {
  char op;
  int x, n, resultado;
  scanf("%d", &n);
  FilaCircular *filaCircular = criaFilaCircularVazia(n);
  while (scanf(" %c", &op) != EOF) {
    switch (op) {
    case 'E':
      scanf("%d", &x);
      enfileirar(filaCircular, x);
      break;
    case 'D':
      resultado = desenfileirar(filaCircular);
      if (resultado >= 0){
          printf("%d\n", resultado);
      }
      break;
    }
  }
  liberaFilaCircular(filaCircular);
  return 0;
}
