/**
   ######################################################
   ##                                                  ##
   ##        Condicionales (Toma de Decisiones)        ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    printf("\n\n=== 2. Condicionales (if / else) ===\n");
  
  /** if, else if, else:
   * Control basico de decisiones. Las llaves {} son obligatorias
   * a nivel moral para evitar errores, incluso con una sola linea.
   **/
  int nota = 85;
  if (nota >= 90) {
      printf("Excelente\n");
  } else if (nota >= 70) {
      printf("Aprobaste con %d. A duras penas, pero aprobaste.\n", nota);
  } else {
      printf("Nos vemos en verano\n");
  }

  /** El Operador Ternario (? :):
   * Un if-else comprimido en una sola expresion.
   * (condicion) ? valor_si_verdadero : valor_si_falso
   **/
  int edad = 25;
  const char* bebida = (edad >= 18) ? "Cerveza" : "Cerveza sin alcohol"; // Correccion const char* añadida según reporte de auditoria!
  printf("Para alguien de %d anios, le servimos: %s\n", edad, bebida);
  return 0;
}
