#include <stdio.h>

int main(void){
    printf("\n=== 2. La Trampa del Desbordamiento ===\n");
    // char trampa[4] = "Juan"; // PELIGRO: No hay espacio para '\0'
    printf("Recuerda: 'Juan' necesita 5 espacios (4 letras + 1 nulo). \n");
    printf("Si reservas 4, imprimira basura de la RAM hasta toparse con un '\\0' accidental.\n");
    
    return 0;
}
