/**
   ######################################################
   ##                                                  ##
   ##            Operadores y Logica Basica            ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    printf("=== 1. Operadores y Logica Basica ===\n");
  
  /** Verdad y Falsedad:
   * En C, 0 es Falso. Cualquier otro numero es Verdadero.
   * Cortocircuito logico: && y || se evaluan de izquierda a derecha 
   * y la evaluacion se detiene tan pronto como se conoce el resultado.
   **/
  int divisor = 0;
  int dividendo = 10;
  
  // Si divisor es 0, la primera condición (divisor != 0) es Falsa.
  // Gracias al cortocircuito, C omite evaluar la segunda parte,
  // evitando asi una division por cero que daria un error fatal.
  if (divisor != 0 && (dividendo / divisor > 1)) {
      printf("El resultado es mayor a 1\n");
  } else {
      printf("Cortocircuito en accion: El divisor era 0, pero evitamos el error.\n");
  }
  return 0;
}
