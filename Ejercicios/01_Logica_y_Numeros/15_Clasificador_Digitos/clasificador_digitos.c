
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  long long n;

  // Leer el numero entero N
  if (scanf("%lld", &n) == 1) {
    long long temp = llabs(n);
    int pares = 0;
    int impares = 0;

    // Caso especial cuando el numero es 0
    if (temp == 0) {
      pares = 1;
    } else {
      while (temp > 0) {
        int digito = (int)(temp % 10);
        if (digito % 2 == 0) {
          pares++;
        } else {
          impares++;
        }
        temp /= 10;
      }
    }

    printf("Pares: %d, Impares: %d\n", pares, impares);
  }

  return 0;
}
