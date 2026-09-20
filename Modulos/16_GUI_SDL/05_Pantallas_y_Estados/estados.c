/**
   ######################################################
   ##                                                  ##
   ##        Módulo 16 - Submódulo 5: Estados          ##
   ##      (Implementación: FSM, Botones y Menús)      ##
   ##                                                  ##
   ######################################################
**/

#include "estados.h"
#include "../04_Texto_y_Cronometro/texto.h"
#include <stdio.h>
#include <string.h>

Boton boton_crear(float x, float y, float ancho, float alto,
                  const char *texto) {
  Boton b;
  b.rect = (SDL_FRect){x, y, ancho, alto};
  b.texto = texto;
  b.hover = false;
  return b;
}

bool boton_contiene_punto(const Boton *boton, float px, float py) {
  if (boton == NULL) {
    return false;
  }

  return (px >= boton->rect.x && px <= boton->rect.x + boton->rect.w &&
          py >= boton->rect.y && py <= boton->rect.y + boton->rect.h);
}

void boton_actualizar_hover(Boton *boton, float px, float py) {
  if (boton != NULL) {
    boton->hover = boton_contiene_punto(boton, px, py);
  }
}

void boton_dibujar(SDL_Renderer *renderer, const Boton *boton) {
  if (renderer == NULL || boton == NULL) {
    return;
  }

  // Seleccionar colores segun el estado del puntero
  if (boton->hover) {
    // Fondo iluminado al posar el cursor
    SDL_SetRenderDrawColor(renderer, 42, 98, 195, 255);
    SDL_RenderFillRect(renderer, &boton->rect);

    // Borde brillante de seleccion
    SDL_SetRenderDrawColor(renderer, 130, 190, 255, 255);
    SDL_RenderRect(renderer, &boton->rect);
  } else {
    // Fondo normal en reposo
    SDL_SetRenderDrawColor(renderer, 28, 42, 65, 255);
    SDL_RenderFillRect(renderer, &boton->rect);

    // Borde sobrio de descanso
    SDL_SetRenderDrawColor(renderer, 60, 90, 135, 255);
    SDL_RenderRect(renderer, &boton->rect);
  }

  // Calcular dimensiones aproximadas del texto para centrarlo
  float escala = 2.4f;
  float ancho_char = 8.0f * escala;
  float alto_char = 8.0f * escala;
  float ancho_texto = (float)strlen(boton->texto) * ancho_char;

  float texto_x = boton->rect.x + ((boton->rect.w - ancho_texto) / 2.0f);
  float texto_y = boton->rect.y + ((boton->rect.h - alto_char) / 2.0f);

  SDL_Color color_texto = boton->hover ? (SDL_Color){255, 255, 255, 255}
                                       : (SDL_Color){205, 220, 240, 255};

  texto_renderizar(renderer, texto_x, texto_y, boton->texto, escala,
                   color_texto);
}

void estados_dibujar_menu(SDL_Renderer *renderer, const Boton *boton_jugar,
                          int ancho_ventana, int alto_ventana) {
  if (renderer == NULL || boton_jugar == NULL) {
    return;
  }

  // Fondo oscuro principal de la pantalla de bienvenida
  SDL_SetRenderDrawColor(renderer, 14, 16, 22, 255);
  SDL_RenderClear(renderer);

  // Titulo de cabecera en dorado
  const char *titulo = "ESCAPE DEL LABERINTO";
  float escala_titulo = 3.6f;
  float ancho_titulo = (float)strlen(titulo) * (8.0f * escala_titulo);
  float pos_x_titulo = ((float)ancho_ventana - ancho_titulo) / 2.0f;
  SDL_Color color_oro = {255, 215, 65, 255};
  texto_renderizar(renderer, pos_x_titulo, 240.0f, titulo, escala_titulo,
                   color_oro);

  // Subtitulo explicativo
  const char *subtitulo = "PROYECTO 2D EN C CON SDL3";
  float escala_sub = 2.0f;
  float ancho_sub = (float)strlen(subtitulo) * (8.0f * escala_sub);
  float pos_x_sub = ((float)ancho_ventana - ancho_sub) / 2.0f;
  SDL_Color color_sub = {150, 165, 185, 255};
  texto_renderizar(renderer, pos_x_sub, 305.0f, subtitulo, escala_sub,
                   color_sub);

  // Dibujar boton central de inicio
  boton_dibujar(renderer, boton_jugar);

  // Instrucciones al pie de ventana
  const char *instrucciones =
      "Haz clic en ENTRAR para iniciar | ESC para salir";
  float escala_inst = 1.6f;
  float ancho_inst = (float)strlen(instrucciones) * (8.0f * escala_inst);
  float pos_x_inst = ((float)ancho_ventana - ancho_inst) / 2.0f;
  SDL_Color color_inst = {110, 120, 140, 255};
  texto_renderizar(renderer, pos_x_inst, (float)alto_ventana - 90.0f,
                   instrucciones, escala_inst, color_inst);
}

void estados_dibujar_victoria(SDL_Renderer *renderer, Uint64 tiempo_record_ms,
                              const Boton *boton_reiniciar, int ancho_ventana,
                              int alto_ventana) {
  if (renderer == NULL || boton_reiniciar == NULL) {
    return;
  }

  // Fondo verde profundo de victoria
  SDL_SetRenderDrawColor(renderer, 10, 24, 18, 255);
  SDL_RenderClear(renderer);

  // Titulo victorioso en esmeralda
  const char *titulo = "[ VICTORIA: LABERINTO SUPERADO ]";
  float escala_titulo = 3.4f;
  float ancho_titulo = (float)strlen(titulo) * (8.0f * escala_titulo);
  float pos_x_titulo = ((float)ancho_ventana - ancho_titulo) / 2.0f;
  SDL_Color color_victoria = {65, 245, 150, 255};
  texto_renderizar(renderer, pos_x_titulo, 220.0f, titulo, escala_titulo,
                   color_victoria);

  // Mensaje con el tiempo congelado alcanzado
  char buffer_tiempo[32];
  hud_formatear_tiempo(tiempo_record_ms, buffer_tiempo, sizeof(buffer_tiempo));

  char texto_marca[64];
  snprintf(texto_marca, sizeof(texto_marca), "TIEMPO RECORD: %s",
           buffer_tiempo);

  float escala_marca = 2.6f;
  float ancho_marca = (float)strlen(texto_marca) * (8.0f * escala_marca);
  float pos_x_marca = ((float)ancho_ventana - ancho_marca) / 2.0f;
  SDL_Color color_oro = {255, 215, 65, 255};
  texto_renderizar(renderer, pos_x_marca, 310.0f, texto_marca, escala_marca,
                   color_oro);

  // Dibujar boton para volver a jugar
  boton_dibujar(renderer, boton_reiniciar);

  // Instrucciones de navegacion
  const char *instrucciones =
      "Haz clic en REINICIAR para intentar un mejor tiempo | ESC para salir";
  float escala_inst = 1.6f;
  float ancho_inst = (float)strlen(instrucciones) * (8.0f * escala_inst);
  float pos_x_inst = ((float)ancho_ventana - ancho_inst) / 2.0f;
  SDL_Color color_inst = {130, 160, 145, 255};
  texto_renderizar(renderer, pos_x_inst, (float)alto_ventana - 90.0f,
                   instrucciones, escala_inst, color_inst);
}
