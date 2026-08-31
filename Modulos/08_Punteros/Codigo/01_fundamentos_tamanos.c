#include <stdio.h>
#include <stdlib.h>

int main(void){
    printf("\n=== 1. Fundamentos: Direcciones y Tamanos ===\n");
    int x = 42;
    int *ptr_x = &x; // ptr_x guarda la dirección física de x
    
    printf("Valor de x: %d\n", x);
    printf("Direccion de x en RAM: %p\n", (void *)&x);
    printf("Valor guardado en ptr_x: %p\n", (void *)ptr_x);
    
    // Todos los punteros pesan lo mismo (normalmente 8 bytes en 64 bits)
    printf("Tamano de int: %lu bytes\n", sizeof(int));
    printf("Tamano de int*: %lu bytes\n", sizeof(int *));
    printf("Tamano de double*: %lu bytes\n", sizeof(double *));
    printf("Tamano de char*: %lu bytes\n", sizeof(char *));

    return 0;
}
