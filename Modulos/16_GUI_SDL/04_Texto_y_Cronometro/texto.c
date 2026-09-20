/**
   ######################################################
   ##                                                  ##
   ##        Módulo 16 - Submódulo 4: Texto            ##
   ##       (Implementación: Tipografía y HUD)         ##
   ##                                                  ##
   ######################################################
**/

#include "texto.h"
#include <stdio.h>
#include <string.h>

void texto_renderizar(SDL_Renderer *renderer, float x, float y, const char *texto, float escala, SDL_Color color) {
    if (renderer == NULL || texto == NULL || escala <= 0.0f) {
        return;
    }

    // Respaldar la escala previa del renderer
    float prev_sx = 1.0f;
    float prev_sy = 1.0f;
    SDL_GetRenderScale(renderer, &prev_sx, &prev_sy);

    // Configurar la escala para aumentar el tamaño de fuente
    SDL_SetRenderScale(renderer, escala, escala);

    // Asignar el color de trazado solicitado
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    // Dibujar el texto ajustando las coordenadas a la escala aplicada
    SDL_RenderDebugText(renderer, x / escala, y / escala, texto);

    // Restaurar la escala original del renderer
    SDL_SetRenderScale(renderer, prev_sx, prev_sy);
}

void hud_formatear_tiempo(Uint64 milisegundos, char *buffer, size_t tam_buffer) {
    if (buffer == NULL || tam_buffer == 0) {
        return;
    }

    Uint64 total_segundos = milisegundos / 1000;
    Uint64 minutos = total_segundos / 60;
    Uint64 segundos = total_segundos % 60;
    Uint64 centesimas = (milisegundos % 1000) / 10;

    snprintf(buffer, tam_buffer, "%02llu:%02llu.%02llu",
             (unsigned long long)minutos,
             (unsigned long long)segundos,
             (unsigned long long)centesimas);
}

void hud_renderizar(SDL_Renderer *renderer, Uint64 tiempo_transcurrido_ms, int ancho_ventana) {
    if (renderer == NULL) {
        return;
    }

    // Dibujar fondo oscuro del panel superior
    SDL_FRect panel_hud = {
        0.0f,
        0.0f,
        (float)ancho_ventana,
        64.0f
    };
    SDL_SetRenderDrawColor(renderer, 22, 24, 30, 255);
    SDL_RenderFillRect(renderer, &panel_hud);

    // Dibujar linea divisoria inferior del HUD
    SDL_SetRenderDrawColor(renderer, 75, 82, 98, 255);
    SDL_RenderLine(renderer, 0.0f, 63.0f, (float)ancho_ventana, 63.0f);

    // Renderizar titulo del juego en el lateral izquierdo
    SDL_Color color_titulo = { 230, 235, 245, 255 };
    texto_renderizar(renderer, 24.0f, 22.0f, "LABERINTO ESCAPE", 2.2f, color_titulo);

    // Renderizar cronometro formateado en el lateral derecho
    char tiempo_str[32];
    hud_formatear_tiempo(tiempo_transcurrido_ms, tiempo_str, sizeof(tiempo_str));

    char cronometro_texto[64];
    snprintf(cronometro_texto, sizeof(cronometro_texto), "TIEMPO: %s", tiempo_str);

    SDL_Color color_cronometro = { 72, 230, 160, 255 };
    float ancho_estimado = (float)(strlen(cronometro_texto) * 8) * 2.2f;
    float pos_x_tiempo = (float)ancho_ventana - ancho_estimado - 24.0f;

    texto_renderizar(renderer, pos_x_tiempo, 22.0f, cronometro_texto, 2.2f, color_cronometro);
}
