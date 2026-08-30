/**
   ######################################################
   ##                                                  ##
   ##             Strings y Cadenas en C               ## 
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void imprimir_con_longitud(char cadena[]);

int main(void){
    
    printf("\n=== 1. Declaracion e Inicializacion ===\n");
    // Asignacion literal (el compilador calcula el espacio y el '\0' automaticamente)
    char saludo1[] = "Hola";
    
    // Asignacion caracter por caracter (tu responsabilidad agregar el '\0')
    char saludo2[5] = {'H', 'o', 'l', 'a', '\0'};
    
    printf("Asignacion literal: %s\n", saludo1);
    printf("Asignacion manual:  %s\n", saludo2);
    
    printf("\n=== 2. La Trampa del Desbordamiento ===\n");
    // char trampa[4] = "Juan"; // PELIGRO: No hay espacio para '\0'
    printf("Recuerda: 'Juan' necesita 5 espacios (4 letras + 1 nulo). \n");
    printf("Si reservas 4, imprimira basura de la RAM hasta toparse con un '\\0' accidental.\n");
    
    printf("\n=== 3. Manipulacion de Bloques: <string.h> ===\n");
    char origen[] = "Secreto super clasificado";
    char destino[20];
    
    printf("-- Copiar (strcpy vs strncpy) --\n");
    // strcpy(destino, origen); // ERROR: Destino (20) es menor que origen (26)
    strncpy(destino, origen, 19);
    destino[19] = '\0'; // strncpy no garantiza el '\0' si corta el texto al limite
    printf("Copia segura (max 19 chars): %s\n", destino);
    
    printf("\n-- Medir (strlen) --\n");
    printf("Longitud real de '%s': %lu caracteres (sin contar el nulo)\n", destino, (unsigned long)strlen(destino));
    printf("Tamano de memoria reservado: %lu bytes\n", (unsigned long)sizeof(destino));

    printf("\n-- Comparar (strcmp vs strncmp) --\n");
    if (strcmp("Apple", "Apple") == 0){
        printf("'Apple' y 'Apple' son exactamente iguales.\n");
    }
    
    // Comparamos solo las primeras 4 letras para buscar el prefijo
    if (strncmp("Automovil", "Autobus", 4) == 0){
        printf("'Automovil' y 'Autobus' tienen los mismos primeros 4 caracteres ('Auto').\n");
    }
    
    printf("\n-- Concatenar (strcat vs strncat) --\n");
    char saludo_completo[30] = "Hola, ";
    char nombre_concatenar[] = "Mundo cruel";
    
    // Concatenamos solo "Mundo" para evitar textos demasiado largos
    strncat(saludo_completo, nombre_concatenar, 5); 
    printf("Concatenacion parcial (max 5 letras): %s\n", saludo_completo);
    
    printf("\n-- Buscar (strchr y strcspn) --\n");
    char correo[] = "tudireccion@gmail.com";
    char *arroba = strchr(correo, '@');
    if (arroba != NULL){
        printf("Arroba encontrada en el correo: %s\n", correo);
        printf("Texto a partir del arroba: %s\n", arroba);
    }
    
    // Simulacion de la limpieza del salto de linea de fgets
    char input_usuario[] = "Texto con enter\n";
    printf("Texto original tiene '\\n' en el indice: %lu\n", (unsigned long)strcspn(input_usuario, "\n"));
    
    // Reemplazamos el salto de linea con el caracter nulo
    input_usuario[strcspn(input_usuario, "\n")] = '\0';
    printf("Despues de limpiar con strcspn, nueva longitud es: %lu\n", (unsigned long)strlen(input_usuario));

    printf("\n=== 4. Modificacion Caracter a Caracter: <ctype.h> ===\n");
    char pass[] = "Pa55word!";
    int digitos = 0;
    
    printf("Analizando el string '%s':\n", pass);
    for (int i = 0; pass[i] != '\0'; i++){
        if (isdigit(pass[i])){
            digitos++;
        }
        // Convertimos todo a mayuscula sobre la marcha
        pass[i] = toupper(pass[i]);
    }
    printf("Contiene %d digitos.\n", digitos);
    printf("Version en mayusculas pura: %s\n", pass);
    
    printf("\n=== 5. Conversion Texto a Numero: <stdlib.h> ===\n");
    char str_entero[] = "42";
    char str_decimal[] = "3.14159";
    char str_basura[] = "100pts";
    
    // Funciones rapidas pero inseguras
    int numero_entero = atoi(str_entero);
    double numero_decimal = atof(str_decimal);
    
    printf("atoi(\"42\") -> %d\n", numero_entero);
    printf("atof(\"3.14159\") -> %f\n", numero_decimal);
    
    // Funcion robusta (strtol) que permite detectar basura
    char *resto;
    long numero_seguro = strtol(str_basura, &resto, 10);
    printf("strtol(\"100pts\") -> Numero real: %ld | Basura ignorada: '%s'\n", numero_seguro, resto);

    printf("\n=== 6. Paso de Strings a Funciones ===\n");
    imprimir_con_longitud(pass);

    return 0;
}

void imprimir_con_longitud(char cadena[]){
    // A diferencia de los arreglos normales de enteros, aqui NO hace falta 
    // recibir el 'size' como parametro extra. Gracias al caracter nulo ('\0'), 
    // strlen() puede calcular la longitud dinamicamente.
    printf("-> La funcion recibio '%s', que tiene %lu caracteres reales.\n", cadena, (unsigned long)strlen(cadena));
}
