#include <stdio.h>
#include <string.h>

int main(void) {
  /**
     ######################################################
     ##                                                  ##
     ##        Input, Output y el caos del Buffer        ## 
     ##                                                  ##
     ######################################################
  **/
  printf("=== Salida de Datos (Output) ===\n");

  /** Uso basico y secuencias de escape:
   * La funcion printf permite imprimir texto formateado.
   * - \n: Salto de linea
   * - \t: Tabulador
   * - \\: Barra invertida
   * - \": Comillas dobles
   **/
  printf("\n--- Uso basico ---\n");
  printf("Hola Mundo\n");
  printf("Me llamo \"C\" y uso una barra \\.\n");
  printf("Esto usa\tun\ttabulador.\n");

  /** Especificadores de formato:
   * %d o %i para enteros (int, short)
   * %u para enteros sin signo (unsigned int)
   * %ld / %lld para enteros largos (long, long long)
   * %f para flotantes (float)
   * %lf para flotantes de doble precision (double)
   * %Lf para flotantes de precision extendida (long double)
   * %c para caracteres
   * %s para strings
   **/
  printf("\n--- Especificadores de formato ---\n");
  int edad = 25;
  float peso = 70.5;
  char inicial = 'J';
  char nombre_corto[] = "Juan";
  printf("Tengo %d anios, peso %f kg. Inicial: %c, Nombre: %s\n", edad, peso, inicial, nombre_corto);

  /** Formateo de precision y alineacion:
   * Podemos controlar los decimales (%.2f), el relleno (%04d) 
   * y la alineacion izquierda o derecha (%-10s).
   **/
  printf("\n--- Formateo y precision ---\n");
  printf("Precio (2 decimales): $%.2f\n", 19.999);
  printf("ID con relleno: [%04d]\n", 7);
  printf("Alineado a la izquierda: [%-10s] <- fin\n", "C");

  /** Impresion de numeros en otras bases:
   * %x / %X para Hexadecimal
   * %o para Octal
   **/
  printf("\n--- Bases numericas ---\n");
  int numero = 255;
  printf("Decimal: %d, Hexadecimal: %X, Octal: %o\n", numero, numero, numero);

  /** Alternativas simples a printf:
   * puts() imprime una cadena y agrega salto de linea automaticamente.
   * putchar() imprime un solo caracter en pantalla.
   **/
  printf("\n--- puts() y putchar() ---\n");
  puts("Man you got a light?");
  putchar('A');
  putchar('\n');

  return 0;
}
