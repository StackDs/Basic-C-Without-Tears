/**
   ######################################################
   ##                                                  ##
   ##        Módulo 16 - Submódulo 1: Ventana          ##
   ##         (Implementación: Video y Eventos)        ##
   ##                                                  ##
   ######################################################
**/

#include "ventana.h"
#include <stdio.h>

bool ventana_inicializar(SDL_Window **ventana, SDL_Renderer **renderer,
                         const char *titulo, int ancho, int alto) {
  if (ventana == NULL || renderer == NULL) {
    fprintf(stderr, "[ERROR] Punteros de ventana o renderer inválidos.\n");
    return false;
  }

  // Inicializar el subsistema de video de SDL3
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_Log("ERROR al inicializar SDL3: %s", SDL_GetError());
    return false;
  }

  // Crear la ventana física y el contexto de renderizado acelerado por GPU
  if (!SDL_CreateWindowAndRenderer(titulo, ancho, alto, 0, ventana, renderer)) {
    SDL_Log("ERROR al crear ventana y renderer: %s", SDL_GetError());
    SDL_Quit();
    return false;
  }

  printf("-> [OK] Ventana SDL3 inicializada correctamente (%d x %d px).\n",
         ancho, alto);
  return true;
}

void ventana_ejecutar_ciclo_base(SDL_Renderer *renderer) {
  if (renderer == NULL) {
    return;
  }

  printf("-> Entrando al Game Loop base (pantalla negra activa)...\n");
  printf(
      "-> Haz clic en la 'X' de la ventana o presiona [ESC] para salir.\n\n");

  bool corriendo = true;
  SDL_Event evento;

  while (corriendo) {
    // 1. Procesar todos los eventos de la cola
    while (SDL_PollEvent(&evento)) {
      if (evento.type == SDL_EVENT_QUIT) {
        corriendo = false;
      } else if (evento.type == SDL_EVENT_KEY_DOWN) {
        if (evento.key.key == SDLK_ESCAPE) {
          corriendo = false;
        }
      }
    }

    // 2. Limpiar el búfer de dibujo con color negro puro (R=0, G=0, B=0,
    // Alpha=255)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // 3. Intercambiar el búfer trasero con la pantalla visible (Double
    // Buffering)
    SDL_RenderPresent(renderer);
  }

  printf("-> Saliendo del Game Loop base...\n");
}

void ventana_destruir(SDL_Window *ventana, SDL_Renderer *renderer) {
  printf("-> Liberando recursos de video y cerrando SDL3...\n");

  if (renderer != NULL) {
    SDL_DestroyRenderer(renderer);
  }
  if (ventana != NULL) {
    SDL_DestroyWindow(ventana);
  }

  SDL_Quit();
  printf("-> [OK] Memoria de GPU y subsistema SDL3 liberados exitosamente.\n");
}
