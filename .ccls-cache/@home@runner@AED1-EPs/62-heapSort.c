#include <stdio.h>
#include <stdlib.h>

typedef struct tHeap {
    int *v;
    int tamanho;    // tamanho do vetor alocado
    int quantidade; // qtde elementos inseridos
} Heap;

// Recebe o tamanho do vetor para o heap.
// Aloca um heap, aloca o vetor do heap, ajusta o tamanho,
// a quantidade inicia com zero.
// Devolve um ponteiro para o heap recem-criado.
Heap *criaHeapVazio(int tam) {
    Heap *h = malloc(sizeof(Heap));
    h->v = malloc(sizeof(int) * tam);
    h->tamanho = tam;
    h->quantidade = 0;
    return h;
}

void troca(int *v, int i, int j)
{
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

// Recebe um ponteiro para um heap.
// Libera o vetor e depois o ponteiro do heap.
void liberaHeap(Heap *h) {
    free(h->v);
    free(h);
}

// Devolve o indice do pai de i.
int pai(int i) {
    return (i - 1) / 2;
}

// Recebe um ponteiro para um heap.
// Devolve o indice do ultimo pai: chao(n/2)-1,
// onde n é a quantidade de elementos do heap.
int ultimoPai(Heap *h) {
    return (h->quantidade / 2) - 1;
}

// Recebe um ponteiro para um heap e um indice pai.
// Se a chave do pai eh menor que a de algum filho,
// faz a troca e chama recursivamente.
// A troca deve ser feita pela chave do maior filho.
// No caso de empate, prefira trocar com o filho esquerdo.
void peneirar(Heap *h, int pai) {
    int maiorFilho = pai; // Inicialmente, assume-se que o pai é o maior
    int esquerdo = 2 * pai + 1; // Índice do filho esquerdo
    int direito = 2 * pai + 2;  // Índice do filho direito

    // Verifica se o filho esquerdo existe e é maior que o pai atual
    if (esquerdo < h->quantidade && h->v[esquerdo] > h->v[maiorFilho]) {
        maiorFilho = esquerdo;
    }

    // Verifica se o filho direito existe e é maior que o maior dos filhos
    if (direito < h->quantidade && h->v[direito] > h->v[maiorFilho]) {
        maiorFilho = direito;
    }

    // Se o maior filho for diferente do pai, troca e chama recursivamente peneirar
    if (maiorFilho != pai) {
        int temp = h->v[pai];
        h->v[pai] = h->v[maiorFilho];
        h->v[maiorFilho] = temp;
        peneirar(h, maiorFilho); // Chama recursivamente para o maior filho
    }
}

// Recebe um ponteiro para um heap.
// Constroi um heap, chamando peneirar() para 
// cada um dos pais, do ultimo pai ate a raiz.
void constroiHeap(Heap *h) {
    int i;
    for (i = ultimoPai(h); i >= 0; i--) {
        peneirar(h, i);
    }
}

// Recebe um vetor e o seu tamanho.
// Imprime o conteudo do vetor.
void imprime(int *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

// Recebe um ponteiro para um heap.
// Ordena as chaves pelo algoritmo HeapSort.
// Imprime o vetor apos chamar constroiHeap().
// A cada iteracao, imprime o vetor apos peneirar().
void heapSort(Heap *h)
{
    int n = h->quantidade;
    constroiHeap(h);
    imprime(h->v,n);
    for(int i = n-1; i > 0; i--)
    {
        troca(h->v, 0, i); //maximo na posição i
        h->quantidade --;
        peneirar(h,0);
        imprime(h->v, n);
    }
}

int main() {
    int n, i;
    scanf("%d", &n);
    Heap *h = criaHeapVazio(n);
    for (i = 0; i < n; i++) {
        scanf("%d", &h->v[i]);
    }
    h->quantidade = n;
    heapSort(h);
    liberaHeap(h);
    return 0;
}
