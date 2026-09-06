#include <stdio.h>

// Cuenta los bits en 1 usando el algoritmo de Brian Kernighan
unsigned int contar_bits(unsigned long long n) {
  unsigned int cuenta = 0;

  // n & (n - 1) apaga el bit en 1 menos significativo en cada paso
  while (n > 0) {
    n &= (n - 1);
    cuenta++;
  }

  return cuenta;
}

int main(void) {
  unsigned long long n;

  // Leer el numero entero sin signo
  if (scanf("%llu", &n) == 1) {
    // Calcular e imprimir la cantidad de bits encendidos
    printf("%u\n", contar_bits(n));
  }

  return 0;
}
