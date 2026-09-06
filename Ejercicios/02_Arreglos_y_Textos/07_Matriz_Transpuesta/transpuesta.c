

#include <stdio.h>

int main(void) {
  int f, c;

  // Leer filas y columnas
  if (scanf("%d %d", &f, &c) == 2 && f >= 1 && c >= 1) {
    long long matriz[50][50];

    // Leer la matriz original de F x C
    for (int i = 0; i < f; i++) {
      for (int j = 0; j < c; j++) {
        if (scanf("%lld", &matriz[i][j]) != 1) {
          return 0;
        }
      }
    }

    // Imprimir la matriz transpuesta de C x F
    for (int j = 0; j < c; j++) {
      for (int i = 0; i < f; i++) {
        if (i > 0) {
          printf(" ");
        }
        printf("%lld", matriz[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}
