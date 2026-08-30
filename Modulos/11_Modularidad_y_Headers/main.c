/**
   ######################################################
   ##                                                  ##
   ##        Demostración Compilación Múltiple         ## 
   ##                                                  ##
   ######################################################
**/

// Este archivo demuestra la compilación de múltiples archivos.
// Incluye nuestro "sintaxis.h" para acceder a las funciones y variables
// del módulo, pero el código real de esas funciones vive en "sintaxis.c".
// 
// Compilación:
// gcc main.c sintaxis.c -o juego

#include <stdio.h>
#include "sintaxis.h" // Incluimos la interfaz pública de nuestro módulo

int main() {
    printf("\n=== DEMOSTRACIÓN DE COMPILACIÓN SEPARADA ===\n\n");
    
    // 1. Usando el struct y las funciones públicas del módulo
    Jugador player1;
    Arma espada_legendaria;
    
    espada_legendaria.dano = 50;
    espada_legendaria.municion = -1; // Arma cuerpo a cuerpo infinita
    
    inicializar_jugador(&player1, "Stack");
    player1.arma_equipada = &espada_legendaria; // Asignamos el puntero
    
    // 2. Jugando con la variable global (prometida con extern en el .h)
    puntuacion_global += 500;
    printf("Puntuación Global del Servidor: %d\n", puntuacion_global);
    
    imprimir_estado_jugador(&player1);
    
    // 3. Simulando el ciclo de combate
    recibir_dano(&player1, 60); // Mucho daño, pero sigue vivo
    recibir_dano(&player1, 20); // Aquí bajará de 30 y será envenenado
    
    imprimir_estado_jugador(&player1);
    
    curar_jugador(&player1, 40); // Nos curamos y quitamos el veneno
    
    imprimir_estado_jugador(&player1);
    
    recibir_dano(&player1, 100); // Muerte súbita
    recibir_dano(&player1, 10);  // Intento de golpear a un muerto
    
    imprimir_estado_jugador(&player1);

    return 0;
}
