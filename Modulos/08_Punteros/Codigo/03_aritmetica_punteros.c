/**
   ######################################################
   ##                                                  ##
   ##              Aritmetica de Punteros              ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <stddef.h>

int main(void){
    printf("\n=== 3. Aritmetica de Punteros ===\n");
    int numeros[5] = {10, 20, 30, 40, 50};
    int *p1 = &numeros[0];
    int *p2 = &numeros[3];
    
    printf("Direccion de p1 (numeros[0]): %p\n", (void *)p1);
    // Un salto avanza sizeof(int) bytes
    printf("Direccion de p1 + 1 (numeros[1]): %p (Salto de %lu bytes)\n", (void *)(p1 + 1), sizeof(int));
    
    // Distancia entre punteros del mismo tipo
    ptrdiff_t distancia = p2 - p1;
    printf("Distancia entre numeros[3] y numeros[0]: %td elementos\n", distancia);

    return 0;
}
