
#include <stdio.h>

int main(void) {
  long long n;

  // Leer el valor de N desde la entrada estandar
  if (scanf("%lld", &n) == 1 && n >= 1) {
    long long suma = 0;

    // Acumular la suma de todos los enteros desde 1 hasta N
    for (long long i = 1; i <= n; i++) {
      suma += i;
    }

    // Imprimir el resultado final
    printf("%lld\n", suma);
  }

  return 0;
}
