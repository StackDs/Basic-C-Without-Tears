/**
 * Ejemplo 2: Fuga de Memoria (Memory Leak)
 * 
 * Este programa NO genera un Segmentation Fault, termina exitosamente.
 * Pero deja basura en la memoria dinámica, lo que a la larga congela el sistema.
 * 
 * Instrucciones para diagnosticar con Valgrind:
 * 1. Compila con -g: 
 *    gcc -g 02_memory_leak.c -o 02_memory_leak
 * 2. Ejecuta con Valgrind: 
 *    valgrind --leak-check=full ./02_memory_leak
 * 3. Valgrind te indicará "definitely lost" y la línea del malloc()
 *    que olvidaste liberar con free().
 */

#include <stdio.h>
#include <stdlib.h>

void funcion_descuidada() {
    // Pedimos 100 enteros a la memoria dinámica (Heap)
    int *arreglo = (int*)malloc(100 * sizeof(int));
    
    if (arreglo == NULL) return;
    
    arreglo[0] = 99; // Usamos el arreglo
    
    // ERROR: La función termina, el puntero 'arreglo' local se destruye, 
    // pero jamás llamamos a free(arreglo). Esa memoria quedó perdida para siempre.
}

int main(void) {
    printf("Voy a desperdiciar memoria...\n");
    
    // Llamamos a la función 50 veces, perdiendo bloques de memoria en cada llamada
    for (int i = 0; i < 50; i++) {
        funcion_descuidada();
    }
    
    printf("Terminé, pero dejé el Heap hecho un desastre. (¡Pásame por Valgrind!)\n");
    return 0;
}
