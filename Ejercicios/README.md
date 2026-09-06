# Banco de Ejercicios Prácticos: C Without Tears

Bienvenido al banco de ejercicios prácticos de **Basic-C-Without-Tears**. Esta sección está diseñada para que puedes poner en todo lo que se vió en los modulos, hay 80 problemas de diferentes tipos, desde la lógica algorítmica fundamental hasta la programación de sistemas y la persistencia en disco.

Cada ejercicio se encuentra organizado en su propia carpeta e incluye:
- **`README.md`**: Enunciado del problema en lenguaje natural, especificación formal de la entrada y sus límites numéricos, formato de salida esperado y tabla de ejemplos de prueba.
- **Código fuente en C (`.c`)**: Solución de referencia implementada en C estándar (`C11`), modular, limpia y completamente comentada paso a paso para guiarte en el razonamiento algorítmico y las buenas prácticas de bajo nivel.

---

## 📚 Módulos de Ejercicios

A continuación encontrarás la descripción de cada uno de los cuatro módulos temáticos que componen el banco de ejercicios:

### 1. [Módulo 1: Lógica y Números](./01_Logica_y_Numeros) (20 Ejercicios)
Este módulo se centra en afianzar las bases del pensamiento algorítmico en C. Trabajarás con control de flujo, condicionales (`if`/`else`), bucles (`for`, `while`, `do-while`), funciones modulares y aritmética fundamental.

- **Temas clave**: Aritmética modular, cálculo de factoriales y potencias, validación de números primos, sucesión de Fibonacci, números perfectos y narcisistas, algoritmos clásicos como Euclides (MCD/MCM), simulación de relojes e inversión de dígitos.

### 2. [Módulo 2: Arreglos y Textos](./02_Arreglos_y_Textos) (20 Ejercicios)
En este módulo explorarás la gestión estática de memoria mediante vectores y matrices multidimensionales, así como el tratamiento de cadenas de texto como arreglos de caracteres terminados en el caracter nulo (`\0`).

- **Temas clave**: Búsqueda lineal y extremos (mínimo/máximo), estadísticas y ordenamiento (Bubble Sort), operaciones matriciales (suma, transpuesta y multiplicación), conteo y transformación manual de cadenas ASCII, detectores de palíndromos y anagramas, filtros de espacios y cifrado por sustitución (Cifrado César).

### 3. [Módulo 3: Modelado y Memoria](./03_Modelado_y_Memoria) (20 Ejercicios)
Aquí darás el salto hacia la gestión explícita de memoria en el Heap y el modelado de datos personalizado utilizando estructuras (`struct`), punteros y abstracciones dinámicas.

- **Temas clave**: Definición de `struct` y estructuras anidadas, asignación y redimensionamiento dinámico con `malloc`, `realloc` y `free`, clonación profunda de memoria, punteros a funciones, y construcción desde cero de estructuras de datos fundamentales como listas simplemente enlazadas, pilas (LIFO) y colas (FIFO).

### 4. [Módulo 4: Sistemas y Archivos](./04_Sistemas_y_Archivos) (20 Ejercicios)
El último módulo profundiza en la programación de bajo nivel interactuando con bits y con el sistema de archivos del sistema operativo, tanto en formato de texto como en formato binario.

- **Temas clave**: Operadores lógicos y máscaras a nivel de bits (`&`, `|`, `^`, `~`, `<<`, `>>`), empaquetado y desempaquetado de datos (canales RGB), manipulación de flujos con `FILE *`, modos de apertura (`"r"`, `"w"`, `"rb"`, `"wb"`, `"a"`), acceso aleatorio con `fseek`, utilidades tipo `wc` y `hexdump`, y desarrollo de una base de datos CRUD con borrado lógico persistida en disco.

---

## 🛠️ Cómo Compilar y Ejecutar

Para compilar cualquiera de los ejercicios utilizando el compilador GCC con advertencias estrictas y estándar C11:

```bash
# Ejemplo: Compilar el ejercicio de suma de números
gcc -Wall -Wextra -Werror -std=c11 Ejercicios/01_Logica_y_Numeros/01_Suma_N_Numeros/suma_n.c -o suma_n

# Si el ejercicio utiliza funciones de <math.h> (como sqrt o hypot), agrega la bandera -lm:
gcc -Wall -Wextra -Werror -std=c11 Ejercicios/03_Modelado_y_Memoria/01_Distancia_Puntos/distancia_puntos.c -lm -o distancia

# Ejecutar el binario generado
./suma_n
```
