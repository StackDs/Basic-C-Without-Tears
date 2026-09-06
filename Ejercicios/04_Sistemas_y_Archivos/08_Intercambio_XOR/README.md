# Intercambio Seguro sin Variable Temporal (XOR Swap)

El algoritmo de intercambio por XOR es un método clásico para intercambiar los valores de dos variables numéricas sin utilizar memoria o variables auxiliares temporales. Se fundamenta en dos propiedades de la compuerta XOR:
1. $x \oplus x = 0$ (cualquier valor contra sí mismo da cero).
2. $x \oplus 0 = x$ (el cero es el elemento neutro).

Al aplicar tres operaciones consecutivas:
```c
A = A ^ B;
B = A ^ B;
A = A ^ B;
```
los valores de $A$ y $B$ quedan perfectamente intercambiados.

Escribe un programa que lea dos números enteros, aplique el intercambio mediante XOR e imprima los valores resultantes.

## Entrada
La entrada consiste en dos números enteros $A$ y $B$ separados por un espacio.

Límites:
- -1000000000 <= A, B <= 1000000000

## Salida
Imprime los dos números con sus valores intercambiados, separados por un espacio.

## Ejemplos

| Entrada | Salida |
| :--- | :--- |
| 15 42 | 42 15 |
| -7 100 | 100 -7 |
| 0 0 | 0 0 |
