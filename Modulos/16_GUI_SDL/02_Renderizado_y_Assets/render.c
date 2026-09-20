/**
   ######################################################
   ##                                                  ##
   ##        Módulo 16 - Submódulo 2: Render           ##
   ##         (Implementación: Texturas GPU)           ##
   ##                                                  ##
   ######################################################
**/

#include "render.h"
#include <stdio.h>

// Carga un archivo de imagen buscando en rutas relativas locales y globales
static SDL_Texture *cargar_textura(SDL_Renderer *renderer, const char *nombre_archivo) {
    char ruta[256];
    const char *prefijos[] = { "../assets/", "assets/", "Modulos/16_GUI_SDL/assets/" };

    for (size_t i = 0; i < sizeof(prefijos) / sizeof(prefijos[0]); i++) {
        snprintf(ruta, sizeof(ruta), "%s%s", prefijos[i], nombre_archivo);
        SDL_Surface *superficie = SDL_LoadSurface(ruta);
        if (superficie != NULL) {
            SDL_Texture *textura = SDL_CreateTextureFromSurface(renderer, superficie);
            SDL_DestroySurface(superficie);

            if (textura != NULL) {
                // Activar filtrado lineal para suavizar el escalado y eliminar la pixelacion
                SDL_SetTextureScaleMode(textura, SDL_SCALEMODE_LINEAR);
                return textura;
            }
        }
    }

    fprintf(stderr, "[ERROR] No se pudo cargar la imagen: %s (%s)\n", nombre_archivo, SDL_GetError());
    return NULL;
}

bool render_cargar_texturas(SDL_Renderer *renderer, Texturas *texturas) {
    if (renderer == NULL || texturas == NULL) {
        return false;
    }

    // Inicializar punteros en NULL por seguridad
    texturas->pared = NULL;
    texturas->camino = NULL;
    texturas->salida = NULL;
    texturas->jugador = NULL;

    // Cargar sprites desde la carpeta compartida de assets con soporte multi-ruta
    texturas->camino = cargar_textura(renderer, "camino.png");
    texturas->pared = cargar_textura(renderer, "pared.png");
    texturas->salida = cargar_textura(renderer, "salida.png");
    texturas->jugador = cargar_textura(renderer, "player.png");

    // Verificar que todas las texturas se cargaron con exito
    if (!texturas->camino || !texturas->pared || !texturas->salida || !texturas->jugador) {
        fprintf(stderr, "[ERROR] Faltan texturas esenciales para renderizar el juego.\n");
        render_destruir_texturas(texturas);
        return false;
    }

    printf("-> [OK] Todas las texturas del juego fueron cargadas en la GPU exitosamente.\n");
    return true;
}

void render_dibujar_laberinto(SDL_Renderer *renderer, const Laberinto *laberinto, const Texturas *texturas) {
    if (renderer == NULL || laberinto == NULL || texturas == NULL) {
        return;
    }

    // Recorrer la matriz fila por fila para proyectar cada celda en pantalla
    for (int f = 0; f < laberinto->filas; f++) {
        for (int c = 0; c < laberinto->columnas; c++) {
            // Calcular rectangulo destino en pixeles dejando espacio superior para el HUD
            SDL_FRect destino = {
                (float)(c * TAM_TILE),
                (float)((f * TAM_TILE) + PANEL_HUD_ALTO),
                (float)TAM_TILE,
                (float)TAM_TILE
            };

            // Dibujar suelo base en todas las celdas para asegurar fondo solido
            SDL_RenderTexture(renderer, texturas->camino, NULL, &destino);

            // Dibujar elemento especifico segun el codigo de la matriz
            int celda = laberinto->celdas[f][c];
            if (celda == CELDA_PARED) {
                SDL_RenderTexture(renderer, texturas->pared, NULL, &destino);
            } else if (celda == CELDA_SALIDA) {
                SDL_RenderTexture(renderer, texturas->salida, NULL, &destino);
            }
        }
    }
}

void render_dibujar_jugador(SDL_Renderer *renderer, const Jugador *jugador, const Texturas *texturas) {
    render_dibujar_jugador_rotado(renderer, jugador, texturas, 0.0);
}

void render_dibujar_jugador_rotado(SDL_Renderer *renderer, const Jugador *jugador, const Texturas *texturas, double angulo) {
    if (renderer == NULL || jugador == NULL || texturas == NULL || texturas->jugador == NULL) {
        return;
    }

    // Ubicar el sprite del personaje en sus coordenadas logicas actuales
    SDL_FRect destino = {
        (float)(jugador->x * TAM_TILE),
        (float)((jugador->y * TAM_TILE) + PANEL_HUD_ALTO),
        (float)TAM_TILE,
        (float)TAM_TILE
    };

    // Renderizar textura con el angulo de orientacion indicado
    SDL_RenderTextureRotated(renderer, texturas->jugador, NULL, &destino, angulo, NULL, SDL_FLIP_NONE);
}

void render_destruir_texturas(Texturas *texturas) {
    if (texturas == NULL) {
        return;
    }

    // Liberar texturas de la memoria de video
    if (texturas->pared) {
        SDL_DestroyTexture(texturas->pared);
        texturas->pared = NULL;
    }
    if (texturas->camino) {
        SDL_DestroyTexture(texturas->camino);
        texturas->camino = NULL;
    }
    if (texturas->salida) {
        SDL_DestroyTexture(texturas->salida);
        texturas->salida = NULL;
    }
    if (texturas->jugador) {
        SDL_DestroyTexture(texturas->jugador);
        texturas->jugador = NULL;
    }
}
