# Cifrado César

El cifrado César es uno de los métodos criptográficos clásicos por sustitución más antiguos. Consiste en reemplazar cada letra de un mensaje por la letra que se encuentra $K$ posiciones adelante en el alfabeto, volviendo al inicio al sobrepasar la 'Z' o 'z' (aritmética modular sobre 26 letras). Las letras mayúsculas y minúsculas conservan su estado original, y los caracteres no alfabéticos (dígitos, espacios y signos) no se modifican. Escribe un programa que reciba el desplazamiento $K$ y una línea de texto, y produzca el mensaje cifrado.

## Entrada
La primera línea contiene un número entero no negativo $K$ que representa el desplazamiento.
La segunda línea contiene la cadena de texto a cifrar.

Límites:
- 0 <= K <= 1000
- 1 <= Longitud de la cadena <= 1000

## Salida
Imprime una única línea con el texto cifrado resultante.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 3<br>Hola Mundo! | Krod Pxqgr! |
| 1<br>xyz ABC 123 | yza BCD 123 |
| 26<br>Texto Sin Cambio | Texto Sin Cambio |
