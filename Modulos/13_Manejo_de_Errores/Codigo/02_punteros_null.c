/**
   ######################################################
   ##                                                  ##
   ##         Comprobacion de Punteros (NULL)          ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <stdlib.h>

int* crear_arreglo(int tamano) {
    if (tamano <= 0) {
        return NULL; // Fallo de lógica, el tamaño no tiene sentido
    }
    // Intentamos asignar memoria (malloc en sí mismo devuelve NULL si falla)
    int *ptr = malloc(tamano * sizeof(int));
    return ptr; 
}

int main(void) {
    printf("\n=== 2. Comprobación de Punteros (NULL) ===\n");
    
    int *mi_arreglo = crear_arreglo(-5);
    if (mi_arreglo == NULL) {
        fprintf(stderr, "[Error] No se pudo crear el arreglo. Tamaño inválido o falta memoria.\n");
    }

    return 0;
}
