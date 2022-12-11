// Copyright [2022-11-09] <sxc19@mails.tsinghua.edu.cn, Xingchen Song>

#include <stdio.h>
#include <stdlib.h>
#include "utils/calc.h"

int main() {
  char s[MAXVAL];
  // 实际上getchar的返回值应该是 int (因为EOF是-1), 这里返回char不报错原因是char 是 signed (我的编译器认为是signed，换别人的可能就是unsigned)
  // 比如把下面一句显式声明为 unsigned char type; 那么就会陷入死循环，因为永远无法判断EOF (EOF是个负值)
  // https://blog.csdn.net/lonfee88/article/details/7542641
  // https://stackoverflow.com/questions/1437241/endoffile-in-c-eof
  char type = getop(s);
  double a, b, c;
  while (type != EOF) {
    switch (type) {
      case NUMBER:
        printf("push %f\n", atof(s));
        push(atof(s));
        break;
      case '+':
        a = pop(); b = pop(); c = a + b;
        printf("push %f + %f = %f\n", a, b, c);
        push(c);
        break;
      case '-':
        a = pop(); b = pop(); c = b - a;
        printf("push %f - %f = %f\n", b, a, c);
        push(c);
        break;
      case '*':
        a = pop(); b = pop(); c = a * b;
        printf("push %f * %f = %f\n", a, b, c);
        push(c);
        break;
      case '/':
        a = pop(); b = pop();
        if (a - 0.0 <= 1e-3) c = b / a;
        else printf("error: zero divisor\n");
        printf("push %f / %f = %f\n", b, a, c);
        push(c);
        break;
      case '\n':
        printf("final result: %.8g\n", pop());
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
    }
    type = getop(s);
  }
  printf("type: %d\n\n", type);
  return 0;
}
