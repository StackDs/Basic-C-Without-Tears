# Inversión de Arreglo (In-Place)

Invertir los elementos de un arreglo modificando directamente su memoria original (*in-place*) es una técnica que optimiza el uso de espacio al evitar la asignación de un segundo arreglo auxiliar. La estrategia consiste en intercambiar los elementos simétricos desde los extremos hacia el centro. Escribe un programa que lea un arreglo de $N$ números enteros y lo invierta directamente sobre el mismo arreglo.

## Entrada
La primera línea contiene un número entero positivo $N$ que representa la cantidad de elementos.
La segunda línea contiene $N$ números enteros separados por espacios.

Límites:
- 1 <= N <= 1000
- -10^9 <= Elemento <= 10^9

## Salida
Imprime los $N$ elementos invertidos separados por un espacio en una sola línea.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 5<br>1 2 3 4 5 | 5 4 3 2 1 |
| 4<br>10 20 30 40 | 40 30 20 10 |
| 1<br>99 | 99 |
