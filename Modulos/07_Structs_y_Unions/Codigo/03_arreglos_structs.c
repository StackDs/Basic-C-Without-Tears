/**
   ######################################################
   ##                                                  ##
   ##     Arreglos de Estructuras (Base de Datos)      ##
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
    printf("\n=== 4. Arreglos de Estructuras (Base de Datos en RAM) ===\n");
    Producto inventario[3] = {
        {"Laptop", 999.99, 10},
        {"Mouse", 25.50, 50},
        {"Teclado", 45.00, 30}
    };
    
    // Iteracion (Busqueda)
    printf("Buscando productos menores a $50:\n");
    for(int i = 0; i < 3; i++){
        if (inventario[i].precio < 50.0){
            printf("- %s ($%.2f)\n", inventario[i].nombre, inventario[i].precio);
        }
    }

    return 0;
}
