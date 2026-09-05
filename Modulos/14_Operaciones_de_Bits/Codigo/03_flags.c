/**
   ######################################################
   ##                                                  ##
   ##           Banderas y Mascaras (Flags)            ##
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
    printf("\n=== 3. Aplicaciones Prácticas: Banderas (Flags) ===\n");
    // Guardamos múltiples estados en un solo byte (uint8_t) en lugar de usar varios int.
    uint8_t mis_banderas = 0; 
    
    // Podemos activar múltiples banderas simultáneamente usando OR entre ellas:
    mis_banderas |= (BIT_LED_ROJO | BIT_LED_AZUL);
    
    printf("Banderas empaquetadas: "); imprimir_binario_8(mis_banderas);

    return 0;
}
