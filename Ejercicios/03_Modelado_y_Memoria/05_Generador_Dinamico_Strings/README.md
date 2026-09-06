# Generador Dinámico de Cadenas

Construir cadenas de texto cuya longitud se determina en tiempo de ejecución es una práctica común para evitar desbordamientos de buffer. Escribe una función que reciba dos cadenas de caracteres, calcule la longitud requerida, reserve con `malloc` el espacio exacto para ambas (incluyendo el terminador `\0`), las concatene y devuelva el puntero resultante. El programa principal debe imprimir la nueva cadena y liberar la memoria con `free`.

## Entrada
La primera línea contiene la primera cadena de texto $S_1$.
La segunda línea contiene la segunda cadena de texto $S_2$.

Límites:
- 1 <= Longitud de cada cadena <= 500

## Salida
Imprime una única línea con la cadena resultante de la concatenación dinámica.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| Hola <br>Mundo | Hola Mundo |
| Memoria <br>Dinamica | Memoria Dinamica |
| Puntero<br>C | PunteroC |
