/**
   ######################################################
   ##                                                  ##
   ##              Iterativo vs Recursivo              ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>

int factorial_iterativo(int n);
int factorial_recursivo(int n);

int main(void){
    printf("\n=== 6. Iterativo vs Recursivo ===\n");
    int num_factorial = 5;
    printf("Factorial de %d (Iterativo): %d\n", num_factorial, factorial_iterativo(num_factorial));
    printf("Factorial de %d (Recursivo): %d\n", num_factorial, factorial_recursivo(num_factorial));

    return 0;
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
