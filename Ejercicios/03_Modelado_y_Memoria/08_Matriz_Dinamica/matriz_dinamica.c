
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int f, c;

  if (scanf("%d %d", &f, &c) == 2 && f >= 1 && c >= 1) {
    // Asignar el arreglo principal de punteros a fila
    long long **matriz = (long long **)malloc((size_t)f * sizeof(long long *));
    if (matriz == NULL) {
      return 1;
    }

    // Asignar cada fila individualmente
    for (int i = 0; i < f; i++) {
      matriz[i] = (long long *)malloc((size_t)c * sizeof(long long));
      if (matriz[i] == NULL) {
        // Liberar filas previas en caso de fallo
        for (int k = 0; k < i; k++)
          free(matriz[k]);
        free(matriz);
        return 1;
      }
    }

    long long suma_total = 0;

    // Leer los elementos
    for (int i = 0; i < f; i++) {
      for (int j = 0; j < c; j++) {
        if (scanf("%lld", &matriz[i][j]) != 1) {
          return 1;
        }
        suma_total += matriz[i][j];
      }
    }

    // Imprimir la matriz
    for (int i = 0; i < f; i++) {
      for (int j = 0; j < c; j++) {
        if (j > 0)
          printf(" ");
        printf("%lld", matriz[i][j]);
      }
      printf("\n");
    }

    printf("Suma total: %lld\n", suma_total);

    // Liberar primero cada fila
    for (int i = 0; i < f; i++) {
      free(matriz[i]);
    }
    // Liberar el puntero principal
    free(matriz);
  }

  return 0;
}
