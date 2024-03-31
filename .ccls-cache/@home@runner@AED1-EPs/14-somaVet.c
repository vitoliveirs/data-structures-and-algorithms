#include <stdio.h>

int main(){

  int *N = (int*)malloc(sizeof(int));
  int chave; 
  scanf("%d", N);

  if(N[0] < 0){
    printf("nenhum numero informado");
    return 0;
  }
  //chave = N[0];
  for (int i = 1; i < *N; i++){
    if (N[i] < N[i-1]){
      chave = N[i];
    }
  } 

  printf("%d", chave);

  return 0;
}