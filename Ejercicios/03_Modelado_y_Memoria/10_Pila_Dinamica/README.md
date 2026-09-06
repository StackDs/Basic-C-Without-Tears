# Implementación de Pila Dinámica (Stack)

Una Pila es una estructura de datos lineal que opera bajo el principio LIFO (*Last In, First Out*), donde el último elemento insertado es el primero en retirarse. Escribe un programa que modele una pila dinámica mediante nodos enlazados en memoria dinámica, soportando las operaciones `PUSH`, `POP` y `TOP`.

## Entrada
Secuencia de comandos terminados en `FIN`:
- `PUSH <valor>`: Inserta un entero en el tope de la pila.
- `POP`: Retira el elemento en el tope y muestra su valor.
- `TOP`: Muestra el elemento en el tope sin retirarlo.
- `FIN`: Finaliza la ejecución.

Límites:
- -10^9 <= Valor <= 10^9

## Salida
- Para `POP`: `Pop: VAL` o `Error: Pila vacia.`.
- Para `TOP`: `Top: VAL` o `Error: Pila vacia.`.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| PUSH 10<br>PUSH 20<br>TOP<br>POP<br>TOP<br>POP<br>POP<br>FIN | Top: 20<br>Pop: 20<br>Top: 10<br>Pop: 10<br>Error: Pila vacia. |
