/**
   ######################################################
   ##                                                  ##
   ##          Archivos de Texto (Escritura)           ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
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

    return 0;
}
