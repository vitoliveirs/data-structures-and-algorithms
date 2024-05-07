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
    return (i-1)/2;
}

// Devolve o indice do filho direito de i.
int filhoDir (int i){
    return 2*i+2;
}

// Recebe um ponteiro para um heap.
// Devolve o indice do ultimo pai: chao(n/2)-1,
// onde n é a quantidade de elementos do heap.
int ultimoPai (Heap *h){
    return (h->quantidade/2)-1;
}

// Recebe um ponteiro para um heap e um indice pai.
// Se a chave do pai eh menor que a de algum filho,
// faz a troca e chama recursivamente.
// A troca deve ser feita pela chave do maior filho.
// No caso de empate, prefira trocar com o filho esquerdo.
void desceChave (Heap *h, int pai){
    int maiorFilho = pai; 
    int fEsq = 2 * pai + 1; // Calcula o índice do filho esquerdo
    int fDir = 2 * pai + 2; // Calcula o índice do filho direito

    // Verifica se o filho esquerdo existe e se é maior que o pai
    if (fEsq < h->quantidade && h->v[fEsq] > h->v[maiorFilho]){
        maiorFilho = fEsq;
    }

    // Verifica se o filho direito existe e se é maior que o maior dos filhos até agora
    if (fDir < h->quantidade && h->v[fDir] > h->v[maiorFilho]){
        maiorFilho = fDir;
    }

    // Se o maior filho for diferente do pai, faz a troca e chama recursivamente para o filho
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

// Recebe um ponteiro para um heap.
// Devolve 1 se heap vazio, 0 caso contrario.
int vazio (Heap *h){
    return h->quantidade == 0;
}

// Recebe um ponteiro para um heap.
// Devolve 1 se heap cheio, 0 caso contrario.
int cheio (Heap *h){
    return h->quantidade == h->tamanho;
}

// Apos inserir uma nova chave em um heap, pode ser necessario 
// "subir" esta nova chave para manter a propriedade estrutural do heap.
// Este procedimento recursivo recebe o ponteiro para o heap e o indice i.
void sobeChave (Heap *h, int i){
    int paiIndex = pai(i); // Renomeando a variável para evitar conflito de nomes
    if (i > 0 && h->v[i] > h->v[paiIndex]){
        int temp = h->v[i];
        h->v[i] = h->v[paiIndex];
        h->v[paiIndex] = temp;
        sobeChave(h, paiIndex);
    }
}

// Recebe um ponteiro para um heap e uma chave x.
// Insere a chave no fim do vetor e chama sobeChave().
void inserir (Heap *h, int x){
    if (cheio(h)){
        return;
    }
    h->v[h->quantidade] = x;
    h->quantidade++;
    sobeChave(h, h->quantidade-1);
}

// Recebe um ponteiro para um heap.
// Assume que o heap nao estah vazio.
// Remove a chave da raiz e devolve o seu valor.
// Para remover a raiz, troque as chaves da raiz com o ultimo elemento.
// Depois, chame desceChave() para a nova raiz.
int extraiMaximo (Heap *h){
    int max = h->v[0];
    h->v[0] = h->v[h->quantidade-1];
    h->quantidade--;
    desceChave(h, 0);
    return max;
}

// Recebe um ponteiro para um heap e uma chave x.
// Procura o indice i da chave x.
// Se encontrar, remove x do heap.
// Para remover x, troque as chaves de i com o ultimo elemento.
// Depois, chame desceChave() para i.
void remover (Heap *h, int x){
    int i;
    for (i = 0; i < h->quantidade; i++){
        if (h->v[i] == x){
            break;
        }
    }
    h->v[i] = h->v[h->quantidade - 1];
    h->quantidade--;
    desceChave(h, i);
}


int main () {
    int tam;
    scanf ("%d", &tam);
    Heap *h = criaHeapVazio (tam);
    char op;
    int x;
    while (scanf (" %c", &op) != EOF) {
        switch (op) {
            case 'I': scanf ("%d", &x); 
                      inserir (h, x);
                      break;
            case 'R': scanf ("%d", &x); 
                      remover (h, x);
                      break;
            case 'E': if (!vazio (h)) {
                          x = extraiMaximo (h);
                          printf ("[%d]\n", x);
                      }
                      break;
            case 'P': if (!vazio (h)) {
                          imprime (h->v, h->quantidade);
                      }
                      break;
        }
    }
    liberaHeap (h);
    return 0;
}