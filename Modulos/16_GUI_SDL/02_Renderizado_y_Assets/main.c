/**
   ######################################################
   ##                                                  ##
   ##        Módulo 16 - Submódulo 2: Prueba           ##
   ##         (Main de renderizado de sprites)         ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <stdbool.h>
#include <SDL3/SDL.h>
#include "../01_Ventana_y_Ciclo/laberinto.h"
#include "../01_Ventana_y_Ciclo/ventana.h"
#include "render.h"

int main(void) {
    Laberinto laberinto;
    Jugador jugador;

    // Cargar laberinto desde el archivo de configuracion
    const char *ruta_mapa = "../assets/mapa.txt";
    if (!laberinto_cargar_desde_archivo(ruta_mapa, &laberinto, &jugador)) {
        fprintf(stderr, "Fallo al cargar el mapa desde: %s\n", ruta_mapa);
        return 1;
    }

    // Calcular dimensiones de la ventana
    int ancho_ventana = laberinto.columnas * TAM_TILE;
    int alto_ventana = (laberinto.filas * TAM_TILE) + PANEL_HUD_ALTO;

    // Crear ventana y renderer
    SDL_Window *ventana = NULL;
    SDL_Renderer *renderer = NULL;

    if (!ventana_inicializar(&ventana, &renderer, "Submodulo 2 - Renderizado de Laberinto", ancho_ventana, alto_ventana)) {
        laberinto_liberar(&laberinto);
        return 1;
    }

    // Cargar texturas desde los assets
    Texturas texturas;
    if (!render_cargar_texturas(renderer, &texturas)) {
        ventana_destruir(ventana, renderer);
        laberinto_liberar(&laberinto);
        return 1;
    }

    printf("-> Ejecutando bucle de renderizado. Cierra la ventana o presiona ESC para salir.\n");

    // Game loop con renderizado de la matriz y el jugador
    bool corriendo = true;
    SDL_Event evento;

    while (corriendo) {
        // Polling de eventos
        while (SDL_PollEvent(&evento)) {
            if (evento.type == SDL_EVENT_QUIT) {
                corriendo = false;
            } else if (evento.type == SDL_EVENT_KEY_DOWN) {
                if (evento.key.key == SDLK_ESCAPE) {
                    corriendo = false;
                }
            }
        }

        // Limpiar el fondo con un tono oscuro para el panel superior
        SDL_SetRenderDrawColor(renderer, 20, 20, 25, 255);
        SDL_RenderClear(renderer);

        // Dibujar el laberinto y el personaje
        render_dibujar_laberinto(renderer, &laberinto, &texturas);
        render_dibujar_jugador(renderer, &jugador, &texturas);

        // Presentar el cuadro en pantalla
        SDL_RenderPresent(renderer);
    }

    // Liberar texturas, ventana y matriz dinamica
    render_destruir_texturas(&texturas);
    ventana_destruir(ventana, renderer);
    laberinto_liberar(&laberinto);

    printf("-> Fin exitoso de la prueba del Submodulo 2.\n");
    return 0;
}
