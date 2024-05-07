#include <stdio.h>
#include <stdlib.h>
typedef struct tLista
{
    char *itens;     // ponteiro (vetor) de chars
    int quantidade; // qtde de elementos inseridos na lista
    int tamanho;    // tamanho maximo alocado
} Lista;

// Recebe o tamanho alocado para o vetor.
// Devolve um ponteiro para Lista.
Lista *criaListaVazia(int tamanho)
{
    Lista *lista = malloc(sizeof(Lista));
    lista->tamanho = tamanho;                     // associa o parâmetro tamanho à variavel tamanho da struct lista
    lista->itens = malloc(sizeof(char) * tamanho); // o vetor terá <tamanho> itens
    lista->quantidade = 0;                        // lista iniciada vazia
    return lista;
}
// Libera memoria: liberar lista->itens primeiro, depois a lista.
void liberaLista(Lista *lista)
{
    free(lista->itens); // libera o vetor
    free(lista);        // libera a estrutura
}
// Devolve 1 se lista cheia, 0 caso contrario.
int cheia(Lista *lista)
{
    return lista->quantidade == lista->tamanho; // retorna 1 quando quantidade == tamanho
}
// Devolve 1 se lista vazia, 0 caso contrario.
int vazia(Lista *lista)
{
    return lista->quantidade == 0; // retorna 1 quando quandidade == 0
}



void imprimeLista(Lista *lista) // imprime lista dessa forma -> item_0 item_1 item_2 item_3 ... item_n\n
{
    for (int i = 0; i < lista->quantidade-1; i++)
    {
        printf("%c ", lista->itens[i]); // imprime até penultimo elemento, lado a lado, separado por espaço (\n imprime e pula linha (para o exercicio))
    }
    if (lista->quantidade > 0)
    {
        printf("%c\n", lista->itens[lista->quantidade-1]); // imprime o ultimo elemento e pula uma linha
    }
}

// devolve primeiro indice tal que x <= lista.intens[i]
int buscaPosicao(Lista *lista, char x)
{
    int i;

    for (i = 0; i < lista->quantidade ; i++)
    {
        if (x <= lista->itens[i])
        {
            return i;
        }
    }   


}

int buscaValor(Lista *lista, int n, char x)
{
    for(int i = 0; i < n; i++)
    {
        if( lista->itens[i] == x)
        {
            return i;
        }
    }

    return -1;
}

// Insere uma chave x na lista, caso ja nao exista na lista.
// (Ou seja, nao pode inserir chaves repetidas na lista.)
void inserir(Lista *lista, char x)
{
    if (vazia(lista))
    {
        lista->itens[0] = x;
        lista->quantidade = 1;

    }
    else
    {

        int i = buscaPosicao(lista, x);
        //printf("Ao inserir %c, o valor de i é %d\n", x,i); //debug
        // ignorar chaves repetidas
        if (lista->itens[i] != x)
        {
            // deslocar para direita (começar da direita para a esquerda):
            for (int j = lista->tamanho -1; j >= i; j--) // tenho que deslocar do ultimo elemento até o i
            {
                lista->itens[j + 1] = lista->itens[j];
            }

            lista->itens[i] = x;
            lista->quantidade++;

        }
    }
}

void remover(Lista *lista, char x)
{
    if (!vazia(lista))
    {
        int i = buscaPosicao(lista, x);
        if (lista->itens[i] == x)
        {
            for (int j = i + 1; j <= lista->quantidade ; j++)
            {
                lista->itens[j - 1] = lista->itens[j];
            }
            lista->quantidade--;

        }
    }
}

int main()
{
    char op, x;
    int q, i;
    Lista *lista = criaListaVazia(q);
    while (scanf(" %c", &op) != EOF)
    {
        switch (op)
        {
        case 'I':
            scanf(" %c", &x);
            inserir(lista, x);     
            break;
        case 'B':
            scanf(" %c", &x);
            int retorno = buscaValor(lista, q, x);
            if ( lista->quantidade == 0 || retorno < 0 )
            {
                printf("NAO\n");
            }
            else
            {
                printf("SIM\n");
            }

            break;
        case 'R':
            scanf(" %c", &x);
            remover(lista, x);         

            break;

        case 'M':
            imprimeLista(lista);
            break;
        }
    }

    liberaLista(lista);
    return 0;
}