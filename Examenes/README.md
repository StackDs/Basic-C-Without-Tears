# Evaluaciones y Guías Prácticas: Basic C Without Tears

Bienvenido a la sección de **evaluaciones y guías prácticas formativas**. Este directorio contiene el material de práctica modular del curso, diseñado para que puedas poner en práctica tus conocimientos simulando una prueba.

## 📁 Organización del Directorio

- **`Examenes/`**: Contiene las versiones finales compiladas en formato **PDF**, listas para ser estudiadas, impresas o compartidas.
- **`Examenes/Tex/`**: Subdirectorio donde se almacenan y centralizan todos los archivos fuente originales en **LaTeX (`.tex`)**.

---

## 📔 Tipos de Cuestionarios

Las guías están divididas en dos grandes categorías según su alcance en el lenguaje:

### 1. Tipo A: Lógica de Programación en C

Abarca los fundamentos algorítmicos y el control de memoria estática en C (Módulos 01 al 06):

- **Temas clave**: Tipos primitivos y modificadores, memoria en el Stack vs variables en Python, entrada y salida formateada (`printf`, `scanf`, manejo de buffers), estructuras condicionales (`if-else`, `switch`), ciclos e iteraciones (`for`, `while`, `do-while`), modularidad con funciones, arreglos unidimensionales, matrices bidimensionales y manipulación rigurosa de cadenas de caracteres (Strings como arreglos de `char` delimitados por `\0`).

### 2. Tipo B: Conceptos Avanzados en C

Abarca el trabajo directo con hardware, bajo nivel y estructuras de datos dinámicas (Módulos 07, 08, 09 y 14):

- **Temas clave**: Modelado de datos con estructuras (`struct`), `union`, `typedef`, alineación y _padding_ de memoria; punteros (direccionamiento con `&`, desreferenciación con `*`, aritmética de punteros, punteros dobles y punteros a funciones); gestión explícita de memoria en el Heap (`malloc`, `calloc`, `realloc`, `free`, prevención de fugas de memoria y punteros colgantes); y operaciones a nivel de bits (`&`, `|`, `^`, `~`, desplazamientos `<<`, `>>`, bitmasking y banderas).
- _Nota:_ Este bloque omite intencionalmente cualquier pregunta sobre Makefiles o configuración del compilador.

---

## 📎 Modalidades de Cada Guía

Cada entrega cuenta con dos documentos complementarios:

| Modalidad              | Sufijo            | Descripción                                                                                                                                                                                                                                                             |
| :--------------------- | :---------------- | :---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Versión Estudiante** | `*_Preguntas.pdf` | Contiene únicamente los enunciados de los 4 problemas principales con sus subapartados progresivos $(a, b, c)$, tablas de prueba (Entrada/Salida). Ideal para resolver sin ayuda previa.                                                                               |
| **Versión Pauta**      | `*_Pauta.pdf`     | Contiene los enunciados junto a sus respectivas **cajas de solución**, explicaciones paso a paso, análisis de trampas comunes de memoria y código C de referencia completamente funcional, aunque de igual forma está correcto escribir con pseudocódigo tus respuestas. |

---

## 📘 Documentos Especiales de Referencia

* **[Guía de Referencia: Pseudocódigo en C](./Pseudocodigo.pdf)** ([Fuente LaTeX](./Tex/Pseudocodigo.tex)): Documento explicativo de 4 páginas que detalla qué es el pseudocódigo, cuándo utilizarlo, tablas de equivalencia sintáctica con C y comparativas prácticas entre código compilable y pseudocódigo riguroso (condicionales, arreglos y cadenas con `\0`).

---

## 📚 Material de Práctica Disponible

### Guías Tipo A (Fundamentos y Lógica)
* **Guía 01 - Preguntas**: [`Guia_01_Tipo_A_Preguntas.pdf`](./Guia_01_Tipo_A_Preguntas.pdf) ([Fuente LaTeX](./Tex/Guia_01_Tipo_A_Preguntas.tex))
* **Guía 01 - Pauta con Soluciones**: [`Guia_01_Tipo_A_Pauta.pdf`](./Guia_01_Tipo_A_Pauta.pdf) ([Fuente LaTeX](./Tex/Guia_01_Tipo_A_Pauta.tex))

### Guías Tipo B (Conceptos Avanzados)
* **Guía 01 - Preguntas**: [`Guia_01_Tipo_B_Preguntas.pdf`](./Guia_01_Tipo_B_Preguntas.pdf) ([Fuente LaTeX](./Tex/Guia_01_Tipo_B_Preguntas.tex))
* **Guía 01 - Pauta con Soluciones**: [`Guia_01_Tipo_B_Pauta.pdf`](./Guia_01_Tipo_B_Pauta.pdf) ([Fuente LaTeX](./Tex/Guia_01_Tipo_B_Pauta.tex))

---

## 🛠️ Compilación de Archivos LaTeX

Para compilar cualquiera de los archivos `.tex` hacia el directorio de tu elección utilizando `tectonic`:

```bash
tectonic --outdir <directorio_salida> Examenes/Tex/<archivo>.tex
```
Por ejemplo, para compilar directamente en la carpeta `Examenes/`:

```bash
tectonic --outdir Examenes Examenes/Tex/Guia_01_Tipo_B_Pauta.tex
```
