/**
 * Ejercicio: Registro de Pares e Impares (Bit a Bit)
 * 
 * Descripcion:
 * Determina la paridad de numeros usando operaciones a nivel de bits (& 1)
 * y almacena un registro continuo en el archivo 'historial.txt' en modo append.
 */

#include <stdio.h>

// Determina paridad con bit a bit y guarda el resultado en consola y en archivo
void guardar_en_historial(int num) {
    // Abrir el archivo en modo "a" (append) para no sobreescribir registros previos
    FILE *archivo = fopen("historial.txt", "a");

    if (archivo == NULL) {
        printf("Error al abrir el archivo historial.txt\n");
        return;
    }

    // Operacion bit a bit: el bit menos significativo de un numero impar es 1.
    // Al aplicar AND (&) con 1, aislamos dicho bit.
    if ((num & 1) == 0) {
        fprintf(archivo, "El numero %d es PAR.\n", num);
        printf("El numero %d es PAR.\n", num);
    } else {
        fprintf(archivo, "El numero %d es IMPAR.\n", num);
        printf("El numero %d es IMPAR.\n", num);
    }

    // Cerrar el flujo del archivo
    fclose(archivo);
}

int main(void) {
    int numero;

    // Procesar numeros hasta recibir un 0 (condicion de terminacion)
    while (scanf("%d", &numero) == 1 && numero != 0) {
        guardar_en_historial(numero);
    }

    return 0;
}
