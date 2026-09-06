# Pirámide de Asteriscos

La construcción de figuras geométricas en la terminal mediante bucles anidados ayuda a desarrollar el razonamiento espacial y el control de índices. Escribe un programa que reciba un número entero positivo $N$ y dibuje una pirámide simétrica de asteriscos (`*`) con altura $N$. Cada fila $i$ (desde $1$ hasta $N$) debe contener $N - i$ espacios en blanco a la izquierda seguidos de $2i - 1$ asteriscos.

## Entrada
La entrada consiste en una única línea que contiene un número entero positivo $N$.

Límites: 1 <= N <= 50

## Salida
Imprime $N$ líneas correspondientes a los niveles de la pirámide simétrica.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 3 | &nbsp;&nbsp;*<br>&nbsp;***<br>***** |
| 1 | * |
| 4 | &nbsp;&nbsp;&nbsp;*<br>&nbsp;&nbsp;***<br>&nbsp;*****<br>******* |
