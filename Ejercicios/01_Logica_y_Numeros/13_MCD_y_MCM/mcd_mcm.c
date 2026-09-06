
#include <stdio.h>

// Calcula el MCD mediante el algoritmo de divisiones sucesivas de Euclides
long long calcular_mcd(long long a, long long b) {
  while (b != 0) {
    long long temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int main(void) {
  long long a, b;

  // Leer los dos enteros positivos A y B
  if (scanf("%lld %lld", &a, &b) == 2 && a > 0 && b > 0) {
    long long mcd = calcular_mcd(a, b);
    // MCM(a, b) = (a * b) / MCD(a, b); se divide antes de multiplicar
    long long mcm = (a / mcd) * b;
    printf("%lld %lld\n", mcd, mcm);
  }

  return 0;
}
