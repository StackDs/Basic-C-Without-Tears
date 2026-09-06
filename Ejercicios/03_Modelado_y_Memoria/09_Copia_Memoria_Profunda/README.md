# Copia Profunda de Memoria (Deep Copy)

Una copia superficial (*shallow copy*) solo duplica los punteros, provocando que dos variables compartan y modifiquen la misma memoria. Una copia profunda (*deep copy*) reserva un nuevo bloque independiente y copia los datos elemento a elemento. Escribe un programa que cree un arreglo dinámico de estructuras `struct Persona`, genere una copia profunda en un segundo bloque dinámico, modifique un registro en la copia y demuestre que el arreglo original no resulta afectado.

## Entrada
La primera línea contiene un número entero $N$ (cantidad de personas).
Las siguientes $N$ líneas contienen `Nombre Edad`.
La siguiente línea contiene el índice $I$ (0-indexed) a modificar en la copia, seguido del nuevo `Nombre Edad`.

Límites:
- 1 <= N <= 100
- 0 <= I < N

## Salida
El listado del arreglo `Original:` seguido de los $N$ registros `[i] Nombre, Edad`.
El listado de la `Copia:` con la modificación aplicada.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 2<br>Juan 25<br>Maria 30<br>0 Pedro 28 | Original:<br>[0] Juan, 25<br>[1] Maria, 30<br>Copia:<br>[0] Pedro, 28<br>[1] Maria, 30 |
