#include <stdio.h>
#include <stdbool.h>

int main(void) {
  /**
     ############################################
     ##                                        ##
     ##  5. Modificadores de Flujo             ##  
     ##                                        ##
     ############################################
  **/
  printf("\n\n=== 5. Modificadores de Flujo ===\n");

  /** break: Aborta y sale inmediatamente del bucle actual. **/
  printf("--- Ejemplo de break ---\n");
  for (int i = 0; i < 10; i++) {
      if (i == 3) {
          printf("Me aburri en i=3, abortando ciclo.\n");
          break; 
      }
      printf("Iteracion %d\n", i);
  }

  /** continue: Salta el resto del bloque y pasa directo a la siguiente iteracion. **/
  printf("\n--- Ejemplo de continue ---\n");
  for (int i = 0; i < 5; i++) {
      if (i == 2) {
          printf("Saltando la iteracion 2...\n");
          continue; // Salta el printf de abajo en i=2
      }
      printf("Iteracion %d\n", i); 
  }
  
  // Nota sobre goto: La teoria te explica por que NO usarlo.
  return 0;
}
