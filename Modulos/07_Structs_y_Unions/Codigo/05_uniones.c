#include <stdio.h>

union Datos {
    int i;
    float f;
    char str[20];
};

typedef struct {
    int tipo_dato; // 1: int, 2: float, 3: string
    union {
        int i;
        float f;
        char str[20];
    } contenido; 
} VariableMagica;

int main(void){
    printf("\n=== 6. Uniones: Compartiendo la Memoria ===\n");
    union Datos mis_datos;
    mis_datos.i = 42;
    printf("Union -> Escribimos int: %d\n", mis_datos.i);
    
    mis_datos.f = 3.14; // Al escribir esto, el 42 muere para siempre
    printf("Union -> Escribimos float: %.2f\n", mis_datos.f);
    printf("Union -> Intentar leer el int ahora da basura de memoria: %d\n", mis_datos.i);
    
    // Uso del Tagged Union
    VariableMagica var1;
    var1.tipo_dato = 2; // Avisamos que guardaremos un float
    var1.contenido.f = 9.99;
    printf("Tagged Union -> Dato tipo %d, valor: %.2f\n", var1.tipo_dato, var1.contenido.f);

    return 0;
}
