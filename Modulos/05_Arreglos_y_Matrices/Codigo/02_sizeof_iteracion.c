#include <stdio.h>

int main(void){
    int edades[5] = {18, 22, 35, 40, 19};
            
    printf("\n=== 2. Calculando el tamano con sizeof ===\n");
    int longitud_edades = sizeof(edades) / sizeof(edades[0]);
    printf("El tamano total de 'edades' en bytes: %lu\n", (unsigned long)sizeof(edades));
    printf("El tamano de un elemento en bytes: %lu\n", (unsigned long)sizeof(edades[0]));
    printf("La longitud del arreglo es: %d\n", longitud_edades);

    printf("\n=== 3. Iteracion y Operaciones Basicas (1D) ===\n");
    int suma = 0;
    int mayor = edades[0];
    
    for (int i = 0; i < longitud_edades; i++){
        printf("Edad en indice %d: %d\n", i, edades[i]);
        suma += edades[i];
        
        if (edades[i] > mayor){
            mayor = edades[i];
        }
    }
    
    float promedio = (float)suma / longitud_edades;
    printf("Suma total: %d | Promedio: %.2f | Mayor edad: %d\n", suma, promedio, mayor);

    return 0;
}
