/**
   ######################################################
   ##                                                  ##
   ##        CRUD de Bits (Operaciones Basicas)        ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <stdint.h>

#define BIT_LED_ROJO    (1 << 0)
#define BIT_LED_AZUL    (1 << 1)
#define BIT_LED_VERDE   (1 << 2)

void imprimir_binario_8(uint8_t num) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i == 4) printf(" "); 
    }
    printf("\n");
}

int main(void) {
    printf("\n=== 2. Las 4 Operaciones Clásicas (CRUD de Bits) ===\n");
    uint8_t estado = 0x00; // Estado inicial: Todo apagado (0000 0000)
    
    printf("Estado inicial:          "); imprimir_binario_8(estado);
    
    // SET (Encender): OR
    estado |= BIT_LED_ROJO; 
    printf("Tras encender el rojo:   "); imprimir_binario_8(estado);
    
    estado |= BIT_LED_VERDE;
    printf("Tras encender el verde:  "); imprimir_binario_8(estado);
    
    // CLEAR (Apagar): AND combinado con NOT
    estado &= ~BIT_LED_ROJO;
    printf("Tras apagar el rojo:     "); imprimir_binario_8(estado);
    
    // TOGGLE (Alternar): XOR
    estado ^= BIT_LED_AZUL;
    printf("Tras alternar el azul:   "); imprimir_binario_8(estado);
    
    // CHECK (Comprobar): AND
    if (estado & BIT_LED_VERDE) {
        printf(" -> [Check] ¡El LED verde está encendido!\n");
    }
    if (!(estado & BIT_LED_ROJO)) {
        printf(" -> [Check] ¡El LED rojo está apagado!\n");
    }

    return 0;
}
