/**
   ######################################################
   ##                                                  ##
   ##             Makefiles: Modulo Saludo             ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include "02_saludo.h"

void saludar_desde_modulo(void){
    printf("¡Hola desde el archivo 02_saludo.c!\n");
    printf("Si ves este mensaje, significa que el Makefile hizo su trabajo y enlazó los archivos correctamente.\n");
}
