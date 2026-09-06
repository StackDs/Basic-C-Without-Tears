#include <stdint.h>
#include <stdio.h>

int main(void) {
  uint32_t n;

  // Leer el numero entero sin signo de 32 bits
  if (scanf("%u", &n) == 1) {
    // Invertir todos los 32 bits con el operador NOT (~)
    uint32_t invertido = ~n;

    // Imprimir el valor decimal resultante
    printf("%u\n", invertido);
  }

  return 0;
}
