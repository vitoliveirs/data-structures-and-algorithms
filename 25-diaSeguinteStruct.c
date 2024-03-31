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
    if (dt.dia == 31) {
      dt.dia = 1, dt.mes = dt.mes + 1, dt.ano = dt.ano;
      printf("%d %d %d", dt.dia, dt.mes, dt.ano);
    } else {
      dt.dia = dt.dia + 1, dt.mes = dt.mes, dt.ano = dt.ano;
      printf("%d %d %d", dt.dia, dt.mes, dt.ano);
    }
    break;
  case 12:
    if(dt.dia == 31){
      dt.dia = 1, dt.mes = 1, dt.ano = dt.ano + 1;
      printf("%d %d %d", dt.dia, dt.mes, dt.ano);
    }
    break;
  case 2:
    if (dt.dia == 28 && isBissexto(dt.ano) == 0) {
      dt.dia = 1, dt.mes = dt.mes + 1, dt.ano = dt.ano;
      printf("%d %d %d", dt.dia, dt.mes, dt.ano);
    } else if ((isBissexto(dt.ano) == 1) && (dt.dia == 29)) {
      dt.dia = 1, dt.mes = dt.mes + 1, dt.ano = dt.ano;
      printf("%d %d %d", dt.dia, dt.mes, dt.ano);
    } else if (isBissexto(dt.ano) == 1 && dt.dia == 28){
      dt.dia = dt.dia + 1, dt.mes = dt.mes, dt.ano = dt.ano;
      printf("%d %d %d", dt.dia, dt.mes, dt.ano);
    }
    break;
  case 4:
  case 6:
  case 9:
  case 11:
    if (dt.dia > 0 && dt.dia <= 30) {
      dt.dia = 1, dt.mes = dt.mes + 1, dt.ano = dt.ano;
      printf("%d %d %d", dt.dia, dt.mes, dt.ano);
    } else {
      dt.dia = dt.dia + 1, dt.mes = dt.mes, dt.ano = dt.ano;
      printf("%d %d %d", dt.dia, dt.mes, dt.ano);
    }
    break;
  default:
    break;
  }
  return 0;
}

int main() {
  int D, M, A;

  scanf("%d", &D);
  scanf("%d", &M);
  scanf("%d", &A);

  struct tData data = {D, M, A};

  isValida(data);

  return 0;
}