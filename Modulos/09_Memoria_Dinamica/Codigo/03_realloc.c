/**
   ######################################################
   ##                                                  ##
   ##         realloc: Redimensionando Memoria         ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 5;
    int *arreglo = malloc(n * sizeof(int)); 
    if (arreglo == NULL) {
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        arreglo[i] = i * 10;
    }
    
    printf("\n=== 3. realloc: Redimensionando la memoria ===\n");
    printf("Agrandando el arreglo de 5 a 8 elementos...\n");
    int nuevo_tamano = 8;
    
    // Nunca hagas 'arreglo = realloc(arreglo, ...)' directamente. Si falla el realloc, perderás el puntero original.
    int *temp = realloc(arreglo, nuevo_tamano * sizeof(int));
    if (temp != NULL) {
        arreglo = temp; // Actualizamos de forma segura
        
        // Inicializamos los nuevos espacios (la memoria vieja se conserva intacta)
        for (int i = 5; i < 8; i++) {
            arreglo[i] = i * 10;
        }
        
        printf("Arreglo redimensionado exitosamente:\n");
        for (int i = 0; i < 8; i++) {
            printf("%d ", arreglo[i]);
        }
        printf("\n");
    } else {
        // Si entra acá, significa que no hubo RAM suficiente. 
        // Pero el arreglo original sigue intacto, no hay fuga de memoria.
        printf("Fallo realloc, pero el arreglo original sigue a salvo.\n");
    }
    
    free(arreglo);
    arreglo = NULL;

    return 0;
}
