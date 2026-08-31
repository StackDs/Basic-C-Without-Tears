#include <stdio.h>

void hackear_cuenta_valor(int dinero);
void hackear_cuenta_referencia(int *dinero);

int main(void){
    printf("\n=== 4. Paso de Parametros (Copia vs Referencia) ===\n");
    int mi_cuenta = 10;
    
    // Paso por valor (Copia)
    printf("Saldo inicial: %d\n", mi_cuenta);
    hackear_cuenta_valor(mi_cuenta);
    printf("Saldo tras intentar hackear (Copia): %d (El clon murio, el original vive)\n", mi_cuenta);
    
    // Paso por referencia (Punteros)
    hackear_cuenta_referencia(&mi_cuenta); // Mandamos la direccion de memoria con '&'
    printf("Saldo tras hackear de verdad (Referencia): %d (Felicidades, eres rico)\n", mi_cuenta);

    return 0;
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
