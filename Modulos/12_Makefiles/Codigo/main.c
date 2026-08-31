#include <stdio.h>
#include "sintaxis.h"

int main(void){
    printf("Iniciando programa principal (main.c)...\n");
    
    // Llamando a la función del otro módulo
    saludar_desde_modulo();
    
    return 0;
}
