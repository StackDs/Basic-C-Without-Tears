
#include <stdio.h>

// Comprueba si n es un numero perfecto
int es_perfecto(long long n) {
  // Los numeros <= 1 no tienen divisores propios que sumen n
  if (n <= 1) {
    return 0;
  }

  long long suma = 1; // 1 siempre es divisor propio para n > 1

  // Buscar parejas de divisores hasta sqrt(n)
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      suma += i;
      // Si los factores son distintos, sumar tambien el cociente (n / i)
      if (i * i != n) {
        suma += (n / i);
      }
    }
  }

  return (suma == n);
}

int main(void) {
  long long n;

  // Leer el numero entero positivo N
  if (scanf("%lld", &n) == 1) {
    if (es_perfecto(n)) {
      printf("%lld es un numero perfecto.\n", n);
    } else {
      printf("%lld no es un numero perfecto.\n", n);
    }
  }

  return 0;
}
