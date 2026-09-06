# Multiplicación de Matrices

La multiplicación de matrices $A \times B$ es válida únicamente si el número de columnas de la primera matriz ($C_1$) es igual al número de filas de la segunda matriz ($F_2$). Cuando son compatibles, el producto genera una matriz de tamaño $F_1 \times C_2$, donde cada elemento $(i, j)$ se calcula como la sumatoria del producto de los elementos correspondientes de la fila $i$ de $A$ y la columna $j$ de $B$. Escribe un programa que lea dos matrices, verifique si son compatibles para el producto matricial y calcule la matriz resultante.

## Entrada
La primera línea contiene dos enteros $F_1$ y $C_1$ (dimensiones de la matriz $A$).
Las siguientes $F_1$ líneas contienen los elementos de la matriz $A$ ($C_1$ enteros por línea).
La siguiente línea contiene dos enteros $F_2$ y $C_2$ (dimensiones de la matriz $B$).
Las siguientes $F_2$ líneas contienen los elementos de la matriz $B$ ($C_2$ enteros por línea).

Límites:
- 1 <= F_1, C_1, F_2, C_2 <= 50
- -1000 <= Elemento <= 1000

## Salida
Si $C_1 \ne F_2$, imprime el mensaje `Error: Matrices incompatibles para multiplicacion.`.
Si son compatibles, imprime $F_1$ líneas con $C_2$ enteros separados por espacios que conformen la matriz producto.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 2 3<br>1 2 3<br>4 5 6<br>3 2<br>7 8<br>9 1<br>2 3 | 31 19<br>85 55 |
| 2 2<br>1 2<br>3 4<br>3 2<br>1 1<br>1 1<br>1 1 | Error: Matrices incompatibles para multiplicacion. |
