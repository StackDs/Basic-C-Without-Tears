#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nombre[30];
    float precio;
} Producto;

int main() {
    printf("\n=== 4. Archivos Binarios (Lectura Masiva) ===\n");
    // Preparamos un arreglo vacío en memoria para recibir los datos
    Producto inventario_cargado[3];
    
    // Abrimos en modo "rb" (Read Binary)
    FILE *archivo_bin_leer = fopen("inventario.bin", "rb");
    if (archivo_bin_leer != NULL) {
        // Leemos masivamente desde el disco directo a nuestro arreglo
        fread(inventario_cargado, sizeof(Producto), 3, archivo_bin_leer);
        fclose(archivo_bin_leer);
        
        printf("Inventario recuperado del disco:\n");
        for (int i = 0; i < 3; i++) {
            printf(" - ID: %d | %s | $%.2f\n", 
                inventario_cargado[i].id, 
                inventario_cargado[i].nombre, 
                inventario_cargado[i].precio);
        }
    }

    return 0;
}
