/**
   ######################################################
   ##                                                  ##
   ##                  Funciones en C                  ## 
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
void hackear_cuenta_valor(int dinero);
void hackear_cuenta_referencia(int *dinero);
void contador_persistente(void);
int factorial_iterativo(int n);
int factorial_recursivo(int n);

// Variable global (Mala práctica en el 99% de los casos).
int whisky_sin_almorzar = 666;

/**
   ######################################################
   ##                                                  ##
   ##         Argumentos desde la Consola              ## 
   ##                                                  ##
   ######################################################
**/
// Observa la firma de main. Ya no es "int main(void)", ahora recibe argumentos.
// argc = cantidad de palabras (Argument Count).
// argv = arreglo con las palabras (Argument Vector).
int main(int argc, char *argv[]){
    
    printf("\n=== 1. Conceptos Basicos y Modularidad ===\n");
    // Llamamos a una funcion que retorna un valor y lo atrapamos
    int resultado_suma = sumar(5, 7);
    printf("El resultado de sumar 5 y 7 es: %d\n", resultado_suma);
    
    // Llamamos a una funcion void (no devuelve nada)
    insultar_usuario();

    printf("\n=== 4. Paso de Parametros (Copia vs Referencia) ===\n");
    int mi_cuenta = 10;
    
    // Paso por valor (Copia)
    printf("Saldo inicial: %d\n", mi_cuenta);
    hackear_cuenta_valor(mi_cuenta);
    printf("Saldo tras intentar hackear (Copia): %d (El clon murio, el original vive)\n", mi_cuenta);
    
    // Paso por referencia (Punteros)
    hackear_cuenta_referencia(&mi_cuenta); // Mandamos la direccion de memoria con '&'
    printf("Saldo tras hackear de verdad (Referencia): %d (Felicidades, eres rico)\n", mi_cuenta);

    printf("\n=== 5. Ambito de las Variables (Scope) ===\n");
    printf("Valor de la global maligna: %d\n", whisky_sin_almorzar);
    
    // Llamamos a la funcion con variable estatica varias veces
    contador_persistente();
    contador_persistente();
    contador_persistente();

    printf("\n=== 6. Iterativo vs Recursivo ===\n");
    int num_factorial = 5;
    printf("Factorial de %d (Iterativo): %d\n", num_factorial, factorial_iterativo(num_factorial));
    printf("Factorial de %d (Recursivo): %d\n", num_factorial, factorial_recursivo(num_factorial));

    printf("\n=== 7. Argumentos del Main (Consola) ===\n");
    printf("Has ejecutado este programa con %d argumentos en total.\n", argc);
    printf("El argumento 0 (el nombre del programa) es: %s\n", argv[0]);
    
    if (argc > 1){
        printf("Wow, le pasaste argumentos extra al programa. El argumento 1 es: %s\n", argv[1]);
    } else {
        printf("Prueba ejecutar este programa desde la terminal agregando palabras al final. (Ej: ./sintaxis pato)\n");
    }

    return 0;
}


/**
   ######################################################
   ##                                                  ##
   ## 2. IMPLEMENTACIONES (El trabajo sucio)           ## 
   ##                                                  ##
   ######################################################
**/
// Aqui es donde la magia ocurre de verdad.

int sumar(int a, int b){
    // Retorna la suma y asesina la ejecucion de la funcion
    return a + b;
}

void insultar_usuario(void){
    printf("Has invocado a la funcion void. No retorno nada, inutil.\n");
    return; // Opcional en funciones void, pero te saca de aqui inmediatamente
}

void hackear_cuenta_valor(int dinero){
    // Recibe un clon de "mi_cuenta"
    dinero = 999999; 
    // Al terminar, el clon se destruye y nadie le avisa al original
}

void hackear_cuenta_referencia(int *dinero){
    // Recibe la direccion. Con '*' accedemos a la casa original de la variable
    *dinero = 999999;
}

void contador_persistente(void){
    // Al tener 'static', esta variable no muere al terminar la funcion.
    // Solo se inicializa en 0 la primera vez que se llama.
    static int llamadas = 0;
    llamadas++;
    printf("Me has llamado %d veces y me acuerdo.\n", llamadas);
}

int factorial_iterativo(int n){
    int resultado = 1;
    // Un simple bucle. Aburrido pero solido como un tanque.
    for (int i = 1; i <= n; i++){
        resultado *= i;
    }
    return resultado;
}

int factorial_recursivo(int n){
    // EL CASO BASE (Obligatorio o el universo implosiona)
    if (n == 0 || n == 1){
        return 1;
    }
    // RECURSION: La funcion se llama a si misma
    return n * factorial_recursivo(n - 1);
}
