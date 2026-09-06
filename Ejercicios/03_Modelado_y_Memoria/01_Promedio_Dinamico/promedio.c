/**
 * Ejercicio: Calculadora de Promedios Dinamica
 * 
 * Descripcion:
 * Solicita memoria dinamica con malloc para almacenar N calificaciones flotantes,
 * calcula su promedio con precision de dos decimales y libera la memoria con free.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int cantidad;

    // Leer la cantidad de calificaciones
    if (scanf("%d", &cantidad) != 1) {
        return 0;
    }

    // Validar que la cantidad sea un entero positivo
    if (cantidad <= 0) {
        printf("La cantidad debe ser mayor a cero.\n");
        return 0;
    }

    // Asignar memoria exacta para 'cantidad' elementos de tipo float
    float *calificaciones = (float *)malloc((size_t)cantidad * sizeof(float));

    // Verificar si la asignacion de memoria fue exitosa
    if (calificaciones == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    float suma = 0.0f;
    for (int i = 0; i < cantidad; i++) {
        if (scanf("%f", &calificaciones[i]) != 1) {
            free(calificaciones);
            return 1;
        }
        suma += calificaciones[i];
    }

    // Imprimir el promedio formateado a dos decimales
    printf("%.2f\n", suma / (float)cantidad);

    // Liberar la memoria dinamica reservada
    free(calificaciones);

    return 0;
}
