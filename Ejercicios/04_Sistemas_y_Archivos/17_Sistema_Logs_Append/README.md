# Sistema de Logs con Modo Anexar (Append)

Al construir bitácoras o sistemas de auditoría (*logging*), el modo de apertura `"a"` (*append*) es esencial. A diferencia de `"w"` que sobrescribe y trunca el archivo a 0 bytes al abrirse, el modo `"a"` posiciona automáticamente el cursor de escritura al final del archivo existente, preservando todas las entradas anteriores y agregando las nuevas.

Escribe un programa que reciba un nombre de archivo de log y una serie de mensajes, y los anexe al final del archivo.

## Entrada
- La primera línea contiene el nombre del archivo de log y un número entero $N$ (cantidad de mensajes a registrar).
- Las siguientes $N$ líneas contienen un mensaje de texto por línea.

Límites:
- 1 <= N <= 50
- Longitud de cada mensaje <= 100 caracteres

## Salida
Imprime `Se anexaron N mensajes al archivo nombre_archivo.`

## Ejemplos

| Entrada | Salida |
| :--- | :--- |
| historial.log 2<br>Inicio de sesion de usuario<br>Conexion a base de datos establecida | Se anexaron 2 mensajes al archivo historial.log. |
