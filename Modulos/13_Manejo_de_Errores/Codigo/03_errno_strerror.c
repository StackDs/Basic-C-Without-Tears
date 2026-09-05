/**
   ######################################################
   ##                                                  ##
   ##             Uso de errno y strerror              ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(void) {
    printf("\n=== 3. Uso de errno y traducción de errores ===\n");
    // Vamos a forzar un error del sistema intentando abrir un archivo inexistente
    
    // Es buena práctica limpiar errno antes de la operación crítica
    errno = 0;
    
    FILE *archivo = fopen("ruta_falsa/archivo_inexistente.txt", "r");
    
    // ¡Solo evaluamos errno SI Y SOLO SI la función falló!
    if (archivo == NULL) {
        // En este punto, errno contiene el número de error específico del sistema
        printf("Ocurrió el error interno número: %d\n", errno);
        
        // Método 1: perror 
        // Imprime tu mensaje y la descripción del error automáticamente en stderr
        perror("[perror] Fallo al abrir el archivo");
        
        // Método 2: strerror 
        // Obtiene la cadena de texto del error, permitiendo formateo libre usando fprintf
        fprintf(stderr, "[strerror] Ocurrió un desastre: %s\n", strerror(errno));
    }

    return 0;
}
