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


  /**
     ############################################
     ##                                        ##
     ##      Declaraciones y asignaciones      ##  
     ##                                        ##
     ############################################
  **/
  
  printf("\n\n=== Declaraciones y asignaciones ===\n");

  /** Declaraciones, asignaciones y actualizaciones:
   * Todas las variables deben declararse explcitamente antes de usarse.
   * Podemos declarar varias en una lnea y darles un valor despus.
   * Para actualizar, C soporta operadores como ++, --, +=, y -=.
   **/
  
  // Declaracion multiple
  int IronMaiden, SOAD, Metallica;

  // Asignacion posterior
  IronMaiden = 1;
  SOAD = 2;
  Metallica = 3;
  
  printf("Bandas (Asignacion multiple): IronMaiden = %d, SOAD = %d, Metallica = %d\n", IronMaiden, SOAD, Metallica);

  //Declaracion unitaria por linea y asignacion inmediata
  int Megadeth = 4;
  int RCHP = 5;
  int MCR = 6;

  printf("Bandas (Declaracion unitaria): Megadeth = %d, RCHP = %d, MCR = %d\n", Megadeth, RCHP, MCR);

  // Demostracion de variables no inicializadas (Basura en memoria)
  int variable_basura;
  printf("\n--- Demostracion de variable sin inicializar ---\n");
  printf("Valor de variable_basura: %d (Este valor es impredecible)\n", variable_basura);

  printf("\n--- Operadores de actualizacion ---\n");
  int contador = 10;
  contador++; //Incremento en 1
  printf("Contador primer incremento = %d\n", contador); 
  contador +=5; // Equivalente para sumar 5
  printf("Contador despues de sumar 5 = %d\n", contador); 

  // Nota rapida sobre los formatos de printf (lo veremos a fondo despues):
  // %d -> enteros (int)
  // %f -> flotantes (float/double)
  // %c -> caracteres (char)
  // %s -> strings (cadenas de texto)

  /** Post y pre incremento
   *  En C existen 2 tipos de incrementos:
   *  Pre incremento: ++x suma uno a la variable antes de usar su valor en una expresion
   *  Post incremento: x++ usa el valor actual de la variable y la incrementa despues
   *  Como se ve a continuacion
   **/
  
  int i;

  // POSTINCREMENTO
  i = 5;
  printf("\nPost incremento:\n");
  printf("Valor original de i: %d\n", i);
  printf("Resultado de i++: %d\n", i++);
  printf("Valor de i despus: %d\n", i);

  // PREINCREMENTO
  i = 5;
  printf("\nPre incremento:\n");
  printf("Valor original de i: %d\n", i);
  printf("Resultado de ++i: %d\n", ++i);
  printf("Valor de i despus: %d\n", i);

  /**
     ###########################################################
     ##                                                       ##
     ##         Representacion de constantes                  ##
     ##                                                       ##
     ###########################################################
  **/
  
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

  /**
     ###########################################################
     ##                                                       ##
     ##               Caracteres en C y Strings               ##
     ##                                                       ##
     ###########################################################
  **/

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
