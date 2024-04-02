#include <stdio.h>
#include <stdlib.h>

typedef struct tPilha {
  int *itens;   // ponteiro (vetor) de inteiros
  int topo;    // pilha: acesso sempre pelo topo
  int tamanho;  // tamanho maximo alocado
} Pilha;

// Recebe o tamanho alocado para o vetor.
// Devolve um ponteiro para Pilha.
Pilha * criaPilhaVazia (int tamanho){
  Pilha *p = malloc(sizeof(Pilha));
  p->itens = malloc(sizeof(int) * tamanho);
  p->topo = 0;
  p->tamanho = tamanho;
  return p;
}

// Libera memoria: liberar pilha->itens primeiro, depois a pilha.
void liberaPilha (Pilha *pilha){
 free(pilha->itens);
 free(pilha);
}

// Devolve 1 se Pilha cheia, 0 caso contrario.
int cheia (Pilha *pilha){
 if(pilha->topo == pilha->tamanho){
  return 1;
 } else return 0;
}

// Devolve 1 se Pilha vazia, 0 caso contrario.
int vazia (Pilha *pilha){
 if(pilha->topo == 0){
  return 1;
 } else return 0;
}

// Insere uma chave x no topo da Pilha, caso nao esteja cheia.
void empilha (Pilha *pilha, int x){
 if(cheia(pilha) != 1){
  pilha->itens[pilha->topo] = x;
  pilha->topo++;
 }
}

// Remove uma chave do topo da Pilha, caso nao esteja vazia.
// Devolve a chave removida, ou -1 caso contrario.
int desempilha (Pilha *pilha){
 if(!vazia(pilha)){
  pilha->topo--;
  return pilha->itens[pilha->topo];
 }
 return -1;
}

// Imprime os elementos da pilha, um por linha, do topo para a base.
void imprimePilhaTopo (Pilha *pilha){
  for(int i = pilha->topo - 1; i >= 0; i--){
    printf("%d\n", pilha->itens[i]);
  }
}

// Imprime os elementos da pilha, um por linha, da base para o topo.
void imprimePilhaBase (Pilha *pilha){
 for(int i = 0; i < pilha->topo; i++){
  printf("%d\n", pilha->itens[i]);
 }
}


int main () {
    char op;
    int n, x;
    scanf ("%d", &n); // tamanho alocado para a pilha
    Pilha *pilha = criaPilhaVazia(n);

    while (scanf (" %c", &op) != EOF) {
        switch (op) {
            case 'E': scanf ("%d", &x);
                      empilha(pilha, x);
                      break;
            case 'D': 
              desempilha(pilha);
                      break;
            case 'T': 
              imprimePilhaTopo(pilha);
                      break;
            case 'B': 
              imprimePilhaBase(pilha);
                      break;
        }
    }
    liberaPilha(pilha);
    return 0;
}