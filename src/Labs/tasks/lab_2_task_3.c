#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, j, k, m, n, s = 0;
  scanf("%d", &n);

  int** A = NULL;
  if (n >= 3) {
    A = (int**)malloc((n + 1) * sizeof(int*));
    for (i = 0; i <= n; i++) {
      A[i] = (int*)calloc(n - 1, sizeof(int));
    }
  }

  for (i = 1; i <= n; i++) {
    j = 1;
    while (j < n) {
      m = n;
      while (m <= n) {
        for (k = 1; k <= (n - 2); k++) {
          s = s + A[i][k];
        }
        m = m + 2;
      }
      j = j * 2;
    }
  }

  if (n >= 3) {
    for (i = 0; i <= n; i++) {
      free(A[i]);
    }
    free(A);
  }
  return 0;
}