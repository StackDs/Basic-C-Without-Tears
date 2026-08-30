/**
   ######################################################
   ##                                                  ##
   ##      Operaciones a Nivel de Bits en C            ## 
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <stdint.h> // Vital para tener tipos sin signo de tamaño exacto

// ==================================================
// 1. Macros para Máscaras de Bits (Buenas prácticas)
// ==================================================
// Definimos constantes usando el operador de desplazamiento a la izquierda (<<)
#define BIT_LED_ROJO    (1 << 0) // 0000 0001 (Posición 0)
#define BIT_LED_AZUL    (1 << 1) // 0000 0010 (Posición 1)
#define BIT_LED_VERDE   (1 << 2) // 0000 0100 (Posición 2)

// ==================================================
// 2. Struct con Campos de Bits (Bit-fields)
// ==================================================
// Usamos tipos sin signo. Ocupa 1 byte completo en memoria, pero segmentado internamente.
struct PermisosArchivo {
    uint8_t lectura   : 1; // Solo 1 bit (0 o 1)
    uint8_t escritura : 1; // Solo 1 bit
    uint8_t ejecucion : 1; // Solo 1 bit
    uint8_t nivel_adm : 3; // Usa 3 bits (Valores permitidos de 0 a 7)
    uint8_t reservado : 2; // Bits de relleno para completar los 8 bits (1 byte)
};

// Función auxiliar para imprimir un número de 8 bits en formato binario visualmente
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

    printf("\n=== 3. Aplicaciones Prácticas: Banderas (Flags) ===\n");
    // Guardamos múltiples estados en un solo byte (uint8_t) en lugar de usar varios int.
    uint8_t mis_banderas = 0; 
    
    // Podemos activar múltiples banderas simultáneamente usando OR entre ellas:
    mis_banderas |= (BIT_LED_ROJO | BIT_LED_AZUL);
    
    printf("Banderas empaquetadas: "); imprimir_binario_8(mis_banderas);

    printf("\n=== 4. Campos de Bits en Structs ===\n");
    struct PermisosArchivo archivo = {0}; // Inicializamos todo en 0
    
    archivo.lectura = 1;
    archivo.escritura = 1;
    archivo.ejecucion = 0;
    archivo.nivel_adm = 5; // Usa 3 bits, así que soporta números del 0 al 7 (111 en binario)
    
    // Observa el tamaño: a pesar de tener 5 variables adentro, todo se comprime.
    printf("Tamaño del struct en memoria: %zu byte(s)\n", sizeof(archivo));
    printf("Permisos actuales:\n");
    printf("- Lectura:   %d\n", archivo.lectura);
    printf("- Escritura: %d\n", archivo.escritura);
    printf("- Ejecución: %d\n", archivo.ejecucion);
    printf("- Nivel Adm: %d\n", archivo.nivel_adm);
    
    // archivo.nivel_adm = 10; 
    // CUIDADO: El número 10 requiere 4 bits (1010). Si lo asignamos a un campo de 3 bits,
    // se desbordará y solo guardará los últimos 3 bits (010 = 2). Pruébalo descomentando la línea.

    // ILEGAL: No puedes sacar la dirección de memoria de un campo de bits.
    // uint8_t *ptr = &archivo.lectura; // ESTO DARÁ UN ERROR DE COMPILACIÓN (Prueba a descomentarlo)
    
    return 0;
}
