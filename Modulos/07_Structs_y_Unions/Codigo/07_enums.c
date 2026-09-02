#include <stdio.h>
#include <string.h>

// 1. Definimos nuestro Enum
// Por defecto ORCO seria 0, GOBLIN 1, TROLL 2.
typedef enum { 
    ORCO, 
    GOBLIN, 
    TROLL 
} TipoEnemigo;

// 2. Definimos nuestro Struct que utiliza el Enum
typedef struct {
    char nombre[30];
    int vida;
    TipoEnemigo tipo;
} Enemigo;

// Funcion que demuestra el poder de combinar enum + switch
void interactuar_con_enemigo(Enemigo *e) {
    printf("Te encuentras con %s (Vida: %d)...\n", e->nombre, e->vida);
    
    // El switch se lee como ingles puro, sin numeros magicos
    switch (e->tipo) {
        case ORCO:
            printf("  -> El Orco ruge: '¡Por la horda!'\n");
            break;
        case GOBLIN:
            printf("  -> El Goblin grita: '¡El tiempo es oro, amigo!'\n");
            break;
        case TROLL:
            printf("  -> El Troll rie: '¡Dingo!'\n");
            break;
        default:
            printf("  -> Enemigo desconocido.\n");
            break;
    }
    printf("\n");
}

int main(void) {
    printf("\n=== 8. Enumeraciones (enum) y Structs ===\n\n");
    
    // Instanciamos usando nuestro enum de forma natural
    Enemigo jefe_orco = {"Grommash", 100, ORCO};
    Enemigo mercader = {"Gallywix", 30, GOBLIN};
    Enemigo cazador = {"Vol'jin", 80, TROLL};
    
    interactuar_con_enemigo(&jefe_orco);
    interactuar_con_enemigo(&mercader);
    interactuar_con_enemigo(&cazador);
    
    // Demostracion interna de C:
    // Para el compilador, e.tipo sigue siendo simplemente un int.
    printf("--- Dato curioso ---\n");
    printf("Valor entero real de ORCO: %d\n", ORCO);
    printf("Valor entero real de TROLL: %d\n", TROLL);
    
    return 0;
}
