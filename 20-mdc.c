#include <stdio.h>

int mdc(int a, int b) {
    int resto;

    while (b != 0) {
        resto = a % b;
        a = b;
        b = resto;
    }

    return a;
}

int main() {

  int N[2];

  for (int i = 0; i < 2; i++){
    scanf("%d", &N[i]);
  }

  int result = mdc(N[0], N[1]);

  printf("%d", result);

  return 0;
}