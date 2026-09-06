# Contador de Bits Encendidos

En ciencias de la computación, el cálculo del peso de Hamming (*population count* o popcount) consiste en contar cuántos bits están configurados en `1` dentro de una palabra binaria. Esta métrica es fundamental en criptografía, teoría de códigos correctores de errores y algoritmos de compresión.

Escribe un programa que reciba un número entero positivo y calcule la cantidad de bits en `1` que posee en su representación binaria.

## Entrada
La entrada consiste en un único número entero no negativo $N$.

Límites:
- 0 <= N <= 4000000000

## Salida
Imprime un único número entero que represente la cantidad de bits en `1` del valor ingresado.

## Ejemplos

| Entrada | Salida |
| :--- | :--- |
| 7 | 3 |
| 16 | 1 |
| 0 | 0 |
| 255 | 8 |
