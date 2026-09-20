/**
   ######################################################
   ##                                                  ##
   ##        Módulo 16 - Submódulo 3: Input            ##
   ##      (Implementación: Eventos y Movimiento)      ##
   ##                                                  ##
   ######################################################
**/

#include "input.h"
#include <stdio.h>

bool jugador_intentar_mover(Jugador *jugador, const Laberinto *laberinto, int dx, int dy) {
    if (jugador == NULL || laberinto == NULL) {
        return false;
    }

    // Calcular la coordenada destino tentativa
    int nuevo_x = jugador->x + dx;
    int nuevo_y = jugador->y + dy;

    // Verificar si la casilla destino es un muro solido
    if (laberinto_es_pared(laberinto, nuevo_x, nuevo_y)) {
        return false;
    }

    // Aplicar el desplazamiento a las coordenadas logicas
    jugador->x = nuevo_x;
    jugador->y = nuevo_y;

    printf("-> Posicion del jugador: (%d, %d)\n", jugador->x, jugador->y);

    // Notificar si se alcanzo la casilla de meta
    if (laberinto_es_salida(laberinto, nuevo_x, nuevo_y)) {
        printf("-> [META] El jugador alcanzo la salida en (%d, %d)\n", nuevo_x, nuevo_y);
    }

    return true;
}

bool input_procesar_eventos(Jugador *jugador, const Laberinto *laberinto, bool *salida_alcanzada) {
    if (jugador == NULL || laberinto == NULL) {
        return false;
    }

    SDL_Event evento;

    // Vaciar la cola de eventos acumulados por el sistema operativo
    while (SDL_PollEvent(&evento)) {
        // Solicitud de cierre mediante la X de la ventana
        if (evento.type == SDL_EVENT_QUIT) {
            return false;
        }

        // Deteccion de pulsacion de teclas
        if (evento.type == SDL_EVENT_KEY_DOWN) {
            switch (evento.key.key) {
                case SDLK_ESCAPE:
                    return false;

                // Desplazamiento hacia arriba
                case SDLK_UP:
                case SDLK_W:
                    jugador_intentar_mover(jugador, laberinto, 0, -1);
                    break;

                // Desplazamiento hacia abajo
                case SDLK_DOWN:
                case SDLK_S:
                    jugador_intentar_mover(jugador, laberinto, 0, 1);
                    break;

                // Desplazamiento hacia la izquierda
                case SDLK_LEFT:
                case SDLK_A:
                    jugador_intentar_mover(jugador, laberinto, -1, 0);
                    break;

                // Desplazamiento hacia la derecha
                case SDLK_RIGHT:
                case SDLK_D:
                    jugador_intentar_mover(jugador, laberinto, 1, 0);
                    break;

                default:
                    break;
            }

            // Actualizar bandera de victoria si se piso la meta
            if (salida_alcanzada != NULL && laberinto_es_salida(laberinto, jugador->x, jugador->y)) {
                *salida_alcanzada = true;
            }
        }
    }

    return true;
}
