/**
   ######################################################
   ##                                                  ##
   ##           Punteros Genericos (void *)            ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>

int main(void){
    printf("\n=== 6. Punteros Genericos (void *) ===\n");
    void *comodin;
    float f = 3.1416;
    comodin = &f;
    // printf("%f", *comodin); // ESTO DA ERROR DE COMPILACION (no se sabe el tamaño)
    
    // Debemos "castear" el comodín antes de desreferenciarlo
    printf("Valor float leido desde comodin: %f\n", *(float *)comodin);

    return 0;
}
