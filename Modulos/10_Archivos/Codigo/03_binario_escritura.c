#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nombre[30];
    float precio;
} Producto;

int main() {
    printf("\n=== 3. Archivos Binarios (Escritura Masiva) ===\n");
    // Creamos un pequeño inventario en memoria (Stack o RAM)
    Producto inventario_original[3] = {
        {101, "Pocion de Vida", 15.5},
        {102, "Espada Larga", 150.0},
        {103, "Escudo de Madera", 50.0}
    };
    
    // Abrimos en modo "wb" (Write Binary)
    FILE *archivo_bin = fopen("inventario.bin", "wb");
    if (archivo_bin != NULL) {
        // Escribimos todo el bloque de memoria de golpe al disco
        // Parametros: origen, tamano de cada elemento, cantidad, archivo
        fwrite(inventario_original, sizeof(Producto), 3, archivo_bin);
        fclose(archivo_bin);
        printf("Archivo 'inventario.bin' guardado con 3 structs.\n");
    }

    return 0;
}
