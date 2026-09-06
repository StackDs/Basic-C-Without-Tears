
#include <stdio.h>

// Determina si n es primo (retorna 1 si es primo, 0 si no lo es)
int es_primo(long long n) {
  // Numeros menores o iguales a 1 no son primos
  if (n <= 1) {
    return 0;
  }
  // 2 y 3 son primos
  if (n <= 3) {
    return 1;
  }
  // Descartar multiplos de 2 y 3
  if (n % 2 == 0 || n % 3 == 0) {
    return 0;
  }
  // Comprobar divisores de la forma 6k ± 1 hasta sqrt(n)
  for (long long i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return 0;
    }
  }
  return 1;
}

int main(void) {
  long long n;

  // Leer el numero a validar
  if (scanf("%lld", &n) == 1) {
    if (es_primo(n)) {
      printf("%lld es primo.\n", n);
    } else {
      printf("%lld no es primo.\n", n);
    }
  }

  return 0;
}
