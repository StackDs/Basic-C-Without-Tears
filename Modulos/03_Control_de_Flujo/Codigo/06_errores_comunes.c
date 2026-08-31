#include <stdio.h>
#include <stdbool.h>

int main(void) {
  /**
     ############################################
     ##                                        ##
     ##  6. Errores Comunes (Cuidado)          ##  
     ##                                        ##
     ############################################
  **/
  printf("\n\n=== 6. Errores Comunes de Sintaxis ===\n");
  
  /** Asignacion vs Comparacion (x = 5 en vez de x == 5) **/
  int x = 0;
  // Si pusieramos if (x = 5), reasignaria x a 5 y el if seria SIEMPRE verdadero.
  if (x == 5) {
      printf("Esto no se imprimira porque x vale %d.\n", x);
  } else {
      printf("Operador == usado correctamente. x vale %d.\n", x);
  }

  /** Olvidar llaves o indentacion engañosa:
   * Visualmente parece que el descuento depende del if,
   * pero sin llaves, solo el printf le pertenece.
   **/
  int saldo = 100;
  if (saldo > 500) {
      printf("Transaccion millonaria aprobada.\n");
  }
  saldo = saldo - 10; // Se ejecuta SIEMPRE porque esta fuera de las llaves del if
  printf("Saldo tras cobrar mantenimiento: %d\n", saldo);

  return 0;
}
