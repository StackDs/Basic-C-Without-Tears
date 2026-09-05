/**
   ######################################################
   ##                                                  ##
   ##            Arreglos 1D (Declaracion)             ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>

int main(void) {
  printf("\n=== 1. Arreglos 1D (Declaracion e Inicializacion) ===\n");
  // Declaracion sin inicializar (demostracion de basura en memoria)
  // ADVERTENCIA INTENCIONAL: Leer elementos de un arreglo sin inicializar es
  // Comportamiento Indefinido (UB) en C. Se muestra aquí ÚNICAMENTE para
  // demostrar que C no inicializa arreglos locales automáticamente en cero
  // (como sí harían otros lenguajes).
  int basura[3];
  printf("Basura en el arreglo sin inicializar (UB): %d, %d, %d\n", basura[0],
         basura[1], basura[2]);

  // Inicializacion completa
  int edades[5] = {18, 22, 35, 40, 19};
  printf("Inicializacion completa (edades): %d, %d, %d, %d, %d\n", edades[0],
         edades[1], edades[2], edades[3], edades[4]);

  // Inicializacion parcial (el resto se vuelve 0 automaticamente)
  int contadores[5] = {1, 2};
  printf("Inicializacion parcial: %d, %d, %d, %d, %d\n", contadores[0],
         contadores[1], contadores[2], contadores[3], contadores[4]);

  return 0;
}
