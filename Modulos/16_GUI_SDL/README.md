# Módulo 16: Interfaz Gráfica y Videojuegos con SDL3

*¿Cansado de la aburrida y monocromática terminal negra? Es hora de ponerle color, sonido, física e interacción a tus ideas. Descubre cómo construir un videojuego 2D completo desde cero con el poder de **SDL3** y la arquitectura modular de C.*

<p align="center">
  <img src="assets/sdl3.jpeg" alt="SDL3" width="550">
</p>

<div align="center">
  <h3><a href="./01_Ventana_y_Ciclo/README.md">🚀 Entrar al Submódulo 1</a></h3>
</div>

## 🎯 Proyecto del Módulo: Laberinto de Escape 2D ($31 \times 21$)

Aprenderemos a través de un proyecto práctico incremental dividido en 6 submódulos con sus propias carpetas dedicadas:

1. [**Submódulo 01: Estructuras Base, Ventana y Ciclo de Eventos**](./01_Ventana_y_Ciclo/README.md)  
   *Carga dinámica de `mapa.txt` en el Heap con `malloc`, log por consola de la matriz en números crudos, inicialización de SDL3, ventana negra acelerada por GPU y el Game Loop.*
2. **Submódulo 02: Renderizado y Carga de Texturas**  
   *Dibujo de tiles en pantalla, carga de sprites desde `assets/` (pared, camino, salida, jugador) y coordenadas de render.*
3. **Submódulo 03: Interacción y Manejo de Eventos (Input)**  
   *Procesamiento de flechas del teclado, colisiones sólidas contra paredes y detección de victoria.*
4. **Submódulo 04: Tipografía y Cronómetro en Pantalla (SDL3_ttf)**  
   *Renderizado de texto con fuentes TrueType y cronómetro de escape en tiempo real.*
5. **Submódulo 05: Máquina de Estados y Pantallas de Menú/Victoria**  
   *Gestión de estados (Menú, Jugando, Fin de Partida), botón interactivo "Entrar" y pantalla de récord final.*
6. **Submódulo 06: Efectos de Sonido, Música y Construcción Final**  
   *Música de fondo en bucle, efectos sonoros, orquestación en `main.c` y el `Makefile` unificado del proyecto.*

## 📁 Estructura del Módulo

* [`assets/`](./assets/): Texturas (`pared.jpg`, `camino.jpg`, `player.png`, `salida.png`), logo [`sdl3.jpeg`](./assets/sdl3.jpeg) y el diseño dinámico [`mapa.txt`](./assets/mapa.txt).
* [`01_Ventana_y_Ciclo/`](./01_Ventana_y_Ciclo/): Código y guía teórica de estructuras dinámicas, ventana y ciclo base.

## 🏆 Lo que dominarás al terminar
Serás capaz de diseñar un videojuego 2D estructurado y modular en C puro, integrando librerías multimedia avanzadas sin depender de motores gráficos pesados ni abstracciones mágicas.

---

<div align="center">
  <a href="../15_Debug/README.md">⬅️ Anterior: Debug</a> | <a href="../../Anexos/README.md">Siguiente: Anexos ➡️</a>
</div>
