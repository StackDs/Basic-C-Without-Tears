/**
   ######################################################
   ##                                                  ##
   ##              Modularidad y Headers               ##
   ##                                                  ##
   ######################################################
**/

// Este archivo demuestra la estructura correcta de un archivo de cabecera (.h).
// Representa la "Interfaz Pública" o "Contrato" de tu módulo.
// No pongas lógica (código entre llaves) ni inicialices variables globales aquí.

// 1. GUARDAS DE INCLUSIÓN (Include Guards)
// Protege al compilador de incluir este archivo múltiples veces y explotar.
#pragma once

// Si quisieras usar la forma clásica (que es a prueba de balas incluso
// en compiladores prehistóricos), usarías esto en su lugar:
/*
#ifndef MOTOR_H
#define MOTOR_H
... todo el contenido ...
#endif
*/

#include <stdio.h> // Inclusión de sistema

// 2. DEFINICIÓN DE MACROS Y CONSTANTES GLOBALES
#define MAX_VIDA 100
#define MULTIPLICADOR_DANO 1.5

// 3. ENUMS (Enumeraciones)
// No los vimos formalmente, pero aquí te los dejo.
// Los enums te permiten crear tipos de datos que solo pueden tener
// un conjunto específico de valores (por debajo, son solo enteros 0, 1, 2...).
// Hacen tu código 10 veces más legible que usar puros números mágicos.
typedef enum {
    ESTADO_VIVO,        // Vale 0
    ESTADO_MUERTO,      // Vale 1
    ESTADO_ENVENENADO   // Vale 2
} EstadoJugador;

// 4. FORWARD DECLARATIONS (Declaraciones Anticipadas)
// Le decimos al compilador: "Existe un struct llamado Arma, créeme. 
// No necesitas saber qué tiene adentro todavía, solo confía."
// Esto evita dependencias circulares horribles.
typedef struct Arma Arma;

// 5. DECLARACIÓN DE STRUCTS
typedef struct {
    char nombre[50];
    int vida;
    EstadoJugador estado; // Usando el enum que creamos arriba
    Arma *arma_equipada;  // Usando el forward declaration. Solo un puntero.
} Jugador;

// (Para efectos prácticos de este ejemplo, definimos 'Arma' aquí mismo. 
// En un proyecto real inmenso, 'Arma' probablemente viviría en su propio armas.h)
struct Arma {
    int municion;
    int dano;
};

// 6. VARIABLES GLOBALES COMPARTIDAS (Promesa)
// 'extern' significa: "Esta variable existe en ALGÚN archivo .c. 
// Compílalo tranquilamente, el Linker ya la encontrará luego."
extern int puntuacion_global;

// 7. PROTOTIPOS DE FUNCIONES (Firmas)
// Esto es lo que los otros archivos pueden llamar. Fíjate que terminan
// en punto y coma (;). Sin llaves y sin implementar el código.

void inicializar_jugador(Jugador *j, const char *nombre);
void recibir_dano(Jugador *j, int cantidad);
void curar_jugador(Jugador *j, int cantidad);
void imprimir_estado_jugador(const Jugador *j);
