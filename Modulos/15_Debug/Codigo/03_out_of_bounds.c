/**
   ######################################################
   ##                                                  ##
   ##     Debug: Fuera de Limites (Out of Bounds)      ##
   ##                                                  ##
   ######################################################
**/

/**
 * Ejemplo 3: Violación de Segmento (Out of Bounds) / Acceso inválido
 * 
 * Intentar leer o escribir más allá del límite de un arreglo de memoria dinámica.
 * 
 * Instrucciones para diagnosticar con Valgrind:
 * 1. Compila con -g: 
 *    gcc -g 03_out_of_bounds.c -o 03_out_of_bounds
 * 2. Ejecuta con Valgrind: 
 *    valgrind ./03_out_of_bounds
 * 3. Lee el reporte: Valgrind gritará "Invalid write of size 4" y te dirá 
 *    la línea exacta donde escribiste fuera de los límites.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Pedimos memoria para solo 5 enteros (índices del 0 al 4)
    int *datos = malloc(5 * sizeof(int));
    
    if (datos == NULL) return 1;

    printf("Escribiendo datos dentro de los límites...\n");
    for (int i = 0; i < 5; i++) {
        datos[i] = i * 10; 
    }

    printf("Cometiendo un crimen de memoria...\n");
    // ERROR: Intentamos escribir en el índice 5 y 10. ¡Esa RAM no nos pertenece!
    // Esto corrompe la memoria adyacente (Heap buffer overflow).
    datos[5] = 999;
    datos[10] = 999;
    
    free(datos); // Valgrind detectará la corrupción incluso si liberamos correctamente

    printf("Dependiendo del OS, puede que explote con Segfault o puede que termine sin avisar.\n");
    return 0;
}
