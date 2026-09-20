/**
   ######################################################
   ##                                                  ##
   ##        Módulo 16 - Submódulo 5: Estados          ##
   ##         (Header: FSM, Botones y Menús)           ##
   ##                                                  ##
   ######################################################
**/

#ifndef ESTADOS_H
#define ESTADOS_H

#include <stdbool.h>
#include <SDL3/SDL.h>

// Estados de la maquina de estados finita del juego
typedef enum {
    ESTADO_MENU,
    ESTADO_JUGANDO,
    ESTADO_VICTORIA
} EstadoJuego;

// Estructura para representar botones interactivos en pantalla
typedef struct {
    SDL_FRect rect;
    const char *texto;
    bool hover;
} Boton;

// Inicializa una estructura de boton interactivo
Boton boton_crear(float x, float y, float ancho, float alto, const char *texto);

// Comprueba si un punto (coordenadas del raton) colisiona con el area del boton
bool boton_contiene_punto(const Boton *boton, float px, float py);

// Actualiza el estado visual de hover segun la posicion del cursor
void boton_actualizar_hover(Boton *boton, float px, float py);

// Dibuja el boton en pantalla con estilos normales o resaltados
void boton_dibujar(SDL_Renderer *renderer, const Boton *boton);

// Dibuja la pantalla completa del menu principal de bienvenida
void estados_dibujar_menu(SDL_Renderer *renderer, const Boton *boton_jugar, int ancho_ventana, int alto_ventana);

// Dibuja la pantalla de victoria final con el tiempo record obtenido
void estados_dibujar_victoria(SDL_Renderer *renderer, Uint64 tiempo_record_ms, const Boton *boton_reiniciar, int ancho_ventana, int alto_ventana);

#endif
