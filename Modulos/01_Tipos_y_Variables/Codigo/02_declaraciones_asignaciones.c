#include<stdio.h>

int main(void){
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

  // Operador Modulo (%)
  int dividendo = 10;
  int divisor = 3;
  int resto = dividendo % divisor; // Devuelve el resto de la division entera (10 / 3 = 3, resto = 1)
  printf("El resto de dividir %d entre %d es: %d\n", dividendo, divisor, resto);

  /** L-values y R-values
   * Un lvalue (left-value) representa un objeto con memoria persistente (ej: una variable 'recipiente').
   * Un rvalue (right-value) representa un valor temporal o literal (ej: 100).
   * Solo los lvalues pueden estar a la izquierda de un operador de asignacion (=).
   **/
  int recipiente = 100; // 'recipiente' es lvalue, '100' es rvalue.
  // 100 = recipiente; // Esto daria error de compilacion: lvalue required as left operand of assignment

  // Nota rapida sobre los formatos de printf (lo veremos a fondo despues):
  // %d / %i -> enteros (int, short)
  // %u -> enteros sin signo (unsigned int)
  // %ld / %lld -> enteros largos (long, long long)
  // %f -> flotantes (float)
  // %lf -> flotantes de doble precision (double)
  // %Lf -> flotantes de precision extendida (long double)
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

  return 0;
}
