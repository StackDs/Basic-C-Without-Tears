#include <stdio.h>
#include <stdint.h>

struct PermisosArchivo {
    uint8_t lectura   : 1; // Solo 1 bit (0 o 1)
    uint8_t escritura : 1; // Solo 1 bit
    uint8_t ejecucion : 1; // Solo 1 bit
    uint8_t nivel_adm : 3; // Usa 3 bits (Valores permitidos de 0 a 7)
    uint8_t reservado : 2; // Bits de relleno para completar los 8 bits (1 byte)
};

int main(void) {
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
