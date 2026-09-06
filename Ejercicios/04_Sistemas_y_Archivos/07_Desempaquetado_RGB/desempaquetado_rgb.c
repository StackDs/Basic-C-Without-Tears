#include <stdint.h>
#include <stdio.h>

// Desempaqueta un entero de color en sus tres componentes RGB
void desempaquetar_rgb(uint32_t color, uint8_t *r, uint8_t *g, uint8_t *b) {
  // Extraer el canal Rojo (bits 16-23)
  *r = (uint8_t)((color >> 16) & 0xFF);
  // Extraer el canal Verde (bits 8-15)
  *g = (uint8_t)((color >> 8) & 0xFF);
  // Extraer el canal Azul (bits 0-7)
  *b = (uint8_t)(color & 0xFF);
}

int main(void) {
  uint32_t color;

  // %i permite leer enteros tanto en base decimal como hexadecimal (0x...)
  if (scanf("%i", (int *)&color) == 1) {
    uint8_t r, g, b;
    desempaquetar_rgb(color, &r, &g, &b);

    // Imprimir los componentes separados por espacios
    printf("%u %u %u\n", r, g, b);
  }

  return 0;
}
