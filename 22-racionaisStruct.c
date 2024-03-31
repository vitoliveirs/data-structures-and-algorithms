#include <stdio.h>
#include <stdlib.h>

struct tRacional {
  int numerador;
  int denominador;
};

struct tRacional racional(int numerador, int denominador){
  struct tRacional racional;

  racional.numerador = numerador;
  racional.denominador = denominador;
  return racional;
}

struct tRacional negativo(struct tRacional negativoRacional){

  struct tRacional resultado;

  if (negativoRacional.denominador < 0) {
      resultado.numerador = negativoRacional.numerador;
      resultado.denominador = negativoRacional.denominador;
  } else {
      resultado.numerador = -negativoRacional.numerador;
      resultado.denominador = negativoRacional.denominador;
  }
  return resultado;
}

struct tRacional soma(struct tRacional somaNumerador, struct tRacional somaDenominador){

  struct tRacional resultado;
  resultado.numerador = (somaNumerador.numerador * somaDenominador.denominador) + (somaDenominador.numerador * somaNumerador.denominador);
  resultado.denominador = somaNumerador.denominador * somaDenominador.denominador;

  return resultado;
}

struct tRacional multiplica(struct tRacional multiplicacaoNumerador, struct tRacional multiplicacaoDenominador){

  struct tRacional resultado;
  resultado.numerador = multiplicacaoNumerador.numerador * multiplicacaoDenominador.numerador;
  resultado.denominador = multiplicacaoNumerador.denominador * multiplicacaoDenominador.denominador;

  return resultado;
}

struct tRacional divide(struct tRacional divisaoNumerador, struct tRacional divisaoDenominador){
  struct tRacional resultado;

  if (divisaoDenominador.numerador < 0) {
    divisaoDenominador.numerador *= -1;
    divisaoDenominador.denominador *= -1;
  }

  int numerador = divisaoNumerador.numerador * divisaoDenominador.denominador;
  int denominador = divisaoNumerador.denominador * divisaoDenominador.numerador;
  if ((numerador < 0 && denominador > 0) || (numerador > 0 && denominador < 0)) {
    resultado.numerador = -abs(numerador);
    resultado.denominador = abs(denominador);
  } else {
    resultado.numerador = abs(numerador);
    resultado.denominador = abs(denominador);
  }
  return resultado;
}

struct tRacional reduz(struct tRacional reduzRacional){
    struct tRacional resultado;
    int reduzNumerador = reduzRacional.numerador;
    int reduzDenominador = reduzRacional.denominador;

    while (reduzDenominador != 0) {
      int valor = reduzDenominador;
      reduzDenominador = reduzNumerador % reduzDenominador;
      reduzNumerador = valor;
    }

    resultado.numerador = reduzRacional.numerador / reduzNumerador;
    resultado.denominador = reduzRacional.denominador / reduzNumerador;

  if (resultado.denominador < 0) {
      resultado.numerador *= -1;
      resultado.denominador *= -1;
  }
    return resultado;
}

int main() {
  int n1, d1, n2, d2;
  char operacao;

  while(scanf("%d %d %c %d %d", &n1, &d1, &operacao, &n2, &d2) != EOF) {
    struct tRacional rac1 = racional(n1, d1);
    struct tRacional rac2 = racional(n2, d2);
    struct tRacional resultado;

    switch (operacao) {
      case '+':
        resultado = soma(rac1, rac2);
        break;
      case '-':
        resultado = soma(rac1, negativo(rac2));
        break;
      case '*':
        resultado = multiplica(rac1, rac2);
        break;
      case '/':
        resultado = divide(rac1, rac2);
        break;
      default:
        continue;
    }

    struct tRacional resultadoSimplificado = reduz(resultado);
    printf("%d %d\n", resultadoSimplificado.numerador, resultadoSimplificado.denominador);
  }

  printf("\n");

  return 0;
}