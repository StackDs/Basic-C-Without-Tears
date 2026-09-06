
#include <stdio.h>

int main(void) {
  int n;

  // Leer la cantidad de elementos
  if (scanf("%d", &n) == 1 && n >= 1) {
    long long num;
    if (scanf("%lld", &num) != 1) {
      return 0;
    }

    // Inicializar minimo y maximo con el primer elemento
    long long min_val = num;
    long long max_val = num;

    // Recorrer el resto de elementos actualizando los extremos
    for (int i = 1; i < n; i++) {
      if (scanf("%lld", &num) == 1) {
        if (num < min_val) {
          min_val = num;
        }
        if (num > max_val) {
          max_val = num;
        }
      }
    }

    // Imprimir los resultados
    printf("Min: %lld, Max: %lld\n", min_val, max_val);
  }

  return 0;
}
