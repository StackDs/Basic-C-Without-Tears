/**
   ######################################################
   ##                                                  ##
   ##             Arreglos y Matrices en C             ## 
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>

/**
 * PROTOTIPOS (Firmas de las funciones)
 **/
void imprimir_arreglo_1d(int arr[], int size);
void modificar_arreglo(int arr[], int size);
void imprimir_matriz(int matriz[][4], int filas);

int main(void){
    
    printf("\n=== 1. Arreglos 1D (Declaracion e Inicializacion) ===\n");
    // Declaracion sin inicializar (basura de memoria)
    int basura[3]; 
    printf("Basura en el arreglo sin inicializar: %d, %d, %d\n", basura[0], basura[1], basura[2]);

    // Inicializacion completa
    int edades[5] = {18, 22, 35, 40, 19};
    
    // Inicializacion parcial (el resto se vuelve 0 automaticamente)
    int contadores[5] = {1, 2}; 
    printf("Inicializacion parcial: %d, %d, %d, %d, %d\n", 
            contadores[0], contadores[1], contadores[2], contadores[3], contadores[4]);
            
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

    printf("\n=== 4. La Trampa de los Limites (Comentada para sobrevivir) ===\n");
    // Si descomentas esto, podrias causar un Segmentation Fault
    // edades[10] = 666; 
    // printf("Peligro inminente: %d\n", edades[10]);
    printf("C no te detendra si intentas acceder al indice 10 de un arreglo de 5. No lo hagas.\n");

    printf("\n=== 5. Arreglos Multidimensionales (Matrices) ===\n");
    // Matriz de 3 filas y 4 columnas
    int matriz[3][4] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };
    
    // Recorrido Row-major order (Bucle mas profundo itera en la ultima dimension)
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            printf("%2d ", matriz[i][j]); // %2d para alinear los numeros de un solo digito
        }
        printf("\n");
    }

    printf("\n=== 6. Paso de Arreglos a Funciones ===\n");
    int numeros_magicos[] = {10, 20, 30};
    int size_magicos = sizeof(numeros_magicos) / sizeof(numeros_magicos[0]);
    
    printf("Antes de la funcion: ");
    imprimir_arreglo_1d(numeros_magicos, size_magicos);
    
    // Modificamos el arreglo. Recordar: C envia un puntero, por lo que mutara el original.
    modificar_arreglo(numeros_magicos, size_magicos);
    
    printf("Despues de la funcion (mutacion!): ");
    imprimir_arreglo_1d(numeros_magicos, size_magicos);
    
    printf("\nImprimiendo matriz desde una funcion:\n");
    // Enviamos la matriz y sus filas (las columnas ya las sabe la funcion)
    imprimir_matriz(matriz, 3); 

    printf("\n=== 7. Arreglos de Longitud Variable (VLAs) ===\n");
    // Simulamos un valor en tiempo de ejecucion sin bloquear la consola con scanf
    int n = 4;
    printf("Creando un VLA de tamano 'n = %d' en tiempo de ejecucion...\n", n);
    
    // Esto es un VLA. En C99 puedes usar variables para dar tamaño (pero cuidado con el Stack)
    int vla[n]; 
    
    for(int i = 0; i < n; i++){
        vla[i] = (i + 1) * 10;
        printf("vla[%d] = %d\n", i, vla[i]);
    }

    return 0;
}


/**
   ######################################################
   ##                                                  ##
   ##             2. IMPLEMENTACIONES                  ## 
   ##                                                  ##
   ######################################################
**/

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
