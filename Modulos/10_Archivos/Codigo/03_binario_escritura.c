/**
   ######################################################
   ##                                                  ##
   ##       Archivos Binarios (Escritura Masiva)       ##
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
    printf("\n=== 3. Archivos Binarios (Escritura Masiva) ===\n");
    // Creamos un pequeño inventario en memoria (Stack o RAM)
    Producto inventario_original[3] = {
        {101, "Pocion de Vida", 15.5},
        {102, "Espada Larga", 150.0},
        {103, "Escudo de Madera", 50.0}
    };
    
    // Abrimos en modo "wb" (Write Binary)
    FILE *archivo_bin = fopen("inventario.bin", "wb");
    if (archivo_bin == NULL) {
        printf("Error: No se pudo crear el archivo binario.\n");
        return 1;
    }
    
    // Escribimos todo el bloque de memoria de golpe al disco
    // Parametros: origen, tamano de cada elemento, cantidad, archivo
    size_t escritos = fwrite(inventario_original, sizeof(Producto), 3, archivo_bin);
    if (escritos != 3) {
        printf("Advertencia: Solo se escribieron %zu de 3 structs.\n", escritos);
    }
    fclose(archivo_bin);
    printf("Archivo 'inventario.bin' guardado con 3 structs.\n");

    return 0;
}
