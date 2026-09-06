# Juego de Adivinanza

El juego de adivinanza numérica es un ejercicio representativo para trabajar con bucles de control interactivos y toma de decisiones condicionales. El programa recibe primero el número secreto $S$ fijado para la partida (entre $1$ y $100$) y luego una secuencia de números que representan los intentos sucesivos del jugador. Para cada intento, el programa responde `Mas alto` si el número secreto es mayor, `Mas bajo` si es menor, o `Correcto en K intentos.` al acertar, concluyendo la ejecución.

## Entrada
La primera línea contiene un número entero $S$ que representa el número secreto a adivinar.
Las líneas siguientes contienen números enteros que corresponden a cada uno de los intentos realizados por el jugador.

Límites:
- 1 <= S <= 100
- 1 <= Intento <= 100

## Salida
Para cada intento incorrecto, imprime una línea con `Mas alto` o `Mas bajo`. Al acertar, imprime una línea con `Correcto en K intentos.` (donde $K$ es la cantidad de intentos efectuados) y finaliza el programa.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 42<br>50<br>25<br>37<br>42 | Mas bajo<br>Mas alto<br>Mas alto<br>Correcto en 4 intentos. |
| 70<br>70 | Correcto en 1 intentos. |
