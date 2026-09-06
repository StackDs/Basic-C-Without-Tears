
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  long long n;

  // Leer el numero entero N
  if (scanf("%lld", &n) == 1) {
    long long temp = llabs(n);
    int suma = 0;

    // Descomponer en base 10 y acumular cada digito
    if (temp == 0) {
      suma = 0;
    } else {
      while (temp > 0) {
        suma += (int)(temp % 10);
        temp /= 10;
      }
    }

    printf("%d\n", suma);
  }

  return 0;
}
