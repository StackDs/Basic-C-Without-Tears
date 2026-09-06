# Desempaquetado de Colores RGB

El desempaquetado es el proceso inverso al empaquetado de colores: dado un entero de 32 bits que representa un color compuesto, se extraen individualmente los canales Rojo, Verde y Azul aplicando desplazamientos a la derecha y máscaras con el valor `0xFF` (`255` en decimal).

Escribe un programa que reciba un entero que contenga un color empaquetado y extraiga los 3 canales por separado.

## Entrada
La entrada consiste en un número entero sin signo (en notación decimal o hexadecimal con prefijo `0x`).

Límites:
- 0 <= Color <= 16777215 (0xFFFFFF)

## Salida
Imprime tres números enteros separados por un espacio, correspondientes a los componentes $R$, $G$ y $B$ en ese orden.

## Ejemplos

| Entrada | Salida |
| :--- | :--- |
| 16711808 | 255 0 128 |
| 0x123456 | 18 52 86 |
| 0 | 0 0 0 |
