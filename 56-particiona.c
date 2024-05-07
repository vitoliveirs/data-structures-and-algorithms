#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimir(int *v, int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", v[i]);
    }
    if (n > 0)
    {
        printf("%d\n", v[n - 1]);
    }
}

void swap(int *v, int i, int j){
  int temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

int *partition(int *v, int e, int d, int p){

  swap(v, d - 1, p);

  int j = e, i = j - 1;
  while (j < d-1)
  {
      if (v[j] <= v[d - 1])
      {
          i++;
          swap(v, i, j);
      }
      j++;
  }
  i++;
  swap(v, i, d - 1);
  printf("%d\n", i);
  return v;
}

int main() {
    int n, p;
    scanf("%d %d", &n, &p);

    int* v = (int*)malloc(n * sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    partition(v, 0, n, p);

    imprimir(v, n);
    free(v);
    return 0;
}
