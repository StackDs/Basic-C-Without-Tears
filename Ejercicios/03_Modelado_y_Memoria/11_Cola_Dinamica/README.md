# Implementación de Cola Dinámica (Queue)

Una Cola es una estructura de datos lineal que sigue el principio FIFO (*First In, First Out*), donde el primer elemento ingresado es el primero en ser atendido y extraído. Escribe un programa que modele una cola dinámica mediante nodos enlazados con punteros al frente y al final, soportando las operaciones `ENQUEUE`, `DEQUEUE` y `FRENTE`.

## Entrada
Secuencia de comandos terminados en `FIN`:
- `ENQUEUE <valor>`: Inserta un entero al final de la cola.
- `DEQUEUE`: Retira el elemento al frente de la cola y muestra su valor.
- `FRENTE`: Muestra el elemento al frente sin retirarlo.
- `FIN`: Finaliza la ejecución.

Límites:
- -10^9 <= Valor <= 10^9

## Salida
- Para `DEQUEUE`: `Dequeue: VAL` o `Error: Cola vacia.`.
- Para `FRENTE`: `Frente: VAL` o `Error: Cola vacia.`.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| ENQUEUE 100<br>ENQUEUE 200<br>FRENTE<br>DEQUEUE<br>FRENTE<br>DEQUEUE<br>DEQUEUE<br>FIN | Frente: 100<br>Dequeue: 100<br>Frente: 200<br>Dequeue: 200<br>Error: Cola vacia. |
