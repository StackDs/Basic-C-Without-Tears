# Verificador de Años Bisiestos

Para corregir el desfase entre el año trópico y el calendario civil, el calendario gregoriano establece años bisiestos con 366 días según tres reglas:
1. Un año es bisiesto si es divisible entre $4$.
2. Sin embargo, si es divisible entre $100$, no es bisiesto.
3. Como excepción a la regla anterior, si es divisible entre $400$, sí es bisiesto.

Escribe un programa que determine si un año determinado es bisiesto.

## Entrada
La entrada consiste en una única línea que contiene un número entero positivo $A$ correspondiente al año.

Límites: 1 <= A <= 10^5

## Salida
Imprime una única línea con el mensaje:
- `A es bisiesto.` si cumple las reglas de año bisiesto.
- `A no es bisiesto.` en caso contrario.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 2024 | 2024 es bisiesto. |
| 1900 | 1900 no es bisiesto. |
| 2000 | 2000 es bisiesto. |
| 2023 | 2023 no es bisiesto. |
