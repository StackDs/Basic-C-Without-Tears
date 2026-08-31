#include <stdio.h>

void contador_persistente(void);

// Variable global (Mala práctica en el 99% de los casos).
int whisky_sin_almorzar = 666;

int main(void){
    printf("\n=== 5. Ambito de las Variables (Scope) ===\n");
    printf("Valor de la global maligna: %d\n", whisky_sin_almorzar);
    
    // Llamamos a la funcion con variable estatica varias veces
    contador_persistente();
    contador_persistente();
    contador_persistente();
    
    return 0;
}

void contador_persistente(void){
    // Al tener 'static', esta variable no muere al terminar la funcion.
    // Solo se inicializa en 0 la primera vez que se llama.
    static int llamadas = 0;
    llamadas++;
    printf("Me has llamado %d veces y me acuerdo.\n", llamadas);
}
