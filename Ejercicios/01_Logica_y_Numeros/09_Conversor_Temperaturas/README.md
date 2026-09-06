# Conversor de Temperaturas

Las conversiones entre escalas termométricas son necesarias en aplicaciones científicas y de ingeniería. Las tres escalas más empleadas son Celsius ($C$), Fahrenheit ($F$) y Kelvin ($K$). Sus fórmulas de conversión directa son:
- De Celsius a Fahrenheit: $F = C \times \frac{9}{5} + 32$
- De Fahrenheit a Celsius: $C = (F - 32) \times \frac{5}{9}$
- De Celsius a Kelvin: $K = C + 273.15$
- De Kelvin a Celsius: $C = K - 273.15$

Escribe un programa que lea un valor de temperatura, su unidad de origen y la unidad de destino deseada, e imprima el valor equivalente.

## Entrada
La entrada consiste en una única línea que contiene un número decimal $T$ seguido de dos caracteres $U_{origen}$ y $U_{destino}$ separados por espacios. Las unidades válidas son `C`, `F` y `K`.

Límites:
- -10^4 <= T <= 10^4
- U_origen, U_destino en {'C', 'F', 'K'}

## Salida
Imprime una única línea con el valor de la temperatura convertida formateado a dos lugares decimales. Si alguna de las unidades ingresadas no es válida, imprime `Error: Unidad no valida.`.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 100.0 C F | 212.00 |
| 0.0 C K | 273.15 |
| 32.0 F C | 0.00 |
| 300.0 K C | 26.85 |
| 25.0 C X | Error: Unidad no valida. |
