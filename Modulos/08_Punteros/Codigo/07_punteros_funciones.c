/**
   ######################################################
   ##                                                  ##
   ##         Punteros a Funciones (Callbacks)         ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>

void saludar(void){
    printf("Hola desde un Callback!\n");
}

void despedir(void){
    printf("Adios desde un Callback!\n");
}

// Esta función recibe un puntero a una función que no toma argumentos y retorna void
void ejecutar_callback(void (*func)(void)){
    printf("Ejecutando funcion inyectada...\n");
    func();
}

int main(void){
    printf("\n=== 7. Punteros a Funciones (Callbacks) ===\n");
    // Pasamos el nombre de la función, que decae en un puntero a sus instrucciones
    ejecutar_callback(saludar);
    ejecutar_callback(despedir);

    return 0;
}
