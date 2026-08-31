#include <stdio.h>
#include <stdlib.h>
// Definir NDEBUG antes de incluir assert.h desactiva los assert (para producción).
// #define NDEBUG 
#include <assert.h>

void procesar_dato_positivo(int dato) {
    // Si dato es negativo, el programa morirá aquí mismo mostrando la línea de error.
    assert(dato >= 0);
    printf("El dato %d es válido y fue procesado.\n", dato);
}

int main(void) {
    printf("\n=== 4. Aserciones y Contratos (assert) ===\n");
    
    printf("Probando assert con un valor positivo (Debería pasar sin problema):\n");
    procesar_dato_positivo(15);
    
    printf("Si descomentas la siguiente línea en el código fuente, el programa abortará.\n");
    // procesar_dato_positivo(-5);

    return 0;
}
