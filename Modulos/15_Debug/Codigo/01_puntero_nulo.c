/**
   ######################################################
   ##                                                  ##
   ##        Debug: El Puntero Nulo (Segfault)         ##
   ##                                                  ##
   ######################################################
**/

/**
 * Ejemplo 1: El Puntero Nulo (Segmentation Fault)
 * 
 * Instrucciones para depurar con GDB:
 * 1. Compila con -g: 
 *    gcc -g 01_puntero_nulo.c -o 01_puntero_nulo
 * 2. Abre GDB: 
 *    gdb ./01_puntero_nulo
 * 3. Ejecuta el programa dentro de GDB: 
 *    run
 * 4. Cuando explote, pide el rastro de la pila (backtrace): 
 *    bt
 * 5. GDB te dirá exactamente en qué línea intentaste acceder al NULL.
 */

#include <stdio.h>

void causar_desastre(int *ptr) {
    // Intentamos asignar un valor a la memoria donde apunta ptr.
    // Si ptr es NULL, el Sistema Operativo asesinará el programa (Segfault).
    *ptr = 42; 
}

int main(void) {
    printf("Iniciando el programa...\n");
    
    int *puntero_peligroso = NULL;
    
    causar_desastre(puntero_peligroso);
    
    // El programa nunca llegará a esta línea
    printf("Programa finalizado con éxito.\n");
    return 0;
}
