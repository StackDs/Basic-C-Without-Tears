/**
   ######################################################
   ##                                                  ##
   ##         Padding y Alineacion de Memoria          ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>

struct PaddingEjemplo {
    char letra;  // 1 byte
    int numero;  // 4 bytes
};

int main(void){
    printf("\n=== 7. Padding y Alineacion de Memoria (sizeof) ===\n");
    struct PaddingEjemplo pad_ejemplo;
    
    // Hacemos el barrido interno de los campos
    unsigned long size_letra = sizeof(pad_ejemplo.letra);
    unsigned long size_numero = sizeof(pad_ejemplo.numero);
    unsigned long size_total_logico = size_letra + size_numero;
    
    // Medimos el molde completo
    unsigned long size_real = sizeof(struct PaddingEjemplo);
    
    printf("Barrido de los campos internos:\n");
    printf(" - Tamano logico de 'char letra': %lu byte(s)\n", size_letra);
    printf(" - Tamano logico de 'int numero': %lu byte(s)\n", size_numero);
    printf("------------------------------------------\n");
    printf("Tamano total logico (suma): %lu bytes\n", size_total_logico);
    printf("Tamano REAL devuelto por el procesador: %lu bytes\n", size_real);
    
    if (size_real > size_total_logico){
        printf("-> Diferencia por Padding: %lu bytes ocultos (basura insertada para alinear a 4/8 bytes)\n", 
                size_real - size_total_logico);
    } else {
        printf("-> No hubo padding (el tamano es exacto).\n");
    }

    return 0;
}
