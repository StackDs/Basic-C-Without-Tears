/**
   ######################################################
   ##                                                  ##
   ##        Módulo 16 - Submódulo 1: Ventana          ##
   ##         (Header: Inicialización y Ciclo)         ##
   ##                                                  ##
   ######################################################
**/

#ifndef VENTANA_H
#define VENTANA_H

#include <SDL3/SDL.h>
#include <stdbool.h>

/**
 * Inicializa el subsistema de video de SDL3 y crea la ventana del SO
 * junto con su contexto de renderizado acelerado por GPU (renderer).
 *
 * Retorna true si ambos recursos fueron creados correctamente, o false ante
 * error.
 */
bool ventana_inicializar(SDL_Window **ventana, SDL_Renderer **renderer,
                         const char *titulo, int ancho, int alto);

/**
 * Ejecuta el bucle de eventos base (Game Loop preliminar):
 * limpia la pantalla en color negro a 60 FPS y escucha las señales de cierre
 * (click en la 'X' de la ventana o pulsar la tecla Escape) para salir.
 */
void ventana_ejecutar_ciclo_base(SDL_Renderer *renderer);

/**
 * Destruye el renderer, la ventana y apaga el subsistema de SDL3
 * liberando toda la memoria asociada en la GPU y el Sistema Operativo.
 */
void ventana_destruir(SDL_Window *ventana, SDL_Renderer *renderer);

#endif
