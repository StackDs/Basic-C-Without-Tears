#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nombre[30];
    float precio;
} Producto;

int main() {
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
