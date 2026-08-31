#include <stdio.h>
#include <stdlib.h>

int main(void){
    printf("\n=== 8. Teaser de Memoria Dinamica (Heap) ===\n");
    // Creamos un arreglo dinamico de 3 enteros usando malloc
    int *dinamico = malloc(3 * sizeof(int));
    if (dinamico != NULL){
        dinamico[0] = 100;
        *(dinamico + 1) = 200; // Demostrando sintaxis equivalente
        dinamico[2] = 300;
        
        printf("Elemento dinamico[1]: %d\n", dinamico[1]);
        
        // REGLA DE ORO: Si pides, devuelves.
        free(dinamico);
        dinamico = NULL; // Evitar el Dangling Pointer (Puntero Colgante)
        printf("Memoria liberada exitosamente, y puntero neutralizado (NULL).\n");
    }

    return 0;
}
