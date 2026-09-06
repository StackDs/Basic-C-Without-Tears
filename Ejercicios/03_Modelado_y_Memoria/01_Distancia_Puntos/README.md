# Distancia entre Dos Puntos

El modelado de coordenadas en un plano bidimensional mediante estructuras (`struct`) permite agrupar las variables $x$ e $y$ en un único tipo de dato coherente. La distancia euclidiana entre dos puntos $P_1(x_1, y_1)$ y $P_2(x_2, y_2)$ se calcula mediante la fórmula:
$$d = \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}$$
Escribe un programa que defina la estructura `struct Punto`, lea las coordenadas de dos puntos y calcule la distancia euclidiana entre ellos.

## Entrada
La primera línea contiene dos números reales $x_1$ e $y_1$ (coordenadas del primer punto).
La segunda línea contiene dos números reales $x_2$ e $y_2$ (coordenadas del segundo punto).

Límites:
- -10^4 <= x_1, y_1, x_2, y_2 <= 10^4

## Salida
Imprime una única línea con el formato `Distancia: D`, donde `D` es el valor de la distancia euclidiana formateado a dos decimales.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 0.0 0.0<br>3.0 4.0 | Distancia: 5.00 |
| 1.5 2.5<br>4.5 6.5 | Distancia: 5.00 |
| -2.0 -1.0<br>1.0 3.0 | Distancia: 5.00 |
