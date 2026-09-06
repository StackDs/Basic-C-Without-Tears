# Carrito de Compras Dinámico

Un carrito de compras en un sistema de comercio electrónico comienza vacío y expande su capacidad en memoria a medida que el cliente agrega productos. Escribe un programa que modele un carrito con capacidad inicial de 2 productos y la duplique con `realloc` cada vez que se llene, calculando al final el subtotal por producto y el total a pagar.

## Entrada
La primera línea contiene un número entero positivo $N$ (cantidad de productos).
Las siguientes $N$ líneas contienen `Nombre Precio Cantidad` (donde `Nombre` es una palabra, `Precio` es un número decimal y `Cantidad` es un entero).

Límites:
- 1 <= N <= 100
- Precio > 0.0, Cantidad >= 1

## Salida
$N$ líneas con el formato `[i] NOMBRE x CANTIDAD = $SUBTOTAL` (a dos decimales), seguidas de la línea `Total a pagar: $TOTAL`.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 3<br>Manzana 1.50 4<br>Leche 2.20 2<br>Pan 0.80 5 | [1] Manzana x 4 = $6.00<br>[2] Leche x 2 = $4.40<br>[3] Pan x 5 = $4.00<br>Total a pagar: $14.40 |
