

#include <stdio.h>

#define TOTAL_ESTUDIANTES 5

// Definicion de la estructura Estudiante
struct Estudiante {
  char nombre[50];
  int edad;
  double promedio;
};

int main(void) {
  struct Estudiante grupo[TOTAL_ESTUDIANTES];
  int mejor_idx = 0;

  // Leer los datos de los 5 estudiantes
  for (int i = 0; i < TOTAL_ESTUDIANTES; i++) {
    if (scanf("%49s %d %lf", grupo[i].nombre, &grupo[i].edad,
              &grupo[i].promedio) != 3) {
      return 0;
    }
    // Determinar el indice del estudiante con mayor promedio
    if (grupo[i].promedio > grupo[mejor_idx].promedio) {
      mejor_idx = i;
    }
  }

  // Imprimir el registro completo
  for (int i = 0; i < TOTAL_ESTUDIANTES; i++) {
    printf("Estudiante: %s, Edad: %d, Promedio: %.2f\n", grupo[i].nombre,
           grupo[i].edad, grupo[i].promedio);
  }

  // Imprimir el estudiante destacado
  printf("Mejor estudiante: %s con promedio %.2f\n", grupo[mejor_idx].nombre,
         grupo[mejor_idx].promedio);

  return 0;
}
