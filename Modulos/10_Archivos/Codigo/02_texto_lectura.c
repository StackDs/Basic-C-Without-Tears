/**
   ######################################################
   ##                                                  ##
   ##        Archivos de Texto (Lectura Segura)        ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
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
    
    fclose(archivo_leer);

    return 0;
}
