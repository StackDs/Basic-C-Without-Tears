
#include <stdio.h>

int main(void) {
  int m, n;

  // Leer la base M y el limite superior N
  if (scanf("%d %d", &m, &n) == 2 && n >= 1) {
    for (int i = 1; i <= n; i++) {
      printf("%d x %d = %d\n", m, i, m * i);
    }
  }

  return 0;
}
