
#include <stdio.h>

int main(void) {
  int f, c;

  // Leer dimensiones
  if (scanf("%d %d", &f, &c) == 2 && f >= 1 && c >= 1) {
    int a[50][50];
    int b[50][50];

    // Leer matriz A
    for (int i = 0; i < f; i++) {
      for (int j = 0; j < c; j++) {
        if (scanf("%d", &a[i][j]) != 1) {
          return 0;
        }
      }
    }

    // Leer matriz B
    for (int i = 0; i < f; i++) {
      for (int j = 0; j < c; j++) {
        if (scanf("%d", &b[i][j]) != 1) {
          return 0;
        }
      }
    }

    // Calcular e imprimir la suma elemento a elemento
    for (int i = 0; i < f; i++) {
      for (int j = 0; j < c; j++) {
        if (j > 0) {
          printf(" ");
        }
        printf("%d", a[i][j] + b[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}
