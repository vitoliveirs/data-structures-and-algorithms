#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tItem
{
    char nome[100];
    int numPesquisas;
    struct tItem *ant, *prox;
} Item;

typedef struct tLista
{
    Item *primeiro, *ultimo;
    int quantidade;
} Lista;

Lista *criaListaVazia()
{
    Lista *lista = malloc(sizeof(Lista));
    lista->primeiro = lista->ultimo = NULL;
    lista->quantidade = 0;
    return lista;
}

Item *criaItem(char *palavra)
{
    Item *item = malloc(sizeof(Item));
    strcpy(item->nome, palavra);
    item->ant = item->prox = NULL;
    return item;
}

void liberaLista(Lista *lista)
{
    Item *anterior = NULL, *atual = lista->primeiro;
    while (atual != NULL)
    {
        anterior = atual;
        atual = atual->prox;
        free(anterior);
    }
    free(lista);
}

int vazia(Lista *lista)
{
    return lista->primeiro == NULL;
}

void imprimir(Lista *lista)
{
    Item *atual = lista->primeiro;
    while (atual != NULL)
    {
        printf("%s [%d]\n", atual->nome, atual->numPesquisas);
        atual = atual->prox;
    }
}

Item *buscaPosicao(Lista *lista, char *palavra)
{
    Item *atual = lista->primeiro;
    while (atual != NULL && strcmp(palavra, atual->nome) != 0)
    {
        atual = atual->prox;
    }
    return atual;
}

void removerRepetido(Lista *lista, Item *palavra)
{
    if (!vazia(lista))
    {
        if (palavra->ant == NULL)
        {
            lista->primeiro = palavra->prox;
            if (palavra->prox != NULL)
            {
                (palavra->prox)->ant = NULL;
            }
            else
            {
                lista->ultimo = NULL;
            }
        }
        else if (palavra->prox == NULL)
        {
            (palavra->ant)->prox = NULL;
            lista->ultimo = palavra->ant;
        }
        else
        {
            (palavra->ant)->prox = palavra->prox;
            (palavra->prox)->ant = palavra->ant;
        }
        lista->quantidade--;
        free(palavra);
    }
}

void inserirPalavra(Lista *lista, Item *palavra, Item *novo)
{
    novo->numPesquisas = palavra->numPesquisas;
    Item *atual = lista->primeiro;
    while (atual != NULL && atual->numPesquisas < novo->numPesquisas)
    {
        atual = atual->prox;
    }
    if (atual == NULL)
    {
        (lista->ultimo)->prox = novo;
        novo->ant = lista->ultimo;
        lista->ultimo = novo;
    }
    else if (atual->ant == NULL)
    {
        lista->primeiro = novo;
        atual->ant = novo;
    }
    else
    {
        (atual->ant)->prox = novo;
        novo->ant = atual->ant;
        atual->ant = novo;
    }
    novo->prox = atual;
    lista->quantidade++;
}

void listar(Lista *lista, char *palavra)
{
    Item *novo = criaItem(palavra);
    if (vazia(lista))
    {
        lista->primeiro = lista->ultimo = novo;
        lista->quantidade++;
        novo->numPesquisas = 1;
    }
    else
    {
        Item *buscar = buscaPosicao(lista, palavra);

        if (buscar != NULL)
        {
            buscar->numPesquisas++;
            inserirPalavra(lista, buscar, novo);
            removerRepetido(lista, buscar);
        }
        else
        {
            (lista->ultimo)->prox = novo;
            novo->ant = lista->ultimo;
            lista->ultimo = novo;
            novo->numPesquisas = 1;
        }
    }
}

int main()
{
    char palavra[100];
    Lista *lista = criaListaVazia();
    while (scanf(" %s", palavra) != EOF)
    {
        listar(lista, palavra);
    }
    imprimir(lista);
    liberaLista(lista);
    return 0;
}
