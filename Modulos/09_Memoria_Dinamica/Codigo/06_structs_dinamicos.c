#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición para el ejemplo de struct dinámico
struct Alumno {
    int id;
    char *nombre; // Puntero interno que requerirá su propio malloc
};

int main(void) {
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
