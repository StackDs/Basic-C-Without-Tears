#include <stdint.h>
#include <stdio.h>

// Extrae el bit ubicado en la posicion P (0 o 1)
int obtener_bit(uint32_t n, uint32_t p) {
  // Desplazar el bit P a la posicion 0 y aislarlo con una mascara de 1
  return (int)((n >> p) & 1U);
}

int main(void) {
  uint32_t n, p;

  // Leer el numero N y la posicion P del bit
  if (scanf("%u %u", &n, &p) == 2 && p <= 31) {
    // Imprimir el estado del bit solicitado
    printf("%d\n", obtener_bit(n, p));
  }

  return 0;
}
