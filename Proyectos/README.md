# Proyectos Propuestos: C Without Tears

Bienvenido al directorio de **Proyectos Propuestos** de **Basic-C-Without-Tears**. A diferencia de los ejercicios individuales que son desafíos atómicos enfocados en conceptos específicos, aquí podrás encontrar proyectos completos con un nivel de dificultad medio/alto, los proyectos fueron elegidos con el fin de poner en práctica de manera global lo aprendido.

Estos proyectos están diseñados para ser abordados de forma progresiva, permitiendo implementaciones en modo texto/consola o evolucionando hacia interfaces gráficas (por ejemplo con librerías como SDL3 o Raylib).

---

## 🎯 Categorías de Proyectos

Los proyectos se encuentran clasificados en **3 categorías temáticas**, cada una orientada al desarrollo de habilidades técnicas y arquitectónicas específicas:

### 1. [🎮 Videojuegos](./01_Videojuegos/) (12 Proyectos)
**Orientación y Habilidades Clave**:
Esta categoría está enfocada en el diseño y la construcción de motores de juegos interactivos en tiempo real y por turnos. Aquí aprenderás a estructurar el ciclo principal del juego (*Game Loop*), gestionar tasas de refresco (FPS), procesar entradas continuas de usuario (teclado/ratón), detectar colisiones en cuadrículas y planos continuos, manejar máquinas de estados (menús, cinemáticas, pausa, niveles, pantalla de fin de juego) e implementar algoritmos de inteligencia artificial elemental (búsqueda de caminos, máquinas de estados finitos y comportamiento de enemigos).

- **Proyectos disponibles**:
  
   - [`01_Pacman`](./01_Videojuegos/01_Pacman/): Clásico juego de laberintos, recolección de píldoras y comportamiento de fantasmas.  
   - [`02_Bomberman`](./01_Videojuegos/02_Bomberman/): Colocación de bombas, propagación de explosiones y destrucción de bloques.
   - [`03_Battleship`](./01_Videojuegos/03_Battleship/): Estrategia por turnos y combate naval sobre matrices de coordenadas ocultas.
   - [`04_Battle_City`](./01_Videojuegos/04_Battle_City/): Batalla de tanques en 2D, proyectiles balísticos y defensa de la base.
   - [`05_Snake`](./01_Videojuegos/05_Snake/): Movimiento continuo, cola dinámica con listas enlazadas y generación de comida.
   - [`06_Tetris`](./01_Videojuegos/06_Tetris/): Caída de tetrominós, rotación matricial y limpieza de líneas completas.
   - [`07_Buscaminas`](./01_Videojuegos/07_Buscaminas/): Despeje de casillas mediante recursión (*Flood Fill*) y conteo de minas adyacentes.
   - [`08_Plants_vs_Zombies`](./01_Videojuegos/08_Plants_vs_Zombies/): Defensa de torres por carriles con oleadas de zombis y recolección de soles.
   - [`09_Clon_Stardew_Valley`](./01_Videojuegos/09_Clon_Stardew_Valley/): Simulación agrícola con ciclo día/noche, siembra, regado y crecimiento de cultivos.
   - [`10_Aventura_Point_and_Click`](./01_Videojuegos/10_Aventura_Point_and_Click/): Narrativa interactiva basada en nodos de decisiones, inventario y acertijos.
   - [`11_Clon_Cookie_Clicker`](./01_Videojuegos/11_Clon_Cookie_Clicker/): Juego incremental con producción pasiva de recursos, multiplicadores y mejoras.
   - [`12_Juego_Sigilo_Top_Down`](./01_Videojuegos/12_Juego_Sigilo_Top_Down/): Infiltración en vista cenital con conos de visión para guardias y sigilo en sombras.

---

### 2. [🔬 Simulación](./02_Simulacion/) (6 Proyectos)
**Orientación y Habilidades Clave**:
Esta categoría se centra en el modelado matemático, la teoría de sistemas dinámicos, autómatas celulares y la simulación basada en agentes. Aprenderás a implementar reglas locales deterministas y probabilísticas que generan comportamientos emergentes complejos a gran escala, matrices de doble búfer para cálculo paralelo en el tiempo y técnicas de renderizado visual continuo de datos científicos.

- **Proyectos disponibles**:
   - [`01_Simulador_Circuitos_Logicos`](./02_Simulacion/01_Simulador_Circuitos_Logicos/): Evaluación de compuertas booleanas interconectadas (AND, OR, NOT, XOR, Flip-Flops).
   - [`02_Ecosistema_Vida_Artificial`](./02_Simulacion/02_Ecosistema_Vida_Artificial/): Simulación de presas y depredadores con energía, reproducción y mutaciones simples.
   - [`03_Juego_de_la_Vida`](./02_Simulacion/03_Juego_de_la_Vida/): El célebre autómata celular de John Conway con actualización de matrices mediante doble búfer.
   - [`04_Hormiga_de_Langton`](./02_Simulacion/04_Hormiga_de_Langton/): Autómata celular bidimensional con comportamiento caótico y posterior autopista emergente.
   - [`05_Simulador_Trafico`](./02_Simulacion/05_Simulador_Trafico/): Modelo de tráfico urbano con intersecciones viales, semáforos temporizados y colas de vehículos.
   - [`06_Modelo_Epidemiologico`](./02_Simulacion/06_Modelo_Epidemiologico/): Modelado poblacional de contagio y propagación de virus (modelo epidemiológico SIR / SEIR).

---

### 3. [📊 Dashboards y Gestión](./03_Dashboards_y_Gestion/) (4 Proyectos)
**Orientación y Habilidades Clave**:
Esta categoría aborda el desarrollo de software de aplicación empresarial y sistemas administrativos. Su objetivo es dominar la arquitectura en capas (separación de lógica de negocio, interfaz de usuario y almacenamiento), la persistencia transaccional en archivos binarios (`.bin` / `.dat`), la validación estricta de datos de entrada, el cálculo de métricas financieras y estadísticas en tiempo real (KPIs), y la generación de reportes estructurados.

- **Proyectos disponibles**:
   - [`01_Dashboard_Financiero`](./03_Dashboards_y_Gestion/01_Dashboard_Financiero/): Registro de ingresos y gastos, cálculo de balances, presupuestos y gráficos ASCII de tendencias.
   - [`02_Sistema_Reserva_Cines`](./03_Dashboards_y_Gestion/02_Sistema_Reserva_Cines/): Gestión de salas, cartelera, selección visual de butacas y venta de boletos con persistencia.
   - [`03_Sistema_Reserva_Vuelos`](./03_Dashboards_y_Gestion/03_Sistema_Reserva_Vuelos/): Reserva de vuelos comerciales, asignación de asientos por clase y emisión de pases de abordar.
   - [`04_Sistema_Planes_Gimnasio`](./03_Dashboards_y_Gestion/04_Sistema_Planes_Gimnasio/): Control de socios, planes de membresía, control de accesos y alertas de vencimiento.

---

## 💡 Recomendaciones para el Desarrollo

1. **Modularidad**: Divide tu código en módulos lógicos con archivos de cabecera (`.h`) y archivos de implementación (`.c`). Evita colocar todo el código en un único archivo.
2. **Automatización**: Crea un `Makefile` para compilar automáticamente todos los módulos de tu proyecto.
3. **Control de Memoria**: Comprueba siempre los retornos de `malloc` y `realloc`, y asegúrate de liberar (`free`) cada recurso asignado. Utiliza herramientas como `Valgrind` para verificar la ausencia de fugas de memoria.
4. **Persistencia Segura**: Diseña estructuras binarias con campos de tamaño fijo para garantizar que los datos se puedan guardar y leer consistentemente en disco.
5. **Visualización**: Incorpora entornos visuales usando SDL3 o cualquier biblioteca visual de tu preferencia.

---

## 🖕 Colaboración 

Con el fin de que este repositorio crezca y funcione como un banco de código para C en español, si consideras que tu proyecto es de buena calidad, enviamelo ya sea a mi contacto **codbryxp@gmail.com** o envia una pull request al repositorio. Y con gusto lo subiré con los respectivos créditos, solo no hagas mucho con IA que me voy a dar cuenta, uso mucho esa basura XD.

