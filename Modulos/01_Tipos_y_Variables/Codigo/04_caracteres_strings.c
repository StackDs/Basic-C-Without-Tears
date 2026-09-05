/**
   ######################################################
   ##                                                  ##
   ##            Caracteres en C y Strings             ##
   ##                                                  ##
   ######################################################
**/

#include<stdio.h>

int main(void){
  printf("\n\n=== Caracteres en C y Strings ===\n");

  /** Caracteres
   * Como comente en el archivo de teoria, los strings los veremos en profundidad mas adelante
   * Un string en C no es mas que un arreglo de caracteres
   * Puedes reservar el tamao explicitamente o dejar que se calcule solo.
   **/

  char invitacion[20] = "Vamos a tomar?";

  printf("%s\n\n", invitacion); 
  
  return 0;
}
