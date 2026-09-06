
#include <stdio.h>

#define N 10

// Ordenamiento por seleccion simple para ordenar las 10 notas
void ordenar(double arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    double temp = arr[i];
    arr[i] = arr[min_idx];
    arr[min_idx] = temp;
  }
}

int main(void) {
  double notas[N];
  double suma = 0.0;

  // Leer las 10 calificaciones
  for (int i = 0; i < N; i++) {
    if (scanf("%lf", &notas[i]) != 1) {
      return 0;
    }
    suma += notas[i];
  }

  // Calcular promedio
  double promedio = suma / N;

  // Ordenar para obtener mediana y moda facilmente
  ordenar(notas, N);

  // Para N = 10, la mediana es el promedio de los elementos centrales
  // (posiciones 4 y 5)
  double mediana = (notas[4] + notas[5]) / 2.0;

  // Calcular la moda (valor con mayor frecuencia)
  double moda = notas[0];
  int max_frec = 1;
  int frec_actual = 1;

  for (int i = 1; i < N; i++) {
    if (notas[i] == notas[i - 1]) {
      frec_actual++;
    } else {
      frec_actual = 1;
    }

    if (frec_actual > max_frec) {
      max_frec = frec_actual;
      moda = notas[i];
    }
  }

  // Imprimir las estadisticas calculadas
  printf("Promedio: %.2f\n", promedio);
  printf("Mediana: %.2f\n", mediana);
  printf("Moda: %.2f\n", moda);

  return 0;
}
