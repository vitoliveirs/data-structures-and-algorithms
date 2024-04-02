#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 100

struct tInteiro {
    char numero[MAX_DIGITS];
};

struct tInteiro inteiro(char *str) {
    struct tInteiro inteiro;
    strcpy(inteiro.numero, str);
    return inteiro;
}

struct tInteiro soma(struct tInteiro a, struct tInteiro b) {
    struct tInteiro resultado;
    int carry = 0;
    int len_a = strlen(a.numero);
    int len_b = strlen(b.numero);
    int len_resultado = len_a > len_b ? len_a : len_b;
    resultado.numero[len_resultado] = '\0';

    for (int i = 0; i < len_resultado; i++) {
        int digito_a = i < len_a ? a.numero[len_a - 1 - i] - '0' : 0;
        int digito_b = i < len_b ? b.numero[len_b - 1 - i] - '0' : 0;
        int soma = digito_a + digito_b + carry;
        resultado.numero[len_resultado - 1 - i] = soma % 10 + '0';
        carry = soma / 10;
    }

    if (carry) {
        memmove(resultado.numero + 1, resultado.numero, len_resultado + 1);
        resultado.numero[0] = carry + '0';
    }

    return resultado;
}

struct tInteiro subtrai(struct tInteiro a, struct tInteiro b) {
    struct tInteiro resultado;
    int borrow = 0;
    int len_a = strlen(a.numero);
    int len_b = strlen(b.numero);
    int len_resultado = len_a > len_b ? len_a : len_b;
    resultado.numero[len_resultado] = '\0';

    for (int i = 0; i < len_resultado; i++) {
        int digito_a = i < len_a ? a.numero[len_a - 1 - i] - '0' : 0;
        int digito_b = i < len_b ? b.numero[len_b - 1 - i] - '0' : 0;
        int diferenca = digito_a - digito_b - borrow;
        if (diferenca < 0) {
            diferenca += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        resultado.numero[len_resultado - 1 - i] = diferenca + '0';
    }

    while (resultado.numero[0] == '0' && resultado.numero[1] != '\0') {
        memmove(resultado.numero, resultado.numero + 1, len_resultado);
        len_resultado--;
    }

    return resultado;
}

struct tInteiro multiplica(struct tInteiro a, struct tInteiro b) {
    struct tInteiro resultado;
    int len_a = strlen(a.numero);
    int len_b = strlen(b.numero);
    int len_resultado = len_a + len_b;
    resultado.numero[len_resultado] = '\0';

    for (int i = 0; i < len_resultado; i++) {
        resultado.numero[i] = '0';
    }

    for (int i = len_a - 1; i >= 0; i--) {
        for (int j = len_b - 1; j >= 0; j--) {
            int produto = (a.numero[i] - '0') * (b.numero[j] - '0') + (resultado.numero[i + j + 1] - '0');
            resultado.numero[i + j + 1] = produto % 10 + '0';
            resultado.numero[i + j] += produto / 10;
        }
    }

    while (resultado.numero[0] == '0' && resultado.numero[1] != '\0') {
        memmove(resultado.numero, resultado.numero + 1, len_resultado);
        len_resultado--;
    }

    return resultado;
}

int main() {
    char a[MAX_DIGITS], b[MAX_DIGITS];
    char operador;

    while (scanf("%s %c %s", a, &operador, b) != EOF) {
        struct tInteiro inteiroA = inteiro(a);
        struct tInteiro inteiroB = inteiro(b);
        struct tInteiro resultado;

        switch (operador) {
            case '+':
                resultado = soma(inteiroA, inteiroB);
                printf("%s\n", resultado.numero);
                break;
            case '-':
                resultado = subtrai(inteiroA, inteiroB);
                printf("%s\n", resultado.numero);
                break;
            case '*':
                resultado = multiplica(inteiroA, inteiroB);
                printf("%s\n", resultado.numero);
                break;
            default:
                break;
        }
    }

    return 0;
}
