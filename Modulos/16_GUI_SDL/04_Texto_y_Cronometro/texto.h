/**
   ######################################################
   ##                                                  ##
   ##        Módulo 16 - Submódulo 4: Texto            ##
   ##          (Header: Tipografía y HUD)              ##
   ##                                                  ##
   ######################################################
**/

#ifndef TEXTO_H
#define TEXTO_H

#include <SDL3/SDL.h>
#include <stddef.h>

// Renderiza una cadena de texto en pantalla con escala y color determinados
void texto_renderizar(SDL_Renderer *renderer, float x, float y, const char *texto, float escala, SDL_Color color);

// Formatea un intervalo de milisegundos en formato legible MM:SS.CC
void hud_formatear_tiempo(Uint64 milisegundos, char *buffer, size_t tam_buffer);

// Dibuja el panel superior HUD con titulo y cronometro en tiempo real
void hud_renderizar(SDL_Renderer *renderer, Uint64 tiempo_transcurrido_ms, int ancho_ventana);

#endif
