
#include <stdio.h>
#include <stdlib.h>

// Funcion para invertir los digitos numericamente
long long invertir_numero(long long n) {
  int signo = (n < 0) ? -1 : 1;
  long long temp = llabs(n);
  long long invertido = 0;

  // Extraer digito por digito y acumularlo en orden invertido
  while (temp > 0) {
    invertido = invertido * 10 + (temp % 10);
    temp /= 10;
  }

  return invertido * signo;
}

int main(void) {
  long long n;

  // Leer el numero entero N
  if (scanf("%lld", &n) == 1) {
    printf("%lld\n", invertir_numero(n));
  }

  return 0;
}
