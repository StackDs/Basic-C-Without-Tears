
#include <stdio.h>

// Funcion para calcular N! de forma iterativa usando 64 bits
unsigned long long calcular_factorial(int n) {
  unsigned long long fact = 1;
  for (int i = 1; i <= n; i++) {
    fact *= (unsigned long long)i;
  }
  return fact;
}

int main(void) {
  int n;

  // Leer el numero entero N
  if (scanf("%d", &n) == 1) {
    // Validar si el numero es negativo
    if (n < 0) {
      printf("El factorial no esta definido para numeros negativos.\n");
    } else {
      printf("%llu\n", calcular_factorial(n));
    }
  }

  return 0;
}
