/**
   ######################################################
   ##                                                  ##
   ##        Módulo 16 - Submódulo 6: Proyecto Final   ##
   ##    (Juego Completo: Videojuego Laberinto 2D)     ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <stdbool.h>
#include <SDL3/SDL.h>
#include "../01_Ventana_y_Ciclo/laberinto.h"
#include "../01_Ventana_y_Ciclo/ventana.h"
#include "../02_Renderizado_y_Assets/render.h"
#include "../03_Interaccion_y_Eventos/input.h"
#include "../04_Texto_y_Cronometro/texto.h"
#include "../05_Pantallas_y_Estados/estados.h"
#include "audio.h"

int main(void) {
    Laberinto laberinto;
    Jugador jugador;

    // Intentar carga de mapa desde la raiz del modulo, carpeta superior o raiz del repo
    const char *ruta_mapa = "assets/mapa.txt";
    if (!laberinto_cargar_desde_archivo(ruta_mapa, &laberinto, &jugador)) {
        ruta_mapa = "../assets/mapa.txt";
        if (!laberinto_cargar_desde_archivo(ruta_mapa, &laberinto, &jugador)) {
            ruta_mapa = "Modulos/16_GUI_SDL/assets/mapa.txt";
            if (!laberinto_cargar_desde_archivo(ruta_mapa, &laberinto, &jugador)) {
                fprintf(stderr, "[ERROR] No se pudo encontrar el mapa del laberinto.\n");
                return 1;
            }
        }
    }

    // Almacenar coordenadas de spawn para permitir reinicios
    int spawn_x = jugador.x;
    int spawn_y = jugador.y;

    // Calcular dimensiones de ventana segun la cuadricula
    int ancho_ventana = laberinto.columnas * TAM_TILE;
    int alto_ventana = (laberinto.filas * TAM_TILE) + PANEL_HUD_ALTO;

    SDL_Window *ventana = NULL;
    SDL_Renderer *renderer = NULL;

    if (!ventana_inicializar(&ventana, &renderer, "Laberinto Escape - 2D Game (SDL3)", ancho_ventana, alto_ventana)) {
        laberinto_liberar(&laberinto);
        return 1;
    }

    Texturas texturas;
    if (!render_cargar_texturas(renderer, &texturas)) {
        ventana_destruir(ventana, renderer);
        laberinto_liberar(&laberinto);
        return 1;
    }

    // Inicializar subsistema de audio y precarga de efectos
    audio_inicializar();
    audio_reproducir_musica(true);

    // Botones de interfaz para el menu y la victoria
    float centro_x = (float)ancho_ventana / 2.0f;
    Boton boton_entrar = boton_crear(centro_x - 120.0f, 410.0f, 240.0f, 56.0f, "ENTRAR");
    Boton boton_reiniciar = boton_crear(centro_x - 140.0f, 420.0f, 280.0f, 56.0f, "JUGAR DE NUEVO");

    EstadoJuego estado = ESTADO_MENU;
    Uint64 tiempo_inicio = 0;
    Uint64 tiempo_final = 0;
    double angulo_jugador = 0.0;
    bool corriendo = true;

    printf("-> [SISTEMA] Videojuego iniciado con exito. Bienvenido a la aventura.\n");

    // Game Loop principal
    while (corriendo) {
        SDL_Event evento;
        while (SDL_PollEvent(&evento)) {
            if (evento.type == SDL_EVENT_QUIT) {
                corriendo = false;
            }

            if (evento.type == SDL_EVENT_KEY_DOWN && evento.key.key == SDLK_ESCAPE) {
                corriendo = false;
            }

            // Gestion de entradas segun la pantalla activa
            switch (estado) {
                case ESTADO_MENU:
                    if (evento.type == SDL_EVENT_MOUSE_MOTION) {
                        boton_actualizar_hover(&boton_entrar, evento.motion.x, evento.motion.y);
                    }
                    if (evento.type == SDL_EVENT_MOUSE_BUTTON_DOWN && evento.button.button == SDL_BUTTON_LEFT) {
                        if (boton_contiene_punto(&boton_entrar, evento.button.x, evento.button.y)) {
                            jugador.x = spawn_x;
                            jugador.y = spawn_y;
                            angulo_jugador = 0.0;
                            tiempo_inicio = SDL_GetTicks();
                            estado = ESTADO_JUGANDO;
                            audio_reproducir_musica(false);
                        }
                    }
                    break;

                case ESTADO_JUGANDO:
                    if (evento.type == SDL_EVENT_KEY_DOWN) {
                        int dx = 0;
                        int dy = 0;

                        switch (evento.key.key) {
                            case SDLK_UP:
                            case SDLK_W:
                                dy = -1;
                                angulo_jugador = 0.0;
                                break;
                            case SDLK_DOWN:
                            case SDLK_S:
                                dy = 1;
                                angulo_jugador = 180.0;
                                break;
                            case SDLK_LEFT:
                            case SDLK_A:
                                dx = -1;
                                angulo_jugador = 270.0;
                                break;
                            case SDLK_RIGHT:
                            case SDLK_D:
                                dx = 1;
                                angulo_jugador = 90.0;
                                break;
                            default:
                                break;
                        }

                        // Intentar desplazar al personaje
                        if (dx != 0 || dy != 0) {
                            if (jugador_intentar_mover(&jugador, &laberinto, dx, dy)) {
                                audio_reproducir_paso();
                            }
                        }

                        // Verificar si se piso la casilla de salida
                        if (laberinto_es_salida(&laberinto, jugador.x, jugador.y)) {
                            tiempo_final = SDL_GetTicks() - tiempo_inicio;
                            estado = ESTADO_VICTORIA;
                            audio_detener_musica();
                            audio_reproducir_victoria();
                        }
                    }
                    break;

                case ESTADO_VICTORIA:
                    if (evento.type == SDL_EVENT_MOUSE_MOTION) {
                        boton_actualizar_hover(&boton_reiniciar, evento.motion.x, evento.motion.y);
                    }
                    if (evento.type == SDL_EVENT_MOUSE_BUTTON_DOWN && evento.button.button == SDL_BUTTON_LEFT) {
                        if (boton_contiene_punto(&boton_reiniciar, evento.button.x, evento.button.y)) {
                            jugador.x = spawn_x;
                            jugador.y = spawn_y;
                            angulo_jugador = 0.0;
                            tiempo_inicio = SDL_GetTicks();
                            estado = ESTADO_JUGANDO;
                            audio_reproducir_musica(true);
                        }
                    }
                    break;
            }
        }

        // Renderizado del cuadro actual
        switch (estado) {
            case ESTADO_MENU:
                estados_dibujar_menu(renderer, &boton_entrar, ancho_ventana, alto_ventana);
                break;

            case ESTADO_JUGANDO: {
                SDL_SetRenderDrawColor(renderer, 18, 18, 22, 255);
                SDL_RenderClear(renderer);

                render_dibujar_laberinto(renderer, &laberinto, &texturas);
                render_dibujar_jugador_rotado(renderer, &jugador, &texturas, angulo_jugador);

                Uint64 transcurrido = SDL_GetTicks() - tiempo_inicio;
                hud_renderizar(renderer, transcurrido, ancho_ventana);
                break;
            }

            case ESTADO_VICTORIA:
                estados_dibujar_victoria(renderer, tiempo_final, &boton_reiniciar, ancho_ventana, alto_ventana);
                break;
        }

        SDL_RenderPresent(renderer);
    }

    // Liberacion rigurosa de todos los recursos
    audio_liberar();
    render_destruir_texturas(&texturas);
    ventana_destruir(ventana, renderer);
    laberinto_liberar(&laberinto);

    printf("-> [SISTEMA] Cierre ordenado y memoria liberada correctamente.\n");
    return 0;
}
