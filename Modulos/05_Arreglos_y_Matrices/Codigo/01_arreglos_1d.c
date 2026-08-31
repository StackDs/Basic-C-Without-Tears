#include <stdio.h>

int main(void){
    printf("\n=== 1. Arreglos 1D (Declaracion e Inicializacion) ===\n");
    // Declaracion sin inicializar (basura de memoria)
    int basura[3]; 
    printf("Basura en el arreglo sin inicializar: %d, %d, %d\n", basura[0], basura[1], basura[2]);

    // Inicializacion completa
    int edades[5] = {18, 22, 35, 40, 19};
    
    // Inicializacion parcial (el resto se vuelve 0 automaticamente)
    int contadores[5] = {1, 2}; 
    printf("Inicializacion parcial: %d, %d, %d, %d, %d\n", 
            contadores[0], contadores[1], contadores[2], contadores[3], contadores[4]);

    return 0;
}
