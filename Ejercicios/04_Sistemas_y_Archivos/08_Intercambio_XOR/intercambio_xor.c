#include <stdio.h>

// Intercambia los valores de dos variables enteras sin memoria auxiliar
void intercambiar_xor(long long *a, long long *b) {
  // Evitar la operacion si ambas variables apuntan a la misma direccion
  if (a != b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
  }
}

int main(void) {
  long long a, b;

  // Leer los dos enteros A y B
  if (scanf("%lld %lld", &a, &b) == 2) {
    // Aplicar el intercambio logico mediante XOR
    intercambiar_xor(&a, &b);

    // Imprimir los valores intercambiados
    printf("%lld %lld\n", a, b);
  }

  return 0;
}
