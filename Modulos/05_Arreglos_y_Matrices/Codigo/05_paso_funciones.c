#include <stdio.h>

void imprimir_arreglo_1d(int arr[], int size);
void modificar_arreglo(int arr[], int size);
void imprimir_matriz(int matriz[][4], int filas);

int main(void){
    printf("\n=== 6. Paso de Arreglos a Funciones ===\n");
    int numeros_magicos[] = {10, 20, 30};
    int size_magicos = sizeof(numeros_magicos) / sizeof(numeros_magicos[0]);
    
    printf("Antes de la funcion: ");
    imprimir_arreglo_1d(numeros_magicos, size_magicos);
    
    // Modificamos el arreglo. Recordar: C envia un puntero, por lo que mutara el original.
    modificar_arreglo(numeros_magicos, size_magicos);
    
    printf("Despues de la funcion (mutacion!): ");
    imprimir_arreglo_1d(numeros_magicos, size_magicos);
    
    int matriz[3][4] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };

    printf("\nImprimiendo matriz desde una funcion:\n");
    // Enviamos la matriz y sus filas (las columnas ya las sabe la funcion)
    imprimir_matriz(matriz, 3); 

    return 0;
}

void imprimir_arreglo_1d(int arr[], int size){
    // Es OBLIGATORIO recibir el 'size'. Si hacemos sizeof(arr) aqui, 
    // nos devolvera el tamano del puntero (4 u 8 bytes), no la longitud del arreglo.
    printf("[");
    for (int i = 0; i < size; i++){
        printf("%d", arr[i]);
        if(i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void modificar_arreglo(int arr[], int size){
    for (int i = 0; i < size; i++){
        arr[i] = arr[i] * 2; // Multiplicamos todos los elementos por 2
    }
}

void imprimir_matriz(int matriz[][4], int filas){
    // Para multidimensionales, las columnas (4) ya deben estar establecidas en la firma.
    for (int i = 0; i < filas; i++){
        printf("Fila %d: ", i);
        for (int j = 0; j < 4; j++){
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
}
