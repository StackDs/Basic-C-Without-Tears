#include <stdio.h>

// Determina si un numero es par evaluando el bit menos significativo
int es_par(long long n) {
  // Si el ultimo bit es 0, el numero es par; si es 1, es impar
  return (n & 1LL) == 0;
}

int main(void) {
  long long n;

  // Leer el numero entero
  if (scanf("%lld", &n) == 1) {
    if (es_par(n)) {
      printf("PAR\n");
    } else {
      printf("IMPAR\n");
    }
  }

  return 0;
}
