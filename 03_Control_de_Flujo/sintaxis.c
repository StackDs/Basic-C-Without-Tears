/**
   ######################################################
   ##                                                  ##
   ##      Control de Flujo: Decisiones y Bucles       ## 
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <stdbool.h>

int main(void) {
  
  /**
     ############################################
     ##                                        ##
     ##  1. Operadores y Logica Basica         ##  
     ##                                        ##
     ############################################
  **/
  printf("=== 1. Operadores y Logica Basica ===\n");
  
  /** Verdad y Falsedad:
   * En C, 0 es Falso. Cualquier otro numero es Verdadero.
   * Cortocircuito logico: && y || se evaluan de izquierda a derecha 
   * y la evaluacion se detiene tan pronto como se conoce el resultado.
   **/
  int divisor = 0;
  int dividendo = 10;
  
  // Si divisor es 0, la primera condición (divisor != 0) es Falsa.
  // Gracias al cortocircuito, C omite evaluar la segunda parte,
  // evitando asi una division por cero que daria un error fatal.
  if (divisor != 0 && (dividendo / divisor > 1)) {
      printf("El resultado es mayor a 1\n");
  } else {
      printf("Cortocircuito en accion: El divisor era 0, pero evitamos el error.\n");
  }


  /**
     ############################################
     ##                                        ##
     ##  2. Condicionales (Toma de decisiones) ##  
     ##                                        ##
     ############################################
  **/
  printf("\n\n=== 2. Condicionales (if / else) ===\n");
  
  /** if, else if, else:
   * Control basico de decisiones. Las llaves {} son obligatorias
   * a nivel moral para evitar errores, incluso con una sola linea.
   **/
  int nota = 85;
  if (nota >= 90) {
      printf("Excelente\n");
  } else if (nota >= 70) {
      printf("Aprobaste con %d. A duras penas, pero aprobaste.\n", nota);
  } else {
      printf("Nos vemos en verano\n");
  }

  /** El Operador Ternario (? :):
   * Un if-else comprimido en una sola expresion.
   * (condicion) ? valor_si_verdadero : valor_si_falso
   **/
  int edad = 25;
  char* bebida = (edad >= 18) ? "Cerveza" : "Cerveza sin alcohol";
  printf("Para alguien de %d anios, le servimos: %s\n", edad, bebida);


  /**
     ############################################
     ##                                        ##
     ##  3. Seleccion Multiple (switch)        ##  
     ##                                        ##
     ############################################
  **/
  printf("\n\n=== 3. Seleccion Multiple (switch) ===\n");
  
  /** Switch y el comportamiento Fall-Through:
   * Solo acepta enteros (int) y caracteres (char).
   * Si omites un 'break', la ejecucion "cae" a los siguientes casos.
   **/
  int opcion = 1;
  printf("Evaluando opcion %d sin un break en el case 1:\n", opcion);
  switch (opcion) {
      case 1:
          printf("-> Elegiste 1\n");
          // ¡Falta el break a proposito para ver el fall-through!
      case 2:
          printf("-> Tambien ejecuto el 2 sin querer (Fall-Through)\n");
          break;
      default:
          printf("-> Opcion invalida\n");
          break;
  }

  /** Agrupacion de casos aprovechando el Fall-Through: **/
  char tecla = 'W';
  printf("\nPresionaste la tecla '%c':\n", tecla);
  switch(tecla) {
      case 'w':
      case 'W':
          printf("-> Accion: Avanzar personaje\n");
          break;
      default:
          printf("-> Tecla no configurada\n");
          break;
  }


  /**
     ############################################
     ##                                        ##
     ##  4. Bucles (Repeticion de tareas)      ##  
     ##                                        ##
     ############################################
  **/
  printf("\n\n=== 4. Bucles (Repeticion de tareas) ===\n");

  /** while: Evalua la condicion antes de entrar al bloque. **/
  int energia = 3;
  printf("--- Ciclo while ---\n");
  while (energia > 0) {
      printf("Energia restante: %d\n", energia);
      energia--;
  }

  /** do-while: Se ejecuta al menos una vez, evalua al final. **/
  printf("\n--- Ciclo do-while ---\n");
  int iteraciones = 1; 
  do {
      printf("Ejecutando iteracion %d garantizada antes de evaluar condicion.\n", iteraciones);
      iteraciones++;
  } while (iteraciones <= 1); // Ya es falso, pero igual se ejecuto una vez

  /** for: Inicializacion, condicion, incremento (o decremento). **/
  printf("\n--- Ciclo for ---\n");
  for (int i = 0; i < 3; i++) {
      printf("Iteracion for: %d\n", i);
  }

  /** Anidamiento de bucles: Un bucle dentro de otro. **/
  printf("\n--- Bucles anidados ---\n");
  for (int fila = 1; fila <= 2; fila++) {
      for (int col = 1; col <= 2; col++) {
          printf("[%d,%d] ", fila, col);
      }
      printf("\n"); // Salto de linea por cada fila terminada
  }


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
