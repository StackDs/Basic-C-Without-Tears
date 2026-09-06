/**
 * Ejercicio: Limpieza de Cadenas (In-Place)
 * 
 * Descripcion:
 * Elimina todos los caracteres no alfanumericos de una cadena y convierte
 * las letras restantes a minusculas modificando la memoria original (in-place).
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Modifica la cadena original conservando solo alfanumericos en minusculas
void limpiar_cadena(char *str) {
    if (str == NULL) {
        return;
    }
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        // Si el caracter actual es alfanumerico (letra o digito)
        if (isalnum((unsigned char)str[i])) {
            str[j] = (char)tolower((unsigned char)str[i]);
            j++;
        }
    }
    // Colocar el caracter nulo de fin de cadena en la nueva posicion
    str[j] = '\0';
}

int main(void) {
    char texto[1024];

    // Leer la linea de texto completa
    if (fgets(texto, sizeof(texto), stdin) != NULL) {
        // Remover el salto de linea al final si existe
        size_t len = strlen(texto);
        if (len > 0 && texto[len - 1] == '\n') {
            texto[len - 1] = '\0';
        }

        // Limpiar la cadena directamente sobre el arreglo original
        limpiar_cadena(texto);
        printf("%s\n", texto);
    }

    return 0;
}
