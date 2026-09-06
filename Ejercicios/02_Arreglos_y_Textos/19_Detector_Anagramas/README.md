# Detector de Anagramas

Dos palabras son anagramas si contienen exactamente las mismas letras con las mismas frecuencias de aparición, variando únicamente el orden entre ellas (por ejemplo, "roma" y "amor", o "frase" y "fresa"). Escribe un programa que reciba dos palabras e indique si son anagramas, ignorando diferencias entre mayúsculas y minúsculas.

## Entrada
Una única línea con dos palabras separadas por un espacio (o dos palabras en líneas consecutivas).

Límites:
- 1 <= Longitud de cada palabra <= 100

## Salida
Imprime una única línea con el mensaje:
- `Son anagramas.` si las palabras están compuestas por las mismas letras.
- `No son anagramas.` en caso contrario.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| roma amor | Son anagramas. |
| frase fresa | Son anagramas. |
| hola bola | No son anagramas. |
| Listen Silent | Son anagramas. |
