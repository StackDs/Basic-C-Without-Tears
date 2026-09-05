/**
   ######################################################
   ##                                                  ##
   ##         La Dualidad: Arreglos y Punteros         ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>

int main(void){
    printf("\n=== 4. La Dualidad: Arreglos y Punteros ===\n");
    int numeros[5] = {10, 20, 30, 40, 50};
    printf("El nombre 'numeros' por si solo decae en su direccion base: %p\n", (void *)numeros);
    printf("numeros[2] es: %d\n", numeros[2]);
    printf("*(numeros + 2) es: %d (Equivalencia absoluta)\n", *(numeros + 2));
    
    printf("Iterando arreglo con pura aritmetica de punteros:\n");
    for(int *p = numeros; p < numeros + 5; p++){
        printf("%d ", *p);
    }
    printf("\n");

    return 0;
}
