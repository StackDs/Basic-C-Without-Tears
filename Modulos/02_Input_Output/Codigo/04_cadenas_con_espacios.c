#include <stdio.h>
#include <string.h>

int main(void) {
  /**
     ###########################################################
     ##                                                       ##
     ##          Captura de Cadenas con Espacios              ##
     ##                                                       ##
     ###########################################################
  **/

  printf("\n\n=== Captura de Cadenas con Espacios ===\n");

  /** El problema de scanf con strings:
   * scanf se detiene al leer un espacio en blanco.
   * Para leer lineas enteras de forma segura, usamos fgets.
   **/
  char nombre_completo[50];
  
  printf("Ingresa tu nombre completo y apellidos (se aceptan espacios): ");
  fgets(nombre_completo, sizeof(nombre_completo), stdin);
  
  // fgets guarda el \n final si cabe, lo eliminamos con strcspn
  nombre_completo[strcspn(nombre_completo, "\n")] = '\0';
  
  printf("Tu nombre completo procesado por fgets es: %s\n", nombre_completo);

  return 0;
}
