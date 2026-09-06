
#include <stdio.h>

// Retorna el indice de la primera ocurrencia o -1 si no existe
int buscar_lineal(const long long arr[], int n, long long x) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == x) {
      return i;
    }
  }
  return -1;
}

int main(void) {
  int n;
  long long x;

  // Leer la cantidad de elementos y el elemento a buscar
  if (scanf("%d %lld", &n, &x) == 2 && n >= 1) {
    long long arr[1000];

    // Leer los elementos del arreglo
    for (int i = 0; i < n; i++) {
      if (scanf("%lld", &arr[i]) != 1) {
        return 0;
      }
    }

    // Realizar la busqueda
    int indice = buscar_lineal(arr, n, x);

    if (indice != -1) {
      printf("Encontrado en el indice %d.\n", indice);
    } else {
      printf("No encontrado.\n");
    }
  }

  return 0;
}
