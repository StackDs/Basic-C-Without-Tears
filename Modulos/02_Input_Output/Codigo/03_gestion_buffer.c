#include <stdio.h>

int main(void) {
  /**
     ############################################
     ##                                        ##
     ##      Gestion del buffer de entrada     ##  
     ##                                        ##
     ############################################
  **/

  printf("\n\n=== Gestion del Buffer de Entrada ===\n");

  /** El problema del \n residual:
   * Al usar scanf para numeros, el ENTER (\n) presionado queda en el buffer.
   * Si intentamos leer un char ahora, leera ese \n.
   * Solucion: Limpiar el buffer manualmente con un bucle getchar.
   **/
  int c;
  // Simular ingreso anterior
  printf("Presiona ENTER para continuar simulando un salto de linea residual...");
  getchar();
  
  // Limpiando el buffer
  while ((c = getchar()) != '\n' && c != EOF); 
  
  char una_letra;
  printf("Ingresa una letra favorita: ");
  scanf("%c", &una_letra); 
  printf("Letra leida correctamente: %c\n", una_letra);

  // Limpiamos el buffer de nuevo tras leer el char por el ENTER presionado
  while ((c = getchar()) != '\n' && c != EOF);

  return 0;
}
