
#include <stdio.h>

int main(void) {
  long long n;

  // Leer el entero positivo inicial N
  if (scanf("%lld", &n) == 1 && n >= 1) {
    int pasos = 0;
    printf("%lld", n);

    // Iterar hasta llegar al valor 1
    while (n != 1) {
      if (n % 2 == 0) {
        n /= 2;
      } else {
        n = 3 * n + 1;
      }
      printf(" %lld", n);
      pasos++;
    }
    printf("\nTotal de pasos: %d\n", pasos);
  }

  return 0;
}
