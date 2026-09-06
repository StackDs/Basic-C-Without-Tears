
#include <stdio.h>

int main(void) {
  int n;

  // Leer la altura deseada para la piramide
  if (scanf("%d", &n) == 1 && n >= 1) {
    for (int i = 1; i <= n; i++) {
      // Imprimir los espacios en blanco a la izquierda para centrar
      for (int j = 0; j < n - i; j++) {
        printf(" ");
      }
      // Imprimir los asteriscos correspondientes al nivel (2*i - 1)
      for (int k = 0; k < 2 * i - 1; k++) {
        printf("*");
      }
      printf("\n");
    }
  }

  return 0;
}
