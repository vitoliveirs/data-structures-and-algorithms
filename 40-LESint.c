#include <stdio.h>
#include <stdlib.h>

typedef struct tLista {
    int *itens;       // ponteiro (vetor) de inteiros
    int quantidade;   // qtde de elementos inseridos na lista
    int tamanho;      // tamanho maximo alocado 
} Lista;
void insertionSort(Lista *A, int n);
// Recebe o tamanho alocado para o vetor.
// Devolve um ponteiro para Lista.
Lista * criaListaVazia (int tamanho){
  Lista *lista = malloc(sizeof(Lista));
  lista->itens = malloc(sizeof(int) * tamanho);
  lista->quantidade = 0;
  lista->tamanho = tamanho;
  return lista;
}
// Libera memoria: liberar lista->itens primeiro, depois a lista.
void liberaLista (Lista *lista){
    free(lista->itens);
    free(lista);
}
// Devolve 1 se lista cheia, 0 caso contrario.
int cheia (Lista *lista){
    return lista->quantidade == lista->tamanho;
}
// Devolve 1 se lista vazia, 0 caso contrario.
int vazia (Lista *lista){
    return lista->quantidade == 0;
}
// Insere uma chave x na lista, caso ja nao exista na lista.
// (Ou seja, nao pode inserir chaves repetidas na lista.)
void inserir (Lista *lista, int x){
    if (cheia(lista))
        return;

  for (int i = 0; i < lista->quantidade; i++) {
      if (lista->itens[i] == x) {
          return; // Chave repetida, nao faz insercao
      }
  }
  lista->itens[lista->quantidade] = x;
  lista->quantidade++;
}
// Remove uma chave x da lista, caso exista.
void remover (Lista *lista, int x){
    if (vazia(lista))
        return;

  int posicao = -1;
  for (int i = 0; i < lista->quantidade; i++) {
      if (lista->itens[i] == x) {
          posicao = i;
          break;
      }
  }
  if (posicao == -1) {
      // Chave nao encontrada na lista
      return;
  }
  // Desloca os elementos uma posicao para frente para remover x
  for (int i = posicao; i < lista->quantidade - 1; i++) {
      lista->itens[i] = lista->itens[i + 1];
  }
  lista->quantidade--;
}

void buscaValor(Lista *lista, int x){
    if (vazia(lista)){
        printf("NAO\n");
        return;
    }


    for(int i = 0; i < lista->quantidade; i++){
        if(x == lista->itens[i]){
            printf("SIM\n");
            return;
        } 
    }
    printf("NAO\n");
}

void mostraValores(Lista *lista, int x){
    if (vazia(lista))
        return;
    insertionSort(lista, lista->quantidade);
    for(int i = 0; i < lista->quantidade; i++){
        printf("%d ", lista->itens[i]);
    }
}

void insertionSort(Lista *A, int n) {
    int i, j, chave;
    for (j = 1; j < n; j++) {
        chave = A->itens[j];
        i = j - 1;
        while (i >= 0 && chave < A->itens[i]) {
            A->itens[i+1] = A->itens[i];
            i--;
        }
        A->itens[i+1] = chave;
    }

    int ultimo = A->itens[0];
    for (i = 1; i < n; i++) {
        if (A->itens[i] != ultimo) {
              ultimo = A->itens[i];
        }
    }
}

int main(){

  int n, x;
  scanf ("%d", &n);

  char op;

  Lista *lista = criaListaVazia(n);

  while(scanf("%c", &op) != EOF){
    scanf("%d", &x);
    switch(op){
      case 'I':
        inserir(lista, x);
        break;
      case 'R':
        remover(lista, x);
        break;
      case 'B':
        buscaValor(lista, x);
        break;
      case 'M':
        mostraValores(lista, x);
        break;
      default:
        break;
    }  
  }

  liberaLista(lista);
  return 0;
}