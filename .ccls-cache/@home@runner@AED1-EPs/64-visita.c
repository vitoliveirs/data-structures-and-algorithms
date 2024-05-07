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
        free(atual);
    }
}

// Recebe um ponteiro para a raiz de uma arvore.
// Imprime as chaves, de acordo com uma visita pre-ordem.
void imprimePreOrdem (Item *r){
    if (r != NULL){
        printf ("%d ", r->chave);
        imprimePreOrdem (r->esq);
        imprimePreOrdem (r->dir);
    }
}

// Recebe um ponteiro para a raiz de uma arvore.
// Imprime as chaves, de acordo com uma visita in-ordem.
void imprimeInOrdem (Item *r){
    if (r != NULL){
        imprimeInOrdem (r->esq);
        printf ("%d ", r->chave);
        imprimeInOrdem (r->dir);
    }
}

// Recebe um ponteiro para a raiz de uma arvore.
// Imprime as chaves, de acordo com uma visita pos-ordem.
void imprimePosOrdem (Item *r){
    if (r != NULL){
        imprimePosOrdem (r->esq);
        imprimePosOrdem (r->dir);
        printf ("%d ", r->chave);
    }
}

int main () {
    int n, i, x;
    scanf ("%d", &n);
    Arvore *arv = criaArvoreVazia ();
    for (i = 0; i < n; i++) {
        scanf ("%d", &x);
        inserir (arv, x);
    }
    if (!vazia (arv)) {
        printf ("Pre-ordem: ");
        imprimePreOrdem (arv->raiz);
        printf ("\nIn-ordem: ");
        imprimeInOrdem (arv->raiz);
        printf ("\nPos-ordem: ");
        imprimePosOrdem (arv->raiz);
        printf ("\n");
    }
    liberaArvore (arv);
    return 0;
}