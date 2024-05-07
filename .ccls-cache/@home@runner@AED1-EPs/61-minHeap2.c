#include <stdlib.h>
#include <stdio.h>

int main () {
    int n, i;
    scanf ("%d", &n);
    Heap *h = criaHeapVazio (n);
    for (i = 0; i < n; i++) {
        scanf ("%d", &h->v[i]);
    }
    h->quantidade = n;
    heapSort (h);
    liberaHeap (h);
    return 0;
}