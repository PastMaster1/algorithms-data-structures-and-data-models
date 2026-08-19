#include <iostream>

int main() {
  int r = 4;
  int n, i, j, k, x, y, z, s = 0;
  std::cin >> n >> z;
  for (i = 1; i <= n; i++) {
    for (j = i; j <= 2 * n; j++) {
      for (k = 1; k <= i + j; k++) {
        if (z > i + j * k) {
          s = s + k % i * j;
        }
      }
    }
    for (x = 0; x <= 4 * n * n * n; x += 4) {
      if (x < r * n) {
        s = s + x * n;
      } else {
        for (y = 7 * n * n; y > n; y /= 2) {
          s = s * y;
        }
      }
    }
  }
  ctd::cout << s;
  return 0;
}