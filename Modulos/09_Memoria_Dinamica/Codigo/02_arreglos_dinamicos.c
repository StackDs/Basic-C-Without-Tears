/**
   ######################################################
   ##                                                  ##
   ##             Arreglos Dinamicos (1D)              ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("\n=== 2. Arreglos Dinamicos (1D) ===\n");
    int n = 5;
    //Pedimos el equivalente a 5 enteros en bytes
    int *arreglo = malloc(n * sizeof(int)); 
    if (arreglo == NULL) {
        return 1;
    }
    
    printf("Llenando el arreglo dinamico...\n");
    for (int i = 0; i < n; i++) {
        arreglo[i] = i * 10;
        printf("arreglo[%d] = %d\n", i, arreglo[i]);
    }

    free(arreglo);
    arreglo = NULL;

    return 0;
}
