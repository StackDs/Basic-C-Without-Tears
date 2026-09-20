/**
   ######################################################
   ##                                                  ##
   ##        Módulo 16 - Submódulo 3: Input            ##
   ##       (Header: Eventos, Teclado y Movimiento)    ##
   ##                                                  ##
   ######################################################
**/

#ifndef INPUT_H
#define INPUT_H

#include <stdbool.h>
#include <SDL3/SDL.h>
#include "../01_Ventana_y_Ciclo/laberinto.h"

// Intenta desplazar al jugador una casilla en la direccion especificada
bool jugador_intentar_mover(Jugador *jugador, const Laberinto *laberinto, int dx, int dy);

// Procesa la cola de eventos de SDL3 capturando teclado y solicitudes de cierre
bool input_procesar_eventos(Jugador *jugador, const Laberinto *laberinto, bool *salida_alcanzada);

#endif
