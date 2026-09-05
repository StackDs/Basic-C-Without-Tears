/**
   ######################################################
   ##                                                  ##
   ##      Arreglos Multidimensionales (Matrices)      ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>

int main(void){
    printf("\n=== 5. Arreglos Multidimensionales (Matrices) ===\n");
    // Matriz de 3 filas y 4 columnas
    int matriz[3][4] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };
    
    // Recorrido Row-major order (Bucle mas profundo itera en la ultima dimension)
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            printf("%2d ", matriz[i][j]); // %2d para alinear los numeros de un solo digito
        }
        printf("\n");
    }

    return 0;
}
