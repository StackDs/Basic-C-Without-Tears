# Verificador de Cuadrado Mágico

Un cuadrado mágico es una matriz cuadrada donde la suma de los valores en cada una de sus filas, columnas y en ambas diagonales principales produce exactamente el mismo resultado, denominado constante mágica. Escribe un programa que lea una matriz cuadrada de $3 	imes 3$ números enteros y determine si corresponde a un cuadrado mágico.

## Entrada
La entrada consta de 3 líneas, cada una con 3 números enteros separados por espacios, que componen la matriz de $3 	imes 3$.

Límites:
- -1000 <= Elemento <= 1000

## Salida
Imprime una única línea con el mensaje:
- `Es un cuadrado magico (Suma = S).` si todas las sumas coinciden en el valor `S`.
- `No es un cuadrado magico.` en caso contrario.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 8 1 6<br>3 5 7<br>4 9 2 | Es un cuadrado magico (Suma = 15). |
| 1 2 3<br>4 5 6<br>7 8 9 | No es un cuadrado magico. |
| 2 7 6<br>9 5 1<br>4 3 8 | Es un cuadrado magico (Suma = 15). |
