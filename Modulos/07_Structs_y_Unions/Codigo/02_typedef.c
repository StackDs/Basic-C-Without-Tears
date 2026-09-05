/**
   ######################################################
   ##                                                  ##
   ##            Simplificacion con typedef            ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>

typedef struct {
    char nombre[30];
    float precio;
    int stock;
} Producto;

int main(void){
    printf("\n=== 3. Simplificacion con typedef ===\n");
    // Usamos 'Producto' como si fuera int o float
    Producto p1 = {"Laptop", 999.99, 10};
    printf("Producto creado con typedef: %s a $%.2f\n", p1.nombre, p1.precio);

    return 0;
}
