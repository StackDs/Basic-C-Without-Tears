# Simulador de Reloj

Un reloj digital avanza segundo a segundo en ciclos de $60$ segundos, $60$ minutos y $24$ horas. Cuando los segundos alcanzan $60$, se reinician a $0$ e incrementan los minutos; de manera similar, al alcanzar $60$ minutos se incrementa la hora, y al llegar a $24$ horas el contador vuelve a $00:00:00$. Escribe un programa que reciba una hora inicial ($H, M, S$) y un número de segundos $T$, e imprima el estado del reloj en cada uno de los $T$ segundos transcurridos en formato digital `HH:MM:SS`.

## Entrada
La entrada consiste en una única línea que contiene cuatro números enteros $H$, $M$, $S$ y $T$ separados por espacios, donde $H, M, S$ representan la hora, minuto y segundo inicial, y $T$ la cantidad de segundos a avanzar.

Límites:
- 0 <= H <= 23
- 0 <= M <= 59
- 0 <= S <= 59
- 1 <= T <= 1000

## Salida
Imprime $T$ líneas donde cada línea contiene el tiempo transcurrido con dos dígitos por campo (`HH:MM:SS`).

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 23 59 58 4 | 23:59:59<br>00:00:00<br>00:00:01<br>00:00:02 |
| 12 30 15 2 | 12:30:16<br>12:30:17 |
