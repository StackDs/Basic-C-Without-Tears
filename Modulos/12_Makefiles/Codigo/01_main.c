/**
   ######################################################
   ##                                                  ##
   ##          Makefiles: Programa Principal           ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include "02_saludo.h"

int main(void){
    printf("Iniciando programa principal (01_main.c)...\n");
    
    // Llamando a la función del otro módulo
    saludar_desde_modulo();
    
    return 0;
}
