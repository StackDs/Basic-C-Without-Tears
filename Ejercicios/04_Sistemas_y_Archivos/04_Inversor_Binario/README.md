# Inversor Binario (Operador NOT)

El operador unario NOT (`~`) realiza una inversión bit a bit (complemento a uno) sobre los bits de su operando, convirtiendo cada `0` en `1` y cada `1` en `0`. En un entero sin signo de 32 bits (`unsigned int`), invertir un valor como `0` producirá `4294967295` (es decir, $2^{32} - 1$).

Escribe un programa que lea un número entero sin signo de 32 bits y muestre el valor decimal resultante tras invertir todos sus bits con el operador `~`.

## Entrada
La entrada consiste en un número entero sin signo $N$.

Límites:
- 0 <= N <= 4294967295

## Salida
Imprime el valor decimal del entero sin signo resultante de aplicar el operador `~`.

## Ejemplos

| Entrada | Salida |
| :--- | :--- |
| 0 | 4294967295 |
| 4294967295 | 0 |
| 1 | 4294967294 |
| 255 | 4294967040 |
