# Estadísticas de Calificaciones

El análisis de rendimiento académico suele apoyarse en tres medidas fundamentales de tendencia central: la media (promedio aritmético de los valores), la mediana (el valor situado en el centro tras ordenar los datos) y la moda (el valor que aparece con mayor frecuencia). Escribe un programa que lea un arreglo de exactamente 10 calificaciones y calcule su promedio, mediana y moda. En caso de empate en la moda, se debe reportar el menor de los valores empatados.

## Entrada
Una única línea que contiene 10 números decimales separados por espacios, correspondientes a las calificaciones.

Límites:
- 0.0 <= Calificación <= 100.0

## Salida
Tres líneas con el siguiente formato:
- `Promedio: PROMEDIO` (formateado a dos decimales)
- `Mediana: MEDIANA` (formateado a dos decimales)
- `Moda: MODA` (formateado a dos decimales)

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 80.0 90.0 70.0 80.0 100.0 80.0 90.0 60.0 85.0 75.0 | Promedio: 81.00<br>Mediana: 80.00<br>Moda: 80.00 |
| 10.0 20.0 30.0 40.0 50.0 60.0 70.0 80.0 90.0 100.0 | Promedio: 55.00<br>Mediana: 55.00<br>Moda: 10.00 |
