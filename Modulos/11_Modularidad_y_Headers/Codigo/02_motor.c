/**
   ######################################################
   ##                                                  ##
   ##         Motor del Módulo (Implementación)        ## 
   ##                                                  ##
   ######################################################
**/

// Este archivo es el "Motor" de tu módulo. Aquí es donde los prototipos
// que prometiste en tu .h cobran vida y se ensucian las manos.

// 1. EL VÍNCULO (El contrato firmado)
// Incluimos nuestro propio header para que el compilador verifique que
// lo que escribimos aquí coincida con lo que prometimos a otros archivos.
#include "02_motor.h"
#include <stdio.h>
#include <string.h>

// 2. DEFINICIÓN DE LA VARIABLE GLOBAL (Solo en UN archivo .c)
// En el .h la declaramos con 'extern', aquí le damos memoria y valor.
int puntuacion_global = 0;

// 3. FUNCIONES PRIVADAS
// Usamos 'static' para que esta función sea INVISIBLE fuera de este archivo.
// Nadie desde el main.c (u otros archivos) podrá invocar a 'aplicar_veneno'.
// Es como un método privado en Programación Orientada a Objetos.
static void aplicar_veneno(Jugador *j) {
    if (j->estado == ESTADO_ENVENENADO) {
        printf("[SISTEMA] %s sufre los efectos del veneno. Pierde 5 de vida.\n", j->nombre);
        j->vida -= 5;
        
        if (j->vida <= 0) {
            j->vida = 0;
            j->estado = ESTADO_MUERTO;
            printf("[SISTEMA] %s no soportó el veneno y ha colapsado.\n", j->nombre);
        }
    }
}

// 4. IMPLEMENTACIÓN DE LA INTERFAZ PÚBLICA
// Estas funciones DEBEN tener la misma firma exacta que en 02_motor.h.

void inicializar_jugador(Jugador *j, const char *nombre) {
    strncpy(j->nombre, nombre, 49);
    j->nombre[49] = '\0';
    
    // MAX_VIDA y ESTADO_VIVO vienen directamente de 02_motor.h
    j->vida = MAX_VIDA; 
    j->estado = ESTADO_VIVO;
    j->arma_equipada = NULL;
    
    printf("[SISTEMA] El jugador '%s' ha sido creado e inicializado.\n", j->nombre);
}

void recibir_dano(Jugador *j, int cantidad) {
    if (j->estado == ESTADO_MUERTO) {
        printf("[SISTEMA] Deja en paz a %s, ¡ya está muerto!\n", j->nombre);
        return;
    }

    j->vida -= cantidad;
    printf("[SISTEMA] %s recibe %d puntos de daño. Vida restante: %d\n", j->nombre, cantidad, j->vida);

    if (j->vida <= 0) {
        j->vida = 0;
        j->estado = ESTADO_MUERTO;
        printf("[SISTEMA] %s ha muerto de forma dolorosa.\n", j->nombre);
    } else if (j->vida < 30 && j->estado != ESTADO_ENVENENADO) {
        // Solo para demostrar que podemos cambiar el enum
        j->estado = ESTADO_ENVENENADO;
        printf("[SISTEMA] ¡Advertencia! %s está sangrando mucho y se ha ENVENENADO.\n", j->nombre);
    }
    
    // Nuestra pequeña función privada invisible entra en acción
    aplicar_veneno(j);
}

void curar_jugador(Jugador *j, int cantidad) {
    if (j->estado == ESTADO_MUERTO) {
        printf("[SISTEMA] La magia curativa no funciona en cadáveres (%s).\n", j->nombre);
        return;
    }
    
    j->vida += cantidad;
    if (j->vida > MAX_VIDA) {
        j->vida = MAX_VIDA;
    }
    
    // Curar también quita el veneno
    if (j->estado == ESTADO_ENVENENADO) {
        j->estado = ESTADO_VIVO;
        printf("[SISTEMA] %s ha sido curado del veneno.\n", j->nombre);
    }
    
    printf("[SISTEMA] %s recupera %d puntos de vida. Vida actual: %d\n", j->nombre, cantidad, j->vida);
}

void imprimir_estado_jugador(const Jugador *j) {
    printf("\n==== ESTADO DE %s ====\n", j->nombre);
    printf("Salud: %d / %d\n", j->vida, MAX_VIDA);
    
    // Los enums son perfectos para usar dentro de un switch
    printf("Estado Físico: ");
    switch (j->estado) {
        case ESTADO_VIVO:
            printf("Sano y Fuerte\n");
            break;
        case ESTADO_ENVENENADO:
            printf("Envenenado (Perdiendo vida...)\n");
            break;
        case ESTADO_MUERTO:
            printf("Frío como el hielo\n");
            break;
    }
    
    if (j->arma_equipada != NULL) {
        printf("Arma: Daño (%d), Munición (%d)\n", 
               j->arma_equipada->dano, 
               j->arma_equipada->municion);
    } else {
        printf("Arma: Manos desnudas\n");
    }
    printf("========================\n\n");
}
