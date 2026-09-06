#include <stdint.h>
#include <stdio.h>

// Empaqueta 3 canales de 8 bits (RGB) en un solo entero de 32 bits
uint32_t empaquetar_rgb(uint8_t r, uint8_t g, uint8_t b) {
  // R en los bits 16-23, G en los bits 8-15 y B en los bits 0-7
  return ((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b;
}

int main(void) {
  unsigned int r, g, b;

  // Leer los valores de los canales Rojo, Verde y Azul
  if (scanf("%u %u %u", &r, &g, &b) == 3 && r <= 255 && g <= 255 && b <= 255) {
    uint32_t color = empaquetar_rgb((uint8_t)r, (uint8_t)g, (uint8_t)b);

    // Imprimir en formato hexadecimal 0xRRGGBB y en formato decimal
    printf("0x%06X (%u)\n", color, color);
  }

  return 0;
}
