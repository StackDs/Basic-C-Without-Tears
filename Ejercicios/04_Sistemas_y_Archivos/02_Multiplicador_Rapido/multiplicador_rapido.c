#include <stdio.h>

int main(void) {
  unsigned long long n;
  unsigned int k;

  // Leer el numero base N y la potencia K
  if (scanf("%llu %u", &n, &k) == 2) {
    // Multiplicacion rapida desplazando bits a la izquierda: N * 2^K
    unsigned long long multiplicacion = n << k;

    // Division entera rapida desplazando bits a la derecha: N / 2^K
    unsigned long long division = n >> k;

    // Imprimir ambos resultados separados por un espacio
    printf("%llu %llu\n", multiplicacion, division);
  }

  return 0;
}
