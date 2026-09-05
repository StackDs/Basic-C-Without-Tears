/**
   ######################################################
   ##                                                  ##
   ##        Archivos Binarios (Lectura Masiva)        ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nombre[30];
    float precio;
} Producto;

int main(void) {
    printf("\n=== 4. Archivos Binarios (Lectura Masiva) ===\n");
    // Preparamos un arreglo vacío en memoria para recibir los datos
    Producto inventario_cargado[3];
    
    // Abrimos en modo "rb" (Read Binary)
    FILE *archivo_bin_leer = fopen("inventario.bin", "rb");
    if (archivo_bin_leer == NULL) {
        printf("Error: No se pudo abrir 'inventario.bin' para lectura.\n");
        return 1;
    }
    
    // Leemos masivamente desde el disco directo a nuestro arreglo y validamos
    size_t leidos = fread(inventario_cargado, sizeof(Producto), 3, archivo_bin_leer);
    fclose(archivo_bin_leer);
    
    if (leidos != 3) {
        printf("Advertencia: Se esperaban 3 registros pero se leyeron %zu.\n", leidos);
    }
    
    printf("Inventario recuperado del disco (%zu elementos leidos):\n", leidos);
    for (size_t i = 0; i < leidos; i++) {
        printf(" - ID: %d | %s | $%.2f\n", 
            inventario_cargado[i].id, 
            inventario_cargado[i].nombre, 
            inventario_cargado[i].precio);
    }

    return 0;
}
