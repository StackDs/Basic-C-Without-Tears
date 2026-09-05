/**
   ######################################################
   ##                                                  ##
   ##           Representacion de Constantes           ##
   ##                                                  ##
   ######################################################
**/

#include<stdio.h>

int main(void){
  printf("\n\n=== Representacion de constantes ===\n");
  
  /** Representacin de Constantes:
   * C permite forzar el tipo y base numrica de las constantes:
   * - Decimales (ej: 1234)
   * - Octales: Llevan un cero a la izquierda (ej: 037)
   * - Hexadecimales: Comienzan con 0x (ej: 0x1F)
   * Las constantes de carcter son nmeros enteros basados en la tabla ASCII.
   **/
  
  int octal = 037;
  int hexadecimal = 0x1F;

  // Imprimiendo bases numericas
  printf("Valor octal (037) en decimal: %d\n", octal);
  printf("Valor hexadecimal (0x1F) en decimal: %d\n\n", hexadecimal);

  char c_num = '7';
  int valor_real = c_num - '0'; // Corregido 'l' por '0'

  // Imprimir el valor del '7' en la tabla ASCII
  printf("El valor del caracter '%c' en la tabla ASCII es: %d\n", c_num, c_num);

  // Valor real almacenado usando el valor asociado en la tabla ASCII para la operacion
  printf("El caracter '%c' equivale al numero real: %d\n", c_num, valor_real);

  /** Variables constantes
   * El calificador 'const' anuncia que su valor no sera modificado.
   * Si se intenta cambiar, el compilador emitira un error.
   **/

  const double e = 2.7182818284;
  printf("\nValor de la constante matematica 'e': %.10f\n", e);

  return 0;
}
