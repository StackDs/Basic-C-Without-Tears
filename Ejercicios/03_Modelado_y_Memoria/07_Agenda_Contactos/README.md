# Agenda de Contactos Dinámica

Gestionar registros de usuarios requiere estructuras dinámicas capaces de crecer a medida que se ingresan nuevos datos. Escribe un programa que utilice un arreglo dinámico de estructuras `struct Contacto` (con nombre y teléfono) para implementar una agenda que permita agregar contactos y buscar números de teléfono por nombre.

## Entrada
Una secuencia de instrucciones terminadas en el comando `FIN`:
- `AGREGAR <nombre> <telefono>`: Añade un contacto a la agenda.
- `BUSCAR <nombre>`: Consulta el teléfono del contacto.
- `FIN`: Concluye el programa.

Límites:
- Nombre y Teléfono: cadenas de hasta 50 caracteres sin espacios
- Hasta 1000 instrucciones

## Salida
Para cada instrucción `BUSCAR`, imprime:
- `Contacto: NOMBRE, Telefono: TEL` si existe.
- `Contacto no encontrado.` si no se encuentra registrado.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| AGREGAR Ana 555-1234<br>AGREGAR Carlos 555-5678<br>BUSCAR Ana<br>BUSCAR David<br>BUSCAR Carlos<br>FIN | Contacto: Ana, Telefono: 555-1234<br>Contacto no encontrado.<br>Contacto: Carlos, Telefono: 555-5678 |
