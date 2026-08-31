/**
   ######################################################
   ##                                                  ##
   ##                  Tipos y variables               ## 
   ##                                                  ##
   ######################################################
**/

#include<stdio.h>

int main(void){
  printf("=== Tipos de datos primitivos y modificadores ===\n");

  /** Tipos de datos Primitivos y sus Tamaños:
   * Existen 4 tipos de datos bsicos que determinan los valores vlidos:
   * - char: Un solo byte, para caracteres.
   * - int: Un nmero entero (generalmente 4 bytes).
   * - float y double: Nmeros de precisin simple y doble.
   * Se les pueden aplicar modificadores como short, long o unsigned.
   **/
  char letra = 'r';
  int entero = 1024;
  float flotante = 32.0f;
  double doble = 3.1425926535;

  // Imprimir los valores de los tipos basicos
  printf("\n--- Valores de tipos basicos ---\n");
  printf("letra: %c\n", letra);
  printf("entero: %d\n", entero);
  printf("flotante: %.2f\n", flotante);
  printf("doble: %.10f\n", doble);

  // Modificadores
  short entero_corto = 30000;
  unsigned int entero_sin_signo = 4000000000u;
  long entero_largo = 123456789L;

  // Imprimir los valores con modificadores
  printf("\n--- Valores con modificadores ---\n");
  printf("entero_corto: %d\n", entero_corto);
  printf("entero_sin_signo: %u\n", entero_sin_signo);
  printf("entero_largo: %ld\n", entero_largo);

  // Imprimir tamaos en bytes (depende de la arquitectura, tipicamente x86-64)
  // La funcion 'sizeof' devuelve el tamao en bytes que ocupa un tipo de dato o variable en memoria
  printf("\n--- Tamanios en memoria ---\n");
  printf("Tamanio de char: %zu bytes\n", sizeof(char));  
  printf("Tamanio de short: %zu bytes\n", sizeof(short));
  printf("Tamanio de int: %zu bytes\n", sizeof(int));
  printf("Tamanio de long: %zu bytes\n", sizeof(long));
  printf("Tamanio de float: %zu bytes\n", sizeof(float));
  printf("Tamanio de double: %zu bytes\n", sizeof(double));

  return 0;
}
