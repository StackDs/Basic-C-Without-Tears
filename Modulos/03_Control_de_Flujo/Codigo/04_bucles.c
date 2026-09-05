/**
   ######################################################
   ##                                                  ##
   ##          Bucles (Repeticion de Tareas)           ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    printf("\n\n=== 4. Bucles (Repeticion de tareas) ===\n");

  /** while: Evalua la condicion antes de entrar al bloque. **/
  int energia = 3;
  printf("--- Ciclo while ---\n");
  while (energia > 0) {
      printf("Energia restante: %d\n", energia);
      energia--;
  }

  /** do-while: Se ejecuta al menos una vez, evalua al final. **/
  printf("\n--- Ciclo do-while ---\n");
  int iteraciones = 1; 
  do {
      printf("Ejecutando iteracion %d garantizada antes de evaluar condicion.\n", iteraciones);
      iteraciones++;
  } while (iteraciones <= 1); // Ya es falso, pero igual se ejecuto una vez

  /** for: Inicializacion, condicion, incremento (o decremento). **/
  printf("\n--- Ciclo for ---\n");
  for (int i = 0; i < 3; i++) {
      printf("Iteracion for: %d\n", i);
  }

  /** Anidamiento de bucles: Un bucle dentro de otro. **/
  printf("\n--- Bucles anidados ---\n");
  for (int fila = 1; fila <= 2; fila++) {
      for (int col = 1; col <= 2; col++) {
          printf("[%d,%d] ", fila, col);
      }
      printf("\n"); // Salto de linea por cada fila terminada
  }
  return 0;
}
