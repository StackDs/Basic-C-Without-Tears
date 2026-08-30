/**
   ######################################################
   ##                                                  ##
   ##           Manejo de Archivos en C                ## 
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definimos un struct para probar los archivos binarios
typedef struct {
    int id;
    char nombre[30];
    float precio;
} Producto;

int main() {
    printf("\n=== 1. Archivos de Texto (Escritura) ===\n");
    // Abrimos en modo "w" (Write). ¡Si el archivo ya existe, se borrará!
    FILE *archivo_txt = fopen("mi_texto.txt", "w");
    
    // Validación obligatoria
    if (archivo_txt == NULL) {
        printf("Error: No se pudo crear el archivo.\n");
        return 1;
    }
    
    // Usamos fprintf igual que un printf
    fprintf(archivo_txt, "Hola, disco duro!\n");
    fprintf(archivo_txt, "Tenemos %d vidas restantes.\n", 3);
    
    // Usamos fputs para texto plano sin formatear
    fputs("Adios, archivo.\n", archivo_txt);
    
    // Cierre obligatorio
    fclose(archivo_txt);
    printf("Archivo 'mi_texto.txt' creado y escrito exitosamente.\n");

    printf("\n=== 2. Archivos de Texto (Lectura Segura con EOF) ===\n");
    // Abrimos en modo "r" (Read).
    FILE *archivo_leer = fopen("mi_texto.txt", "r");
    if (archivo_leer == NULL) {
        printf("Error: Archivo no encontrado.\n");
        return 1;
    }
    
    printf("Contenido del archivo:\n");
    char buffer[100];
    // Forma correcta de iterar: leemos, comprobamos que no haya fallado, luego procesamos
    while (fgets(buffer, sizeof(buffer), archivo_leer) != NULL) {
        // Imprimimos el texto que leimos (fgets incluye el salto de línea)
        printf(" -> %s", buffer);
    }
    
    // Forma alternativa con EOF usando fgetc
    /*
    rewind(archivo_leer); // Volver al inicio
    int c;
    while (1) {
        c = fgetc(archivo_leer);
        if (c == EOF) break;
        putchar(c);
    }
    */
    
    fclose(archivo_leer);

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

    printf("\n=== 5. Navegacion (fseek y ftell) ===\n");
    FILE *archivo_peso = fopen("inventario.bin", "rb");
    if (archivo_peso != NULL) {
        // 1. Mover el cursor al final (offset 0, relativo a SEEK_END)
        fseek(archivo_peso, 0, SEEK_END);
        
        // 2. Preguntar en qué byte estamos
        long peso = ftell(archivo_peso);
        printf("El archivo 'inventario.bin' pesa exactamente: %ld bytes\n", peso);
        printf("(Esto tiene sentido porque 3 structs x %lu bytes = %lu bytes)\n", sizeof(Producto), 3 * sizeof(Producto));
        
        // Volver al principio
        rewind(archivo_peso);
        // Ahora el cursor estaria en 0 de nuevo
        
        fclose(archivo_peso);
    }

    return 0;
}
