#include <stdio.h>
#include <stdlib.h>

typedef struct tItem {
    int chave;
    struct tItem *pai, *esq, *dir;
} Item;

typedef struct tArvore {
    Item *raiz;
    int quantidade;
} Arvore;

Arvore *criaArvoreVazia() {
    Arvore *a = malloc(sizeof(Arvore));
    a->raiz = NULL;
    a->quantidade = 0;
    return a;
}

void liberarNos(Item *atual);

Item *criaItem(int x) {
    Item *novo = malloc(sizeof(Item));
    novo->chave = x;
    novo->pai = novo->esq = novo->dir = NULL;
    return novo;
}

int vazia(Arvore *arv) {
    return arv->raiz == NULL;
}

void inserir(Arvore *arv, int x) {
    if (arv != NULL) {
        Item *novo = criaItem(x);
        if (vazia(arv)) {
            arv->raiz = novo;
            arv->quantidade++;
        } else {
            Item *atual = arv->raiz;
            Item *anterior = NULL;
            while (atual != NULL) {
                anterior = atual;
                if (x < atual->chave) {
                    atual = atual->esq;
                } else if (x > atual->chave) {
                    atual = atual->dir;
                } else {
                    free(novo);
                    return;
                }
            }
            if (x < anterior->chave) {
                anterior->esq = novo;
            } else {
                anterior->dir = novo;
            }
            novo->pai = anterior;
            arv->quantidade++;
        }
    }
}

void liberaArvore(Arvore *arvore) {
    if (arvore != NULL) {
        liberarNos(arvore->raiz);
        free(arvore);
    }
}

void liberarNos(Item *atual) {
    if (atual != NULL) {
        liberarNos(atual->esq);
        liberarNos(atual->dir);
        printf("libera: %d\n", atual->chave);
        free(atual);
    }
}

Item *maximo(Arvore *arv) {
    Item *atual = arv->raiz;
    while (atual->dir != NULL) {
        atual = atual->dir;
    }
    return atual;
}

int maiorChave(Arvore *arvore) {
    if (arvore != NULL) {
        Item *maior = maximo(arvore);
        return maior->chave;
    }
    return -1;
}

void imprimir(Item *atual) {
    if (atual != NULL) {
        imprimir(atual->esq); 
        printf("%d ", atual->chave); 
        imprimir(atual->dir); 
    }
}

int main() {
    int n, i, x;
    scanf("%d", &n);
    Arvore *arv = criaArvoreVazia();
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        inserir(arv, x);
    }
    imprimir(arv->raiz); 
    printf("\n");
    Item *it = maximo(arv);
    printf("Maior chave: %d\n", it->chave);
    liberaArvore(arv);
    return 0;
}
