#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tHeap {
    int *v;
    int tamanho;    // tamanho do vetor alocado
    int quantidade; // qtde elementos inseridos
} Heap;

// Recebe o tamanho do vetor para o heap.
// Aloca um heap, aloca o vetor do heap, ajusta o tamanho,
// a quantidade inicia com zero.
// Devolve um ponteiro para o heap recem-criado.
Heap *criaHeapVazio (int tam){
    Heap *h = malloc(sizeof(Heap));
    h->v = malloc(sizeof(int) * tam);
    h->tamanho = tam;
    h->quantidade = 0;
    return h;
}

// Recebe um ponteiro para um heap.
// Libera o vetor e depois o ponteiro do heap.
void liberaHeap (Heap *h){
    free(h->v);
    free(h);
}

// Devolve o indice do pai de i.
int pai (int i){
    return (i - 1) / 2;
}

// Devolve o indice do filho direito de i.
int filhoDir (int i){
    return 2 * i + 2;
}

// Recebe um ponteiro para um heap.
// Devolve o indice do ultimo pai: chao(n/2)-1,
// onde n é a quantidade de elementos do heap.
int ultimoPai (Heap *h){
    return (h->quantidade / 2) - 1;
}

// Recebe um ponteiro para um heap e um indice pai.
// Se a chave do pai eh menor que a de algum filho,
// faz a troca e chama recursivamente.
// A troca deve ser feita pela chave do maior filho.
// No caso de empate, prefira trocar com o filho esquerdo.
// Recebe um ponteiro para um heap e um índice do pai.
// Se a chave do pai é menor que a de algum filho,
// faz a troca e chama recursivamente.
// A troca deve ser feita pela chave do maior filho.
// No caso de empate, prefira trocar com o filho da esquerda.
void desceChave (Heap *h, int pai){
    int maiorFilho = pai;
    int esq = 2 * pai + 1;
    int dir = 2 * pai + 2;

    if (esq < h->quantidade && h->v[esq] > h->v[maiorFilho]){
        maiorFilho = esq;
    }

    if (dir < h->quantidade && h->v[dir] > h->v[maiorFilho]){
        maiorFilho = dir;
    }

    if (maiorFilho != pai){
        int temp = h->v[pai];
        h->v[pai] = h->v[maiorFilho];
        h->v[maiorFilho] = temp;
        desceChave(h, maiorFilho);
    }
}

// Recebe um ponteiro para um heap.
// Constroi um heap, chamando desceChave() para 
// cada um dos pais, do ultimo pai ate a raiz.
void constroiHeap (Heap *h){
    int i;
    for (i = ultimoPai(h); i >= 0; i--){
        desceChave(h, i);
    }
}

// Recebe um vetor e o seu tamanho.
// Imprime o conteudo do vetor.
void imprime (int *v, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main () {
    int n, i;
    scanf ("%d", &n);
    while (n != 0) {
        Heap *h = criaHeapVazio (n);
        for (i = 0; i < n; i++) {
            scanf ("%d", &h->v[i]);
        }
        h->quantidade = n;
        constroiHeap (h);
        imprime (h->v, h->quantidade);
        liberaHeap (h);
        scanf("%d", &n); // Ler próximo valor de n
    }
    return 0;
}
