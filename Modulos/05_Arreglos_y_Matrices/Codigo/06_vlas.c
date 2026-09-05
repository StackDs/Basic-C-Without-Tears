/**
   ######################################################
   ##                                                  ##
   ##       Arreglos de Longitud Variable (VLAs)       ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>

int main(void){
    printf("\n=== 7. Arreglos de Longitud Variable (VLAs) ===\n");
    // Simulamos un valor en tiempo de ejecucion sin bloquear la consola con scanf
    int n = 4;
    printf("Creando un VLA de tamano 'n = %d' en tiempo de ejecucion...\n", n);
    
    // Esto es un VLA. En C99 puedes usar variables para dar tamaño (pero cuidado con el Stack)
    int vla[n]; 
    
    for(int i = 0; i < n; i++){
        vla[i] = (i + 1) * 10;
        printf("vla[%d] = %d\n", i, vla[i]);
    }

    return 0;
}
