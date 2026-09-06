# Matriz Dinámica con Punteros Dobles

En C, una matriz 2D con dimensiones definidas en tiempo de ejecución se construye frecuentemente mediante un puntero a punteros (`int **`), donde el puntero principal apunta a un arreglo de punteros a fila, y cada uno de estos apunta a un bloque de columnas. Escribe un programa que asigne dinámicamente una matriz de $F 	imes C$, lea sus elementos, imprima la matriz, calcule la suma total de sus valores y libere correctamente cada fila antes de liberar el puntero principal.

## Entrada
La primera línea contiene dos números enteros $F$ y $C$ (filas y columnas).
Las siguientes $F$ líneas contienen los elementos de la matriz ($C$ enteros por línea).

Límites:
- 1 <= F, C <= 100
- -10^6 <= Elemento <= 10^6

## Salida
Imprime las $F$ líneas con $C$ enteros separados por espacios y, en la última línea, `Suma total: SUMA`.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 2 3<br>1 2 3<br>4 5 6 | 1 2 3<br>4 5 6<br>Suma total: 21 |
| 1 1<br>42 | 42<br>Suma total: 42 |
