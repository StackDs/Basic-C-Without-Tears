
#include <stdio.h>

// Calcula base^exponente de forma iterativa
long long potencia(long long base, int exponente) {
  long long resultado = 1;
  for (int i = 0; i < exponente; i++) {
    resultado *= base;
  }
  return resultado;
}

int main(void) {
  long long base;
  int exponente;

  // Leer la base y el exponente no negativo
  if (scanf("%lld %d", &base, &exponente) == 2 && exponente >= 0) {
    printf("%lld\n", potencia(base, exponente));
  }

  return 0;
}
