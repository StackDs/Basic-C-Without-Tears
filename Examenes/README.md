# Evaluaciones y Guías Prácticas: Basic C Without Tears

Este directorio organiza el material de práctica por tipo de contenido y variante. Cada guía ofrece una versión de preguntas y otra con pauta de soluciones.

## Organización

- `Fundamentos/A/` y `Fundamentos/B/`: evaluaciones Tipo A, de lógica y fundamentos de C, separadas por variante.
- `Estructuras_y_Punteros/A/` y `Estructuras_y_Punteros/B/`: evaluaciones Tipo B, sobre estructuras, punteros, memoria dinámica y bits, separadas por variante.
- `Pseudocodigo/`: documento de referencia en PDF.
- `Tex/`: fuentes LaTeX organizadas con la misma jerarquía. `Tex/Plantillas/` contiene las plantillas compartidas.

## Temario

### Tipo A — Fundamentos

Tipos primitivos, entrada y salida, condicionales, ciclos, funciones, arreglos, matrices y cadenas de caracteres.

### Tipo B — Estructuras y Punteros

Estructuras, uniones, alineación, punteros, memoria dinámica y operaciones a nivel de bits. Este bloque omite Makefiles y configuración del compilador.

## Documentos de referencia

- [Guía de pseudocódigo en C (PDF)](./Pseudocodigo/Pseudocodigo.pdf) ([fuente LaTeX](./Tex/Pseudocodigo/Pseudocodigo.tex)).

## Material Tipo A — Fundamentos

### Variante A

| Material | Preguntas | Pauta |
| :--- | :--- | :--- |
| Guía 01 | [PDF](./Fundamentos/Guia_01_Tipo_A_Preguntas.pdf) · [LaTeX](./Tex/Fundamentos/A/Guia_01_Tipo_A_Preguntas.tex) | [PDF](./Fundamentos/Guia_01_Tipo_A_Pauta.pdf) · [LaTeX](./Tex/Fundamentos/A/Guia_01_Tipo_A_Pauta.tex) |
| Guía 02 | [PDF](./Fundamentos/Guia_02_Tipo_A_Preguntas.pdf) · [LaTeX](./Tex/Fundamentos/A/Guia_02_Tipo_A_Preguntas.tex) | [PDF](./Fundamentos/Guia_02_Tipo_A_Pauta.pdf) · [LaTeX](./Tex/Fundamentos/A/Guia_02_Tipo_A_Pauta.tex) |
| Guía 03 | [PDF](./Fundamentos/Guia_03_Tipo_A_Preguntas.pdf) · [LaTeX](./Tex/Fundamentos/A/Guia_03_Tipo_A_Preguntas.tex) | [PDF](./Fundamentos/Guia_03_Tipo_A_Pauta.pdf) · [LaTeX](./Tex/Fundamentos/A/Guia_03_Tipo_A_Pauta.tex) |
| Examen 02 | [PDF](./Fundamentos/A/Examen_02_A_Preguntas.pdf) · [LaTeX](./Tex/Fundamentos/A/Examen_02_A_Preguntas.tex) | [PDF](./Fundamentos/A/Examen_02_A_Pauta.pdf) · [LaTeX](./Tex/Fundamentos/A/Examen_02_A_Pauta.tex) |
| Examen 03 | [PDF](./Fundamentos/A/Examen_03_A_Preguntas.pdf) · [LaTeX](./Tex/Fundamentos/A/Examen_03_A_Preguntas.tex) | [PDF](./Fundamentos/A/Examen_03_A_Pauta.pdf) · [LaTeX](./Tex/Fundamentos/A/Examen_03_A_Pauta.tex) |
| Examen 04 | [PDF](./Fundamentos/A/Examen_04_A_Preguntas.pdf) · [LaTeX](./Tex/Fundamentos/A/Examen_04_A_Preguntas.tex) | [PDF](./Fundamentos/A/Examen_04_A_Pauta.pdf) · [LaTeX](./Tex/Fundamentos/A/Examen_04_A_Pauta.tex) |

### Variante B

| Material | Preguntas | Pauta |
| :--- | :--- | :--- |
| Examen 02 | [PDF](./Fundamentos/B/Examen_02_B_Preguntas.pdf) · [LaTeX](./Tex/Fundamentos/B/Examen_02_B_Preguntas.tex) | [PDF](./Fundamentos/B/Examen_02_B_Pauta.pdf) · [LaTeX](./Tex/Fundamentos/B/Examen_02_B_Pauta.tex) |
| Examen 03 | [PDF](./Fundamentos/B/Examen_03_B_Preguntas.pdf) · [LaTeX](./Tex/Fundamentos/B/Examen_03_B_Preguntas.tex) | [PDF](./Fundamentos/B/Examen_03_B_Pauta.pdf) · [LaTeX](./Tex/Fundamentos/B/Examen_03_B_Pauta.tex) |
| Examen 04 | [PDF](./Fundamentos/B/Examen_04_B_Preguntas.pdf) · [LaTeX](./Tex/Fundamentos/B/Examen_04_B_Preguntas.tex) | [PDF](./Fundamentos/B/Examen_04_B_Pauta.pdf) · [LaTeX](./Tex/Fundamentos/B/Examen_04_B_Pauta.tex) |

## Material Tipo B — Estructuras y Punteros

### Variante B

| Material | Preguntas | Pauta |
| :--- | :--- | :--- |
| Guía 01 | [PDF](./Estructuras_y_Punteros/B/Guia_01_Tipo_B_Preguntas.pdf) · [LaTeX](./Tex/Estructuras_y_Punteros/B/Guia_01_Tipo_B_Preguntas.tex) | [PDF](./Estructuras_y_Punteros/B/Guia_01_Tipo_B_Pauta.pdf) · [LaTeX](./Tex/Estructuras_y_Punteros/B/Guia_01_Tipo_B_Pauta.tex) |

## Compilación LaTeX

Ejecuta `tectonic` desde la raíz del repositorio. Por ejemplo, para generar las preguntas de la Guía 02, Tipo A:

```bash
tectonic --outdir Examenes/Fundamentos Examenes/Tex/Fundamentos/A/Guia_02_Tipo_A_Preguntas.tex
```

La guía de pseudocódigo se compila en su propia carpeta:

```bash
tectonic --outdir Examenes/Pseudocodigo Examenes/Tex/Pseudocodigo/Pseudocodigo.tex
```
