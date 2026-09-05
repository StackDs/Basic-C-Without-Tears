/**
   ######################################################
   ##                                                  ##
   ##     Debug: Desbordamiento Entero (Overflow)      ##
   ##                                                  ##
   ######################################################
**/

/**
 * Ejemplo 5: Desbordamiento de Entero (Integer Overflow)
 * 
 * Ocurre cuando intentas guardar en una variable un número más grande 
 * de lo que su capacidad máxima (en bytes) puede soportar.
 * 
 * En C, desbordar un entero con signo ('int', 'short') genera un
 * "Comportamiento Indefinido". Típicamente, el número colapsa y da la  
 * vuelta (wrap around) convirtiéndose en un número negativo extremo.
 * 
 * Instrucciones para diagnosticar:
 * GDB y Valgrind no son buenos atrapando esto, porque no corrompe la RAM.
 * Aquí usamos una herramienta moderna que viene con GCC: Undefined Behavior Sanitizer (UBSan).
 * 
 * 1. Compila con esta bandera especial: 
 *    gcc -g -fsanitize=undefined 05_integer_overflow.c -o 05_integer_overflow
 * 2. Ejecuta: 
 *    ./05_integer_overflow
 * 3. El programa se ejecutará, pero el "sanitizer" gritará en color rojo 
 *    la línea exacta donde ocurrió la anomalía matemática.
 */

#include <stdio.h>
#include <limits.h> // Librería estándar para ver límites como INT_MAX

int main(void) {
    // INT_MAX suele ser 2,147,483,647 en sistemas de 32 y 64 bits
    printf("El valor máximo que puede guardar este 'int' es: %d\n", INT_MAX);
    
    int cuenta_bancaria = INT_MAX;
    
    printf("Saldo de tu cuenta bancaria: $%d\n", cuenta_bancaria);
    
    printf("¡Felicidades! Acabas de recibir un depósito de $10.\n");
    
    // ERROR MATEMÁTICO: Sumar por encima del límite máximo
    cuenta_bancaria = cuenta_bancaria + 10;
    
    // Como desbordaste la memoria del entero, el bit de signo se altera,
    // y el número se vuelve un valor negativo inmenso.
    printf("Tras el depósito, tu nuevo saldo es... $%d\n", cuenta_bancaria);
    printf("¡Ups, ahora le debes tu alma al banco!\n");
    
    return 0;
}
