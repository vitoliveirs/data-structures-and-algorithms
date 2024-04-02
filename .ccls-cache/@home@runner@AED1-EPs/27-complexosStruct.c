#include <stdio.h>

struct tComplex{
  int a, b;
};

struct tComplex complexo(int a, int b){
  struct tComplex complexo;
  complexo.a = a;
  complexo.b = b;
  return complexo;
}

struct tComplex soma(struct tComplex a, struct tComplex b){
  struct tComplex complexo;
  complexo.a = a.a + b.a;
  complexo.b = a.b + b.b;
  return complexo;
}

struct tComplex subtrai(struct tComplex a, struct tComplex b){
  struct tComplex complexo;
  complexo.a = a.a - b.a;
  complexo.b = a.b - b.b;
  return complexo;
}

struct tComplex multiplica(struct tComplex a, struct tComplex b){
  struct tComplex complexo;
  complexo.a = a.a * b.a - a.b * b.b;
  complexo.b = a.a * b.b + a.b * b.a;
  return complexo;
}

struct tComplex divide(struct tComplex a, struct tComplex b){
  struct tComplex complexo;
  complexo.a = (a.a * b.a + a.b * b.b) / (b.a * b.a + b.b * b.b);
  complexo.b = (a.b * b.a - a.a * b.b) / (b.a * b.a + b.b * b.b);
  return complexo;
}

int main() {
  int a1, b1, a2, b2;
  char i1, operador, i2;

  while(scanf("%d %d%c %c %d %d%c", &a1, &b1, &i1, &operador, &a2, &b2, &i2) != EOF){
    struct tComplex complex1 = complexo(a1, b1);
    struct tComplex complex2 = complexo(a2, b2);
    struct tComplex resultado;

    switch(operador){
        case '+':
          resultado = soma(complex1, complex2);
          if (resultado.b >= 0)
            printf("%d +%di\n", resultado.a, resultado.b);
          else
            printf("%d %di\n", resultado.a, resultado.b);
          break;
        case '-':
          resultado = subtrai(complex1, complex2);
          if (resultado.b >= 0)
            printf("%d +%di\n", resultado.a, resultado.b);
          else
            printf("%d %di\n", resultado.a, resultado.b);
          break;
        case '*':
          resultado = multiplica(complex1, complex2);
          if (resultado.b >= 0)
            printf("%d +%di\n", resultado.a, resultado.b);
          else
            printf("%d %di\n", resultado.a, resultado.b);
          break;
        case '/':
          resultado = divide(complex1, complex2);
          if (resultado.b >= 0)
            printf("%d +%di\n", resultado.a, resultado.b);
          else
            printf("%d %di\n", resultado.a, resultado.b);
          break;
        default:
          break;
    }
  }
  return 0;
}
