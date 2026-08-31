#include <stdio.h>
#include <stdbool.h>

int main(void) {
  /**
     ############################################
     ##                                        ##
     ##  3. Seleccion Multiple (switch)        ##  
     ##                                        ##
     ############################################
  **/
  printf("\n\n=== 3. Seleccion Multiple (switch) ===\n");
  
  /** Switch y el comportamiento Fall-Through:
   * Solo acepta enteros (int) y caracteres (char).
   * Si omites un 'break', la ejecucion "cae" a los siguientes casos.
   **/
  int opcion = 1;
  printf("Evaluando opcion %d sin un break en el case 1:\n", opcion);
  switch (opcion) {
      case 1:
          printf("-> Elegiste 1\n");
          // ¡Falta el break a proposito para ver el fall-through!
      case 2:
          printf("-> Tambien ejecuto el 2 sin querer (Fall-Through)\n");
          break;
      default:
          printf("-> Opcion invalida\n");
          break;
  }

  /** Agrupacion de casos aprovechando el Fall-Through: **/
  char tecla = 'W';
  printf("\nPresionaste la tecla '%c':\n", tecla);
  switch(tecla) {
      case 'w':
      case 'W':
          printf("-> Accion: Avanzar personaje\n");
          break;
      default:
          printf("-> Tecla no configurada\n");
          break;
  }
  return 0;
}
