
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;

  if (scanf("%d", &n) == 1 && n >= 1) {
    // Asignacion inicial para N enteros
    long long *arr = (long long *)malloc((size_t)n * sizeof(long long));
    if (arr == NULL) {
      printf("Error al asignar memoria inicial.\n");
      return 1;
    }

    // Leer primeros N datos
    for (int i = 0; i < n; i++) {
      if (scanf("%lld", &arr[i]) != 1) {
        free(arr);
        return 1;
      }
    }

    // Redimensionar al doble de capacidad (2 * N)
    long long *nuevo_arr =
        (long long *)realloc(arr, (size_t)(2 * n) * sizeof(long long));
    if (nuevo_arr == NULL) {
      printf("Error al redimensionar memoria.\n");
      free(arr);
      return 1;
    }
    arr = nuevo_arr;

    // Leer los siguientes N datos en las nuevas posiciones
    for (int i = n; i < 2 * n; i++) {
      if (scanf("%lld", &arr[i]) != 1) {
        free(arr);
        return 1;
      }
    }

    // Imprimir los 2*N elementos
    for (int i = 0; i < 2 * n; i++) {
      if (i > 0) {
        printf(" ");
      }
      printf("%lld", arr[i]);
    }
    printf("\n");

    // Liberar la memoria
    free(arr);
  }

  return 0;
}
