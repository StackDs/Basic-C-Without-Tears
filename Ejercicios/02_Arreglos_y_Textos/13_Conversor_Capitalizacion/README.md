# Conversor de Capitalización Manual (ASCII)

En la tabla ASCII, cada letra mayúscula ('A' a 'Z') dista exactamente $32$ posiciones numéricas de su respectiva letra minúscula ('a' a 'z'). Manipular directamente estas diferencias aritméticas permite entender el funcionamiento interno de las funciones de conversión de texto. Escribe un programa que reciba una opción (`M` para convertir a mayúsculas o `m` para convertir a minúsculas) y una cadena de texto, realizando la transformación sin utilizar la librería `<ctype.h>`.

## Entrada
La primera línea contiene un carácter que indica el modo: `M` (mayúsculas) o `m` (minúsculas).
La segunda línea contiene la cadena de texto a transformar.

Límites:
- Opción en {'M', 'm'}
- 1 <= Longitud de la cadena <= 1000

## Salida
Imprime una única línea con la cadena transformada. Los caracteres que no sean letras deben permanecer inalterados.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| M<br>hola mundo | HOLA MUNDO |
| m<br>BASIC C PROGRAMMING | basic c programming |
| M<br>C_123! | C_123! |
