/**
   ######################################################
   ##                                                  ##
   ##             La Trampa de los Limites             ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>

int main(void){
    printf("\n=== 4. La Trampa de los Limites (Comentada para sobrevivir) ===\n");
    // Si descomentas esto, podrias causar un Segmentation Fault
    // int edades[5] = {18, 22, 35, 40, 19};
    // edades[10] = 666; 
    // printf("Peligro inminente: %d\n", edades[10]);
    printf("C no te detendra si intentas acceder al indice 10 de un arreglo de 5. No lo hagas.\n");

    return 0;
}
