// Copyright [2022-11-09] <sxc19@mails.tsinghua.edu.cn, Xingchen Song>

#include <stdio.h>
#include <stdlib.h>
#include "utils/calc.h"

int main() {
  char s[MAXVAL];
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
        printf("final result: %.8g\n\n", pop());
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
    }
    type = getop(s);
  }
  return 0;
}
