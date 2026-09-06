
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Empleado {
  char *nombre;
  int num_proyectos;
  char **proyectos;
};

struct Empresa {
  char *nombre;
  int num_empleados;
  struct Empleado *empleados;
};

int main(void) {
  char buf_empresa[64];
  int num_emp;

  if (scanf("%63s %d", buf_empresa, &num_emp) == 2 && num_emp >= 1) {
    struct Empresa *empresa = (struct Empresa *)malloc(sizeof(struct Empresa));
    if (empresa == NULL)
      return 1;

    empresa->nombre = (char *)malloc(strlen(buf_empresa) + 1);
    strcpy(empresa->nombre, buf_empresa);
    empresa->num_empleados = num_emp;
    empresa->empleados =
        (struct Empleado *)malloc((size_t)num_emp * sizeof(struct Empleado));

    for (int i = 0; i < num_emp; i++) {
      char buf_nom[64];
      int num_proy;
      if (scanf("%63s %d", buf_nom, &num_proy) == 2) {
        empresa->empleados[i].nombre = (char *)malloc(strlen(buf_nom) + 1);
        strcpy(empresa->empleados[i].nombre, buf_nom);
        empresa->empleados[i].num_proyectos = num_proy;
        empresa->empleados[i].proyectos =
            (char **)malloc((size_t)num_proy * sizeof(char *));

        for (int j = 0; j < num_proy; j++) {
          char buf_proy[64];
          if (scanf("%63s", buf_proy) == 1) {
            empresa->empleados[i].proyectos[j] =
                (char *)malloc(strlen(buf_proy) + 1);
            strcpy(empresa->empleados[i].proyectos[j], buf_proy);
          }
        }
      }
    }

    // Imprimir resumen jerarquico
    printf("Empresa: %s\n", empresa->nombre);
    for (int i = 0; i < empresa->num_empleados; i++) {
      printf("- Empleado: %s (%d proyectos)\n", empresa->empleados[i].nombre,
             empresa->empleados[i].num_proyectos);
      for (int j = 0; j < empresa->empleados[i].num_proyectos; j++) {
        printf("  * %s\n", empresa->empleados[i].proyectos[j]);
      }
    }

    // Liberacion en cascada: nivel hojas -> nivel intermedio -> nivel raiz
    for (int i = 0; i < empresa->num_empleados; i++) {
      for (int j = 0; j < empresa->empleados[i].num_proyectos; j++) {
        free(empresa->empleados[i]
                 .proyectos[j]); // Liberar cada string de proyecto
      }
      free(empresa->empleados[i]
               .proyectos); // Liberar arreglo de punteros a proyectos
      free(empresa->empleados[i].nombre); // Liberar nombre del empleado
    }
    free(empresa->empleados); // Liberar arreglo de empleados
    free(empresa->nombre);    // Liberar nombre de empresa
    free(empresa);            // Liberar struct empresa principal

    printf("Memoria liberada exitosamente en todos los niveles.\n");
  }

  return 0;
}
