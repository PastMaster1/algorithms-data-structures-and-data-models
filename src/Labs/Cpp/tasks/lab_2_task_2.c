#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, j, k, m, n, s = 0;
  scanf("%d", &n);

  int*** A = NULL;
  if (n >= 5) {
    A = (int***)malloc((2 * n + 1) * sizeof(int**));
    for (int i = 0; i <= 2 * n; i++) {
      A[i] = (int**)malloc((n - 1) * sizeof(int*));
      for (int j = 0; j <= n - 2; j++) {
        A[i][j] = (int*)calloc(n - 2, sizeof(int));
      }
    }
  }

  for (i = 1; i <= (2 * n); i++) {
    j = 1;
    while (j < n - i) {
      for (k = 1; k < j; k++) {
        s = s + A[i][j][k];
      }
      j = j + 2;
    }
  }

  m = s;
  printf("%d", m);
  if (n >= 5) {
    for (i = 0; i <= 2 * n; i++) {
      for (j = 0; j <= n - 2; j++) {
        free(A[i][j]);
      }
      free(A[i]);
    }
    free(A);
  }
  return 0;
}