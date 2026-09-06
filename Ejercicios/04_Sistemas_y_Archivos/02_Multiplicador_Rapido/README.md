# Multiplicador Rápido por Potencias de Dos

En la arquitectura de computadores, desplazar los bits de un entero hacia la izquierda (`<<`) equivale a multiplicar dicho número por potencias de 2 ($N 	imes 2^K$). De manera análoga, desplazar los bits hacia la derecha (`>>`) equivale a realizar una división entera entre $2^K$. Estas instrucciones a nivel de ensamblador son ejecutadas en un solo ciclo de reloj, resultando sumamente eficientes.

Escribe un programa que lea un número entero no negativo $N$ y un exponente $K$, y calcule la multiplicación $N 	imes 2^K$ y la división entera $N / 2^K$ utilizando únicamente los operadores de desplazamiento de bits.

## Entrada
La entrada consiste en una única línea con dos números enteros no negativos separados por un espacio: el valor base $N$ y la potencia $K$.

Límites:
- 0 <= N <= 1000000
- 0 <= K <= 20

## Salida
Imprime en una única línea dos números enteros separados por un espacio: el resultado de la multiplicación y el resultado de la división entera.

## Ejemplos

| Entrada | Salida |
| :--- | :--- |
| 10 3 | 80 1 |
| 24 2 | 96 6 |
| 5 0 | 5 5 |
