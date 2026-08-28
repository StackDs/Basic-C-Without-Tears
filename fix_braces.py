import re

with open('/home/stack/Escritorio/Basic-C-Without-Tears/03_Control_de_Flujo/Teoria.md', 'r') as f:
    content = f.read()

# Regular expression to find ` {` or `{` at the end of statements like if, else, for, while, switch, do
# Wait, it's easier to just do simple string replacements for the specific blocks.

# 1. if (divisor != 0 && (dividendo / divisor > 1)) {
content = content.replace("if (divisor != 0 && (dividendo / divisor > 1)) {\n    printf(\"El resultado es mayor a 1\\n\");\n} else {\n    printf(\"El divisor era 0, pero el programa sigue vivo.\\n\");\n}", "if (divisor != 0 && (dividendo / divisor > 1)) \n{\n    printf(\"El resultado es mayor a 1\\n\");\n} \nelse \n{\n    printf(\"El divisor era 0, pero el programa sigue vivo.\\n\");\n}")

# 2. 
content = content.replace("if (edad >= 18) {\n    printf(\"Puedes pasar.\\n\");\n} else {\n    printf(\"Vete a casa, niño.\\n\");\n}", "if (edad >= 18) \n{\n    printf(\"Puedes pasar.\\n\");\n} \nelse \n{\n    printf(\"Vete a casa, niño.\\n\");\n}")

# 3.
content = content.replace("if (nota >= 90) {\n    printf(\"Excelente\\n\");\n} else if (nota >= 70) {\n    printf(\"Aprobaste, a duras penas\\n\");\n} else {\n    printf(\"Nos vemos en verano\\n\");\n}", "if (nota >= 90) \n{\n    printf(\"Excelente\\n\");\n} \nelse if (nota >= 70) \n{\n    printf(\"Aprobaste, a duras penas\\n\");\n} \nelse \n{\n    printf(\"Nos vemos en verano\\n\");\n}")

# 4.
content = content.replace("switch (opcion) {", "switch (opcion) \n{")
content = content.replace("switch(tecla) {", "switch(tecla) \n{")

# 5.
content = content.replace("while (energia > 0) {", "while (energia > 0) \n{")

# 6.
content = content.replace("do {\n    printf", "do \n{\n    printf")

# 7.
content = content.replace("for (int i = 0; i < 10; i++) {\n    printf(\"Iteracion", "for (int i = 0; i < 10; i++) \n{\n    printf(\"Iteracion")

# 8.
content = content.replace("for (int fila = 1; fila <= 3; fila++) {\n    for (int col = 1; col <= 3; col++) {\n        printf(\"[%d,%d] \", fila, col);\n    }\n    printf(\"\\n\"); // Salto de línea por cada fila\n}", "for (int fila = 1; fila <= 3; fila++) \n{\n    for (int col = 1; col <= 3; col++) \n    {\n        printf(\"[%d,%d] \", fila, col);\n    }\n    printf(\"\\n\"); // Salto de línea por cada fila\n}")

# 9.
content = content.replace("for (int i = 0; i < 100; i++) {\n    if (i == 3) {\n        printf(\"Me aburri", "for (int i = 0; i < 100; i++) \n{\n    if (i == 3) \n    {\n        printf(\"Me aburri")

# 10.
content = content.replace("for (int externo = 1; externo <= 3; externo++) {\n    for (int interno = 1; interno <= 3; interno++) {\n        if (interno == 2) {\n            break", "for (int externo = 1; externo <= 3; externo++) \n{\n    for (int interno = 1; interno <= 3; interno++) \n    {\n        if (interno == 2) \n        {\n            break")

# 11.
content = content.replace("for (int i = 0; i < 5; i++) {\n    if (i == 2) {\n        continue", "for (int i = 0; i < 5; i++) \n{\n    if (i == 2) \n    {\n        continue")

# 12.
content = content.replace("if (x = 5) { // ERROR LÓGICO CATASTRÓFICO\n    printf", "if (x = 5) // ERROR LÓGICO CATASTRÓFICO\n{\n    printf")

# 13.
nuevo_bloque = """Visualmente parece que ambas líneas dependen del `if`, pero el compilador ve el `saldo = saldo - 100;` como totalmente independiente y fuera del condicional. Por esto es que te dije más arriba que usar llaves siempre te salva la vida (y el trabajo).

La forma correcta, para que ambas líneas se ejecuten solo si el saldo es mayor a 0, es usar las llaves así:
```c
if (saldo > 0)
{
    printf("Transaccion aprobada.\\n");
    saldo = saldo - 100; 
}
```"""

content = content.replace("Visualmente parece que ambas líneas dependen del `if`, pero el compilador ve el `saldo = saldo - 100;` como totalmente independiente y fuera del condicional. Por esto es que te dije más arriba que usar llaves siempre te salva la vida (y el trabajo).", nuevo_bloque)

with open('/home/stack/Escritorio/Basic-C-Without-Tears/03_Control_de_Flujo/Teoria.md', 'w') as f:
    f.write(content)
