/**
   ######################################################
   ##                                                  ##
   ##      Debug: Desbordamiento de Pila (Stack)       ##
   ##                                                  ##
   ######################################################
**/

/**
 * Ejemplo 4: Desbordamiento de Pila (Stack Overflow)
 * 
 * Ocurre cuando haces demasiadas llamadas a funciones recursivas infinitas
 * o cuando declaras arreglos locales gigantescos. Agotas la memoria "Stack".
 * 
 * Instrucciones para depurar con GDB:
 * 1. Compila con -g: 
 *    gcc -g 04_stack_overflow.c -o 04_stack_overflow
 * 2. Ejecuta en GDB: 
 *    gdb ./04_stack_overflow
 * 3. Comando: run
 * 4. Cuando ocurra el Segfault, usa el comando 'bt' (backtrace). Verás MILES 
 *    de llamadas a la misma función, probando que caíste en recursión infinita.
 */

#include <stdio.h>

// Una función que se llama a sí misma para siempre (sin condición de salida)
void recursion_infinita(int contador) {
    // Cada vez que llamamos a la función, se crea un nuevo 'contador' en el Stack.
    // Eventualmente, consumiremos todos los Megabytes asignados al Stack.
    printf("Llamada número: %d\n", contador);
    
    // ERROR: Llamada recursiva sin ningún if que la detenga
    recursion_infinita(contador + 1);
}

int main(void) {
    printf("Iniciando el descenso a la locura...\n");
    
    // Inicia la pesadilla recursiva
    recursion_infinita(1);
    
    // El programa nunca llegará aquí, morirá asfixiado.
    return 0;
}
