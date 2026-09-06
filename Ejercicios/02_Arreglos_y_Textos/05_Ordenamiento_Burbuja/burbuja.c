
#include <stdio.h>

// Implementacion de Bubble Sort con bandera de optimizacion
void bubble_sort(long long arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int hubo_intercambio = 0;
    for (int j = 0; j < n - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        long long temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        hubo_intercambio = 1;
      }
    }
    // Si no hubo ningun intercambio, el arreglo ya esta ordenado
    if (!hubo_intercambio) {
      break;
    }
  }
}

int main(void) {
  int n;

  // Leer la cantidad de elementos
  if (scanf("%d", &n) == 1 && n >= 1) {
    long long arr[1000];

    // Leer los elementos del arreglo
    for (int i = 0; i < n; i++) {
      if (scanf("%lld", &arr[i]) != 1) {
        return 0;
      }
    }

    // Ordenar con bubble sort
    bubble_sort(arr, n);

    // Imprimir el arreglo ordenado
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        printf(" ");
      }
      printf("%lld", arr[i]);
    }
    printf("\n");
  }

  return 0;
}
