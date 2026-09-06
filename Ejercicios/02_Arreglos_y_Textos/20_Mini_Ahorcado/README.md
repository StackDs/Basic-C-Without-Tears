# Mini Juego del Ahorcado

El juego del ahorcado consiste en adivinar una palabra secreta descubriendo sus letras antes de agotar una cantidad limitada de vidas o intentos permitidos. Escribe un programa que reciba una palabra secreta en mayúsculas, una cantidad de vidas iniciales $V$, y una serie de letras ingresadas por el jugador. Para cada intento, el programa debe imprimir el estado actual de la palabra (con las letras descubiertas y guiones bajos `_` en las ocultas) y las vidas restantes. El programa finaliza declarando `Victoria: PALABRA` o `Derrota: PALABRA`.

## Entrada
La primera línea contiene la palabra secreta (en mayúsculas) y el número entero de vidas $V$ separados por un espacio.
Las líneas siguientes contienen las letras ingresadas por el jugador.

Límites:
- 1 <= Longitud de la palabra <= 50
- 1 <= V <= 20

## Salida
Para cada letra intentada, imprime el estado actual de la palabra con espacios entre letras o guiones, seguido de `(Vidas: X)`.
En la última línea, imprime `Victoria: PALABRA` si se completan todas las letras, o `Derrota: PALABRA` si las vidas llegan a 0.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| HOLA 3<br>O A H L | _ O _ _ (Vidas: 3)<br>_ O _ A (Vidas: 3)<br>H O _ A (Vidas: 3)<br>H O L A (Vidas: 3)<br>Victoria: HOLA |
| SOL 2<br>X Z | _ _ _ (Vidas: 1)<br>_ _ _ (Vidas: 0)<br>Derrota: SOL |
