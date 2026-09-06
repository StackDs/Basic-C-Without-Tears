# Eliminación de Nodos en Lista Enlazada

Eliminar un nodo intermedio o inicial en una lista enlazada requiere actualizar los enlaces de los nodos adyacentes para no romper la continuidad de la estructura y liberar la memoria del nodo eliminado con `free`. Escribe un programa que cree una lista con $N$ elementos, busque la primera aparición de un valor $X$, lo elimine reconectando los punteros y muestre el estado final de la lista.

## Entrada
La primera línea contiene un número entero positivo $N$.
La segunda línea contiene $N$ números enteros (elementos de la lista).
La tercera línea contiene un número entero $X$ (valor a eliminar).

Límites:
- 1 <= N <= 1000
- -10^9 <= X, Elemento <= 10^9

## Salida
Primera línea: `Eliminado: X` o `No encontrado: X`.
Segunda línea: `Lista: elem1 -> elem2 -> ... -> NULL` (o `Lista: NULL` si la lista quedó vacía).

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 4<br>10 20 30 40<br>20 | Eliminado: 20<br>Lista: 10 -> 30 -> 40 -> NULL |
| 3<br>1 2 3<br>5 | No encontrado: 5<br>Lista: 1 -> 2 -> 3 -> NULL |
| 1<br>50<br>50 | Eliminado: 50<br>Lista: NULL |
