#include <stdio.h>

// # : 将变量字符串化
// ##: 连接两个变量, x##_##y -> x_y
#define swap(t, x, y) { \
  printf("\nswap " #x " and " #y "\n"); \
  t x##_##y = (x); \
  (x) = (y); \
  y = (x##_##y); \
}

#define swap2(x, y) { \
  printf("\nswap " #x " and " #y "\n"); \
  __typeof__((x)) x##y = (x); \
  (x) = (y); \
  y = (x##y); \
}

int main() {
  int a = 1, b = 2;
  printf("a %d, b %d", a, b);
  swap(int, a, b)
  printf("a %d, b %d", a, b);
  swap2(a, b)
  printf("a %d, b %d\n", a, b);
  return 0;
}
