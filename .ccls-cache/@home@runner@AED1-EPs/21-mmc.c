#include <stdio.h>

int mmc(int a, int b) {
    int produto = a * b;
    int temp;

    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }

    while (a != 0) {
        temp = b % a;
        b = a;
        a = temp;
    }

    return produto / b;
}

int main() {

  int N[2];

  for (int i = 0; i < 2; i++){
    scanf("%d", &N[i]);
  }

  int result = mmc(N[0], N[1]);

  printf("%d", result);

  return 0;
}