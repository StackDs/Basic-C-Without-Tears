# Empaquetado de Colores RGB

En motores gráficos y procesamiento de imágenes, es común compactar los tres componentes de color — Rojo (R), Verde (G) y Azul (B) — de 8 bits cada uno (rango 0 a 255) dentro de un único entero de 32 bits. Esto se logra desplazando el canal Rojo 16 posiciones a la izquierda, el canal Verde 8 posiciones y combinándolos con el canal Azul mediante el operador OR (`|`).

Escribe un programa que reciba tres valores correspondientes a $R$, $G$ y $B$, y los empaquete en un único número entero de 32 bits, mostrando el resultado tanto en formato hexadecimal como en decimal.

## Entrada
La entrada consiste en tres números enteros separados por espacios que representan los valores $R$, $G$ y $B$.

Límites:
- 0 <= R, G, B <= 255

## Salida
Imprime el valor empaquetado en formato hexadecimal con prefijo `0x` en mayúsculas (6 dígitos formateados con ceros a la izquierda) seguido de su valor decimal entre paréntesis.

## Ejemplos

| Entrada | Salida |
| :--- | :--- |
| 255 0 128 | 0xFF0080 (16711808) |
| 0 0 0 | 0x000000 (0) |
| 18 52 86 | 0x123456 (1193046) |
