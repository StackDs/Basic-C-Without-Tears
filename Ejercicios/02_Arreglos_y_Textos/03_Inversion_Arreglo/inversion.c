
#include <stdio.h>

// Funcion para invertir el arreglo in-place
void invertir_arreglo(long long arr[], int n) {
  for (int i = 0; i < n / 2; i++) {
    long long temp = arr[i];
    arr[i] = arr[n - 1 - i];
    arr[n - 1 - i] = temp;
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

    // Invertir in-place
    invertir_arreglo(arr, n);

    // Imprimir el arreglo resultante
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
