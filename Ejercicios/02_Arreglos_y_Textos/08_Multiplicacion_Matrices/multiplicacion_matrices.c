
#include <stdio.h>

int main(void) {
  int f1, c1;

  // Leer dimensiones de matriz A
  if (scanf("%d %d", &f1, &c1) != 2) {
    return 0;
  }

  long long a[50][50];
  for (int i = 0; i < f1; i++) {
    for (int j = 0; j < c1; j++) {
      if (scanf("%lld", &a[i][j]) != 1) {
        return 0;
      }
    }
  }

  int f2, c2;
  // Leer dimensiones de matriz B
  if (scanf("%d %d", &f2, &c2) != 2) {
    return 0;
  }

  long long b[50][50];
  for (int i = 0; i < f2; i++) {
    for (int j = 0; j < c2; j++) {
      if (scanf("%lld", &b[i][j]) != 1) {
        return 0;
      }
    }
  }

  // Validar compatibilidad de multiplicacion
  if (c1 != f2) {
    printf("Error: Matrices incompatibles para multiplicacion.\n");
    return 0;
  }

  // Calcular el producto matricial R = A * B
  for (int i = 0; i < f1; i++) {
    for (int j = 0; j < c2; j++) {
      long long suma = 0;
      for (int k = 0; k < c1; k++) {
        suma += a[i][k] * b[k][j];
      }
      if (j > 0) {
        printf(" ");
      }
      printf("%lld", suma);
    }
    printf("\n");
  }

  return 0;
}
