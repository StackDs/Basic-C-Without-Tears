#include <stdio.h>
#include <stdint.h>

void imprimir_binario_8(uint8_t num) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i == 4) printf(" "); // Espacio visual para separar en nibbles (4 bits)
    }
    printf("\n");
}

int main(void) {
    printf("\n=== 1. Los 6 Operadores a Nivel de Bits ===\n");
    // Usamos el prefijo 0x para hexadecimal
    uint8_t a = 0x0C; // En binario: 0000 1100 (Decimal 12)
    uint8_t b = 0x0A; // En binario: 0000 1010 (Decimal 10)
    
    printf("a       = "); imprimir_binario_8(a);
    printf("b       = "); imprimir_binario_8(b);
    
    printf("a & b   = "); imprimir_binario_8(a & b);   // AND: Solo si ambos son 1
    printf("a | b   = "); imprimir_binario_8(a | b);   // OR:  Si al menos uno es 1
    printf("a ^ b   = "); imprimir_binario_8(a ^ b);   // XOR: Solo si son diferentes
    printf("~a      = "); imprimir_binario_8(~a);      // NOT: Invierte todos los bits
    printf("a << 1  = "); imprimir_binario_8(a << 1);  // L_SHIFT: Empuja izquierda (Multiplica x2)
    printf("a >> 1  = "); imprimir_binario_8(a >> 1);  // R_SHIFT: Empuja derecha (Divide /2)

    return 0;
}
