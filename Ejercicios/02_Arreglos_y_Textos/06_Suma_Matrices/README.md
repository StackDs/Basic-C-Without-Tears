# Suma de Matrices 2D

En álgebra lineal, la suma de dos matrices de iguales dimensiones $F 	imes C$ se define sumando los elementos correspondientes que ocupan la misma fila y columna: $S[i][j] = A[i][j] + B[i][j]$. Escribe un programa que reciba las dimensiones $F$ y $C$, lea las matrices bidimensionales $A$ y $B$, y calcule la matriz resultante $S$.

## Entrada
La primera línea contiene dos números enteros $F$ y $C$ que indican las filas y columnas.
Las siguientes $F$ líneas contienen los elementos de la matriz $A$ ($C$ enteros por línea).
Las siguientes $F$ líneas contienen los elementos de la matriz $B$ ($C$ enteros por línea).

Límites:
- 1 <= F, C <= 50
- -1000 <= Elemento <= 1000

## Salida
Imprime $F$ líneas con $C$ números enteros separados por espacios que representen la matriz suma $S$.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 2 2<br>1 2<br>3 4<br>5 6<br>7 8 | 6 8<br>10 12 |
| 2 3<br>1 0 2<br>-1 3 4<br>2 1 1<br>4 -2 0 | 3 1 3<br>3 1 4 |
