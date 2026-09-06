
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;

  // Leer la cantidad de elementos
  if (scanf("%d", &n) != 1) {
    return 0;
  }

  // Validar cantidad positiva
  if (n <= 0) {
    printf("La cantidad debe ser mayor a cero.\n");
    return 0;
  }

  // Asignar memoria exacta para N doubles
  double *notas = (double *)malloc((size_t)n * sizeof(double));
  if (notas == NULL) {
    printf("Error: No se pudo asignar memoria.\n");
    return 1;
  }

  double suma = 0.0;
  for (int i = 0; i < n; i++) {
    if (scanf("%lf", &notas[i]) != 1) {
      free(notas);
      return 1;
    }
    suma += notas[i];
  }

  // Imprimir el promedio
  printf("Promedio: %.2f\n", suma / (double)n);

  // Liberar la memoria reservada
  free(notas);

  return 0;
}
