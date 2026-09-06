# Recorrido y Estadísticas de Lista Enlazada

Recorrer una lista enlazada implica avanzar a través de los punteros `siguiente` desde la cabeza hasta encontrar el puntero nulo (`NULL`). Escribe un programa que construya una lista enlazada con $N$ elementos y calcule, mediante una función de recorrido, la cantidad total de nodos, la suma de sus valores y el promedio aritmético resultante (formateado a dos decimales).

## Entrada
La primera línea contiene un número entero positivo $N$.
La segunda línea contiene $N$ números enteros que se insertan en orden al final de la lista.

Límites:
- 1 <= N <= 1000
- -10^9 <= Elemento <= 10^9

## Salida
Tres líneas con el siguiente formato:
- `Nodos: N`
- `Suma: SUMA`
- `Promedio: PROM` (a dos decimales)

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 4<br>10 20 30 40 | Nodos: 4<br>Suma: 100<br>Promedio: 25.00 |
| 3<br>5 10 12 | Nodos: 3<br>Suma: 27<br>Promedio: 9.00 |
