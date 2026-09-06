# Calculadora de Factoriales

El factorial de un número entero no negativo $N$, denotado como $N!$, representa el producto de todos los números enteros positivos menores o iguales a $N$. Por definición matemática, $0! = 1$. La operación no se encuentra definida para valores negativos. Escribe un programa que lea un número entero $N$ y calcule su factorial, validando que el valor no sea negativo.

## Entrada
La entrada consiste en una única línea que contiene un número entero $N$.

Límites: -100 <= N <= 20

## Salida
Si $N \ge 0$, imprime un único número entero correspondiente a $N!$. Si $N < 0$, imprime el mensaje `El factorial no esta definido para numeros negativos.`.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 5 | 120 |
| 0 | 1 |
| 1 | 1 |
| 6 | 720 |
| -4 | El factorial no esta definido para numeros negativos. |
