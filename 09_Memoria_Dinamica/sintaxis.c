/**
   ######################################################
   ##                                                  ##
   ##           Memoria Dinamica en C                  ## 
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición para el ejemplo de struct dinámico
struct Alumno {
    int id;
    char *nombre; // Puntero interno que requerirá su propio malloc
};

int main(void) {
    printf("\n=== 1. malloc y free basicos ===\n");
    // Pedimos memoria cruda del tamaño de 1 entero
    int *ptr_entero = malloc(sizeof(int));
    
    // Regla de Oro 1: Validar siempre si el OS nos dio la memoria
    if (ptr_entero == NULL) {
        printf("Error fatal: No se pudo asignar memoria.\n");
        return 1;
    }
    
    *ptr_entero = 42;
    printf("Valor guardado en el Heap: %d\n", *ptr_entero);
    
    // Regla de Oro 2: Liberar la memoria
    free(ptr_entero);
    // Regla de Oro 3: Neutralizar el puntero para evitar Dangling Pointers
    ptr_entero = NULL;
    printf("Memoria liberada y puntero seteado a NULL.\n");

    printf("\n=== 2. Arreglos Dinamicos (1D) ===\n");
    int n = 5;
    //Pedimos el equivalente a 5 enteros en bytes
    int *arreglo = malloc(n * sizeof(int)); 
    if (arreglo == NULL) {
        return 1;
    }
    
    printf("Llenando el arreglo dinamico...\n");
    for (int i = 0; i < n; i++) {
        arreglo[i] = i * 10;
        printf("arreglo[%d] = %d\n", i, arreglo[i]);
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

    printf("\n=== 4. calloc vs malloc ===\n");
    // calloc inicializa todo en 0, malloc deja basura de la memoria reciclada
    int *basura = malloc(5 * sizeof(int));
    int *limpio = calloc(5, sizeof(int));
    
    printf("Valor en malloc (potencial basura): %d\n", basura[0]);
    printf("Valor en calloc (garantizado cero): %d\n", limpio[0]);
    
    free(basura);
    free(limpio);
    
    printf("\n=== 5. Matrices Dinamicas (Punteros Dobles) ===\n");
    int filas = 3;
    int columnas = 4;
    
    // Asignamos arreglo principal (las filas que guardan punteros int*)
    int **matriz = malloc(filas * sizeof(int *));
    
    // Asignamos columnas (arreglos 1D) a cada fila
    for (int i = 0; i < filas; i++) {
        matriz[i] = malloc(columnas * sizeof(int));
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = (i + 1) * (j + 1); // Rellenamos con matemática basica
        }
    }
    
    printf("Matriz dinamica 3x4:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    // Liberacion (Deep Free de la matriz, de adentro hacia afuera)
    for (int i = 0; i < filas; i++) {
        free(matriz[i]); // Liberamos las columnas individuales
    }
    free(matriz); // Liberamos el array de punteros principal
    matriz = NULL;
    printf("Matriz dinamica liberada correctamente (De adentro hacia afuera).\n");

    printf("\n=== 6. Structs Dinamicos y Deep Free ===\n");
    // Asignamos memoria para el struct en sí
    struct Alumno *estudiante = malloc(sizeof(struct Alumno));
    if (estudiante != NULL) {
        estudiante->id = 1234;
        
        // Asignamos memoria dinámica para un char* DENTRO del struct
        char *texto = "Linus Torvalds";
        estudiante->nombre = malloc((strlen(texto) + 1) * sizeof(char)); // +1 por el '\0'
        strcpy(estudiante->nombre, texto);
        
        printf("Alumno ID: %d, Nombre: %s\n", estudiante->id, estudiante->nombre);
        
        // DEEP FREE: El orden importa vitalmente
        free(estudiante->nombre); // 1. Liberamos el interior primero (cuerdas vocales)
        free(estudiante);         // 2. Liberamos el exterior despues (el cuerpo)
        estudiante = NULL;
        printf("Struct dinamico liberado completamente sin fugas.\n");
    }

    return 0;
}
