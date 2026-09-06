# Matriz Transpuesta

La transpuesta de una matriz $A$ de dimensiones $F 	imes C$ es una nueva matriz $A^T$ de dimensiones $C 	imes F$ obtenida al transformar cada fila en su respectiva columna, de modo que el elemento en la posición $(j, i)$ de $A^T$ equivale al elemento $(i, j)$ de $A$. Escribe un programa que lea una matriz $A$ y genere su matriz transpuesta.

## Entrada
La primera línea contiene dos números enteros $F$ y $C$ que indican las filas y columnas.
Las siguientes $F$ líneas contienen los elementos de la matriz ($C$ enteros por línea).

Límites:
- 1 <= F, C <= 50
- -10^6 <= Elemento <= 10^6

## Salida
Imprime $C$ líneas con $F$ números enteros separados por espacios que representen la matriz transpuesta.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 2 3<br>1 2 3<br>4 5 6 | 1 4<br>2 5<br>3 6 |
| 2 2<br>1 0<br>0 1 | 1 0<br>0 1 |
