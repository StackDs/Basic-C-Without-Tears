# Inserción al Inicio en Lista Simplemente Enlazada

Una lista simplemente enlazada está compuesta por nodos dinámicos donde cada nodo almacena un dato y un puntero hacia el siguiente nodo de la secuencia. La inserción al inicio se realiza en tiempo constante $O(1)$ actualizando el puntero raíz de la lista. Escribe un programa que inserte sucesivamente $N$ elementos al inicio de una lista y muestre la lista resultante.

## Entrada
La primera línea contiene un número entero positivo $N$ (cantidad de inserciones).
La segunda línea contiene $N$ números enteros en el orden en que deben insertarse.

Límites:
- 1 <= N <= 1000
- -10^9 <= Elemento <= 10^9

## Salida
Imprime una única línea con la representación visual de la lista enlazada: `Lista: elem1 -> elem2 -> ... -> NULL`.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 4<br>10 20 30 40 | Lista: 40 -> 30 -> 20 -> 10 -> NULL |
| 1<br>99 | Lista: 99 -> NULL |
