#include <stdio.h>
#include <stdlib.h>

int main(void){
    printf("\n=== 2. Desreferenciacion (Viajando a la memoria) ===\n");
    int x = 42;
    int *ptr_x = &x;

    printf("Valor original apuntado por ptr_x: %d\n", *ptr_x);
    
    // Modificamos el valor de x a través de su puntero
    *ptr_x = 99;
    printf("Nuevo valor de x tras hacer '*ptr_x = 99': %d\n", x);
    
    // Puntero NULL seguro
    int *ptr_nulo = NULL;
    printf("Valor de un puntero NULL (No desreferenciar!): %p\n", (void *)ptr_nulo);

    return 0;
}
