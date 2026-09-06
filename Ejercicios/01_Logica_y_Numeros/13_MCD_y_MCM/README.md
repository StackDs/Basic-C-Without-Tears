# Máximo Común Divisor y Mínimo Común Múltiplo

El Máximo Común Divisor (MCD) de dos números enteros es el mayor entero que divide a ambos sin dejar residuo. El algoritmo de Euclides permite calcularlo eficientemente mediante divisiones sucesivas. Por su parte, el Mínimo Común Múltiplo (MCM) es el menor entero positivo divisible entre ambos, y se puede obtener mediante la relación $\text{MCM}(A, B) = \frac{A \times B}{\text{MCD}(A, B)}$. Escribe un programa que lea dos enteros positivos y determine su MCD y MCM.

## Entrada
La entrada consiste en una única línea que contiene dos números enteros positivos $A$ y $B$ separados por un espacio.

Límites: 1 <= A, B <= 10^9

## Salida
Imprime en una única línea dos números enteros separados por un espacio: el primer valor corresponde al MCD y el segundo al MCM.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 12 18 | 6 36 |
| 24 60 | 12 120 |
| 7 13 | 1 91 |
| 15 15 | 15 15 |
