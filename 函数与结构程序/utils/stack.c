#include <stdio.h>
#include "calc.h"

// sp 和 val 被定义在stack_value.c 中, 因此需要用extern声明是外部变量
extern int sp;
extern double val[MAXVAL];

void push(double f) {
  if (sp < MAXVAL) val[sp++] = f;
  else printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
  if (sp > 0) return val[--sp];
  else {
    // printf("error: stack empty\n");
    return 0.0;
  }
}
