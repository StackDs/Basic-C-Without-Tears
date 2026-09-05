/**
   ######################################################
   ##                                                  ##
   ##              malloc y free Basicos               ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("\n=== 1. malloc y free basicos ===\n");
    // Pedimos memoria cruda del tamaño de 1 entero
    int *ptr_entero = malloc(sizeof(int));
    
    // Regla de Oro 1: Validar siempre si el OS nos dio la memoria
    if (ptr_entero == NULL) {
        printf("Error fatal: No se pudo asignar memoria.\n");
        return 1;
    }
    
    *ptr_entero = 42;
    printf("Valor guardado en el Heap: %d\n", *ptr_entero);
    
    // Regla de Oro 2: Liberar la memoria
    free(ptr_entero);
    // Regla de Oro 3: Neutralizar el puntero para evitar Dangling Pointers
    ptr_entero = NULL;
    printf("Memoria liberada y puntero seteado a NULL.\n");

    return 0;
}
