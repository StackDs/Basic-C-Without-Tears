/**
   ######################################################
   ##                                                  ##
   ##           Manejo de Errores en C                 ## 
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

// Definir NDEBUG antes de incluir assert.h desactiva los assert (para producción).
// #define NDEBUG 
#include <assert.h>

// ==========================================
// Funciones que demuestran Patrones de Retorno
// ==========================================

/* 
 * Paso por referencia y retorno entero:
 * Devuelve 0 en caso de éxito, -1 en caso de fallo.
 * El resultado útil se asigna al puntero proporcionado.
 */
int dividir_enteros(int a, int b, int *resultado) {
    if (b == 0) {
        return -1; // Fallo lógico
    }
    *resultado = a / b;
    return 0; // Éxito
}

/*
 * Retorno de Punteros:
 * Devuelve un puntero válido en caso de éxito, NULL en caso de fallo.
 */
int* crear_arreglo(int tamano) {
    if (tamano <= 0) {
        return NULL; // Fallo de lógica, el tamaño no tiene sentido
    }
    // Intentamos asignar memoria (malloc en sí mismo devuelve NULL si falla)
    int *ptr = (int*)malloc(tamano * sizeof(int));
    return ptr; 
}

/*
 * Función para probar la herramienta de desarrollo assert.
 */
void procesar_dato_positivo(int dato) {
    // Si dato es negativo, el programa morirá aquí mismo mostrando la línea de error.
    assert(dato >= 0);
    printf("El dato %d es válido y fue procesado.\n", dato);
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

    printf("\n=== 2. Comprobación de Punteros (NULL) ===\n");
    
    int *mi_arreglo = crear_arreglo(-5);
    if (mi_arreglo == NULL) {
        fprintf(stderr, "[Error] No se pudo crear el arreglo. Tamaño inválido o falta memoria.\n");
    }

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

    printf("\n=== 4. Aserciones y Contratos (assert) ===\n");
    
    printf("Probando assert con un valor positivo (Debería pasar sin problema):\n");
    procesar_dato_positivo(15);
    
    printf("Si descomentas la siguiente línea en el código fuente, el programa abortará.\n");
    // procesar_dato_positivo(-5);

    printf("\n=== 5. Terminación Controlada (exit) ===\n");
    
    printf("El programa ha llegado a su fin.\n");
    printf("En una aplicación real, si el error anterior fuera fatal, usaríamos exit(EXIT_FAILURE).\n");
    printf("Como todo ha sido una simulación controlada, el main devolverá EXIT_SUCCESS.\n");

    return EXIT_SUCCESS;
}
