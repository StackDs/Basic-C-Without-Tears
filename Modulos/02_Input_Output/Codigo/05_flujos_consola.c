#include <stdio.h>

int main(void) {
  /**
     ###########################################################
     ##                                                       ##
     ##             Flujos de consola avanzados               ##
     ##                                                       ##
     ###########################################################
  **/

  printf("\n\n=== Flujos de consola avanzados ===\n");

  /** stdin, stdout y stderr:
   * La consola se divide en flujos de datos (archivos virtuales).
   * Podemos usar fprintf para mandar texto especificamente a la salida normal (stdout)
   * o a la salida de errores (stderr).
   **/
  fprintf(stdout, "Esto se imprime con fprintf(stdout). Es identico a printf.\n");
  fprintf(stderr, "[Mensaje de Sistema]: Esto es un mensaje usando fprintf(stderr). Se usa para notificar errores.\n");

  return 0;
}
