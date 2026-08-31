#include <stdio.h>
#include <stdlib.h>

int dividir_enteros(int a, int b, int *resultado) {
    if (b == 0) {
        return -1; // Fallo lógico
    }
    *resultado = a / b;
    return 0; // Éxito
}

int main(void) {
    printf("\n=== 1. Patrones de Códigos de Retorno ===\n");
    
    int res = 0;
    
    // Comprobamos el código de retorno inmediatamente
    if (dividir_enteros(10, 0, &res) == -1) {
        fprintf(stderr, "[Error] No se puede dividir entre cero (Flujo stderr).\n");
    } else {
        printf("Resultado: %d\n", res);
    }
    
    if (dividir_enteros(10, 2, &res) == 0) {
        printf("Resultado exitoso: %d (Flujo stdout)\n", res);
    }

    return 0;
}
