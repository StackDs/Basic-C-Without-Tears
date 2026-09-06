# Extractor de Bits

Trabajar con registros de control de hardware o banderas de estado requiere inspeccionar bits individuales en posiciones específicas. Para saber si el bit en la posición $P$ está encendido (`1`) o apagado (`0`), podemos desplazar dicho bit hacia la posición menos significativa o aplicar una máscara `(1 << P)`.

Escribe un programa que reciba un número entero no negativo $N$ y una posición $P$ (donde $P = 0$ es el bit menos significativo), e imprima el valor del bit en esa posición.

## Entrada
La entrada contiene dos números enteros separados por un espacio: el número $N$ y la posición $P$.

Límites:
- 0 <= N <= 4000000000
- 0 <= P <= 31

## Salida
Imprime un único dígito (`0` o `1`), correspondiente al bit en la posición $P$.

## Ejemplos

| Entrada | Salida |
| :--- | :--- |
| 8 3 | 1 |
| 8 2 | 0 |
| 25 0 | 1 |
