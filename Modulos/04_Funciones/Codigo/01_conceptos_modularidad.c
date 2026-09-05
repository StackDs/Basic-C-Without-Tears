/**
   ######################################################
   ##                                                  ##
   ##         Conceptos Basicos y Modularidad          ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>

/**
 * 1. PROTOTIPOS (Firmas de las funciones)
 * Le decimos al compilador: "Ey, confía en mí, estas funciones existen
 * y las voy a definir más abajo. Solo te aviso para que no llores."
 **/
int sumar(int a, int b);
void insultar_usuario(void);

int main(void){
    printf("\n=== 1. Conceptos Basicos y Modularidad ===\n");
    // Llamamos a una funcion que retorna un valor y lo atrapamos
    int resultado_suma = sumar(5, 7);
    printf("El resultado de sumar 5 y 7 es: %d\n", resultado_suma);
    
    // Llamamos a una funcion void (no devuelve nada)
    insultar_usuario();
    return 0;
}

// Aqui es donde la magia ocurre de verdad.
int sumar(int a, int b){
    // Retorna la suma y asesina la ejecucion de la funcion
    return a + b;
}

void insultar_usuario(void){
    printf("Has invocado a la funcion void. No retorno nada, inutil.\n");
    return; // Opcional en funciones void, pero te saca de aqui inmediatamente
}
