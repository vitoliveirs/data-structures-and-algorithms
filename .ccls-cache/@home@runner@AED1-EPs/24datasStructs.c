#include <stdio.h>

typedef struct tData {
  int dia, mes, ano;
} Data;

int isBissexto(int ano) {

  int resultado = 0;

  if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)) {
    return resultado = 1;
  }
  return resultado;
}

int isValida(Data dt) {
  switch (dt.mes) {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    if (dt.dia > 0 && dt.dia <= 31) {
      printf("%s\n", "DATA VALIDA");
      return 1;
    } else {
      printf("%s\n", "DATA INVALIDA");
      return 0;
    }
    break;
  case 2:
    if (dt.dia > 0 && dt.dia <= 28) {
        printf("%s\n", "DATA VALIDA");
        return 1;
    } else if ((isBissexto(dt.ano) == 1) && (dt.dia > 0 && dt.dia <= 29)) {
        printf("%s\n", "DATA VALIDA");
        return 1;
    } else {
        printf("%s\n", "DATA INVALIDA");
        return 0;
    }
    break;
  case 4:
  case 6:
  case 9:
  case 11:
    if (dt.dia > 0 && dt.dia <= 30) {
      printf("%s\n", "DATA VALIDA");
      return 1;
    } else {
      printf("%s\n", "DATA INVALIDA");
      return 0;
    }
    break;
  default:
    printf("%s\n", "DATA INVALIDA");
    return 0;
  }
}

int main() {
  int N, D, M, A;
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    scanf("%d %d %d", &D, &M, &A);
    struct tData data = {D, M, A};
    isValida(data);
  }

  return 0;
}