# Módulo 15: Debugging

Como ya te habrás dado cuenta, todos escribimos código que falla (y mucho). Es ley de vida que algo va a salir mal. Si tu programa es muy grande no sabrás dónde está el problema, o al menos no sabrás dónde está el problema sin antes imprimir mil y una líneas en la terminal. La realidad es que en entornos profesionales nadie te va a dejar poner printf en el código de alguien más. Por eso en este módulo aprenderemos a usar GDB, que son herramientas que te permiten depurar tu código.

<div align="center">
  <h3><a href="./15_Debug.md">🚀 Entrar al Módulo</a></h3>
</div>

## 🎯 ¿Qué veremos en este módulo?

*   **El arte de cazar bugs:** Más allá de llenar el código de printf.
*   **GDB:** El depurador estándar de GNU.
*   **Valgrind:** Herramientas para detectar fugas de memoria.

## 💻 Prácticas de Código

*   [`01_puntero_nulo.c`](./Codigo/01_puntero_nulo.c): Ejemplo práctico sobre puntero nulo.
*   [`02_memory_leak.c`](./Codigo/02_memory_leak.c): Ejemplo práctico sobre memory leak.
*   [`03_out_of_bounds.c`](./Codigo/03_out_of_bounds.c): Ejemplo práctico sobre out of bounds.
*   [`04_stack_overflow.c`](./Codigo/04_stack_overflow.c): Ejemplo práctico sobre stack overflow.
*   [`05_integer_overflow.c`](./Codigo/05_integer_overflow.c): Ejemplo práctico sobre integer overflow.

## 🏆 Lo que dominarás al terminar
Perderás el miedo a los fallos invisibles. Serás capaz de pausar la ejecución en tiempo real e inspeccionar la memoria para encontrar Memory Leaks.

---

<div align="center">
  <a href="../14_Operaciones_de_Bits/README.md">⬅️ Anterior</a> | <a href="../16_GUI_SDL/README.md">Siguiente ➡️</a>
</div>
