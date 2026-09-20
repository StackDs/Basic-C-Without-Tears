/**
   ######################################################
   ##                                                  ##
   ##        Módulo 16 - Submódulo 2: Render           ##
   ##         (Header: Texturas y Dibujado)            ##
   ##                                                  ##
   ######################################################
**/

#ifndef RENDER_H
#define RENDER_H

#include <stdbool.h>
#include <SDL3/SDL.h>
#include "../01_Ventana_y_Ciclo/laberinto.h"

// Estructura contenedora de texturas cargadas en la VRAM de la GPU
typedef struct {
    SDL_Texture *pared;
    SDL_Texture *camino;
    SDL_Texture *salida;
    SDL_Texture *jugador;
} Texturas;

// Carga las imagenes desde la carpeta de assets y crea las texturas en la GPU
bool render_cargar_texturas(SDL_Renderer *renderer, Texturas *texturas);

// Dibuja la cuadricula completa del laberinto celda por celda
void render_dibujar_laberinto(SDL_Renderer *renderer, const Laberinto *laberinto, const Texturas *texturas);

// Dibuja al jugador en su coordenada logica actual (sin rotacion)
void render_dibujar_jugador(SDL_Renderer *renderer, const Jugador *jugador, const Texturas *texturas);

// Dibuja al jugador en su coordenada logica con un angulo de rotacion en grados
void render_dibujar_jugador_rotado(SDL_Renderer *renderer, const Jugador *jugador, const Texturas *texturas, double angulo);

// Libera las texturas de la VRAM de la GPU
void render_destruir_texturas(Texturas *texturas);

#endif
