/**
   ######################################################
   ##                                                  ##
   ##       Matrices Dinamicas (Punteros Dobles)       ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("\n=== 5. Matrices Dinamicas (Punteros Dobles) ===\n");
    int filas = 3;
    int columnas = 4;
    
    // Asignamos arreglo principal (las filas que guardan punteros int*)
    int **matriz = malloc(filas * sizeof(int *));
    if (matriz == NULL) {
        fprintf(stderr, "Error: Fallo al asignar memoria para las filas.\n");
        return 1;
    }
    
    // Asignamos columnas (arreglos 1D) a cada fila con validación
    for (int i = 0; i < filas; i++) {
        matriz[i] = malloc(columnas * sizeof(int));
        if (matriz[i] == NULL) {
            fprintf(stderr, "Error: Fallo al asignar memoria para la fila %d.\n", i);
            // Liberamos las filas asignadas previamente para evitar memory leak
            for (int k = 0; k < i; k++) {
                free(matriz[k]);
            }
            free(matriz);
            return 1;
        }
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = (i + 1) * (j + 1); // Rellenamos con matemática basica
        }
    }
    
    printf("Matriz dinamica 3x4:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    // Liberacion (Deep Free de la matriz, de adentro hacia afuera)
    for (int i = 0; i < filas; i++) {
        free(matriz[i]); // Liberamos las columnas individuales
        matriz[i] = NULL;
    }
    free(matriz); // Liberamos el array de punteros principal
    matriz = NULL;
    printf("Matriz dinamica liberada correctamente (De adentro hacia afuera).\n");

    return 0;
}
