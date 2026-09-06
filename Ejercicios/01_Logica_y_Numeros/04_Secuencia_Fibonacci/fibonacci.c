
#include <stdio.h>

int main(void) {
  int n;

  // Leer la cantidad de terminos deseados
  if (scanf("%d", &n) == 1 && n >= 1) {
    unsigned long long a = 0; // Primer termino (F0)
    unsigned long long b = 1; // Segundo termino (F1)

    for (int i = 0; i < n; i++) {
      // Imprimir espacio separador excepto antes del primer elemento
      if (i > 0) {
        printf(" ");
      }
      printf("%llu", a);

      // Calcular el siguiente termino y desplazar las variables
      unsigned long long siguiente = a + b;
      a = b;
      b = siguiente;
    }
    printf("\n");
  }

  return 0;
}
